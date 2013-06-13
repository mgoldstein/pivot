#!/usr/bin/env bash

DB_NAME=pivot

DB_SUID=root
DB_SUPW=yVo5zKN6

DB_UID=pivot
DB_PW=j09k2kdla

DB_HOST=localhost

ADMIN_MAIL="support@pivot.tv"
ADMIN_NAME="pivot"
ADMIN_PASSWORD="P@ssw0rd"

SITE_NAME="Pivot.tv"
INSTALL_PROFILE="pivot"

FEATURES_LOCATION="drupal/sites/all/modules/features"

# Wipe out any existing installation settings and files
sudo rm -rf drupal/sites/default/files
chmod -R u+w drupal/sites/default
rm -f drupal/sites/default/settings.php

# Create the link for the participant core theme
pushd drupal/sites/all/themes
ln -sf ../../../../../participant-core/participant_core .
popd

# Drush needs to be run from under the Drupal root, and the parameter was giving
# me guff.
pushd ./drupal

# Install the site
INSTALL_URL="mysql://$DB_UID:$DB_PW@$DB_HOST/$DB_NAME"
../drush/drush site-install $INSTALL_PROFILE --yes --site-name="$SITE_NAME" \
  --db-url="$INSTALL_URL" --db-su="$DB_SUID" --db-su-pw="$DB_SUPW" \
  --account-mail="$ADMIN_MAIL" --account-name="$ADMIN_NAME" --account-pass="$ADMIN_PASSWORD"

# Disable the abomination that is the overlay module.
../drush/drush pm-disable overlay --yes

# Enable Chaos Tool Suite and Strongarm
../drush/drush pm-enable ctools strongarm page_manager --yes

# Enable views modules
../drush/drush pm-enable views views_ui --yes

# Enable panels modules
../drush/drush pm-enable panels_mini panels_node panels --yes

# Enable backend support modules
../drush/drush pm-enable entity libraries pathauto token --yes

# Enable admin support modules
../drush/drush pm-enable module_filter --yes

# Enable metatag modules
../drush/drush pm-enable metatag metatag_opengraph metatag_panels --yes

# Enable additional field type modules
../drush/drush pm-enable link node_reference references --yes

# Enable the media modules
../drush/drush pm-enable file_entity file_entity_inline media media_internet media_youtube --yes

# Enable WYSIWYG modules
../drush/drush pm-enable wysiwyg --yes

# Enable the content altering modules
../drush/drush pm-enable menu_attributes --yes

# Enable the webforms module
../drush/drush pm-enable webform --yes

# Enable node queues for manual curation of feed data
../drush/drush pm-enable nodequeue smartqueue --yes

# Enable node editing and publishing workflow
../drush/drush pm-enable publication_date scheduler content_lock --yes

# Enable search
../drush/drush pm-enable apachesolr --yes

# Enable Ad server support
../drush/drush pm-enable dfp --yes

# Enable Longtail / Bits on the Run support
../drush/drush pm-enable botr jw_player --yes

# Enable the features module
../drush/drush pm-enable features fe_nodequeue --yes

# Enable the site features
for FEATURE in $(ls -1 "../${FEATURES_LOCATION}" | awk -F- '{print $1}')
do
  ../drush/drush pm-enable $FEATURE --yes
done
for FEATURE in $(ls -1 "../${FEATURES_LOCATION}" | awk -F- '{print $1}')
do
  ../drush/drush features-revert $FEATURE --yes
done

# Enable the devel modules
../drush/drush pm-enable devel devel_generate --yes

# Give ownership of the files directory to the web server user
sudo chown -R www-data:www-data sites/default/files

# Restart Apache
sudo apachectl restart

# Flush cache
../drush/drush cc all

popd
