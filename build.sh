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

# Wipe out any existing installation settings and files
sudo rm -rf drupal/sites/default/files
chmod -R u+w drupal/sites/default
rm -f drupal/sites/default/settings.php

# Drush needs to be run from under the Drupal root, and the parameter was giving
# me guff.
pushd ./drupal

# Install the site (use the drush that is part of the repo as not all servers have an up to date drush)
INSTALL_URL="mysql://$DB_UID:$DB_PW@$DB_HOST/$DB_NAME"
../drush/drush site-install $INSTALL_PROFILE --yes --site-name="$SITE_NAME" \
  --db-url="$INSTALL_URL" --db-su="$DB_SUID" --db-su-pw="$DB_SUPW" \
  --account-mail="$ADMIN_MAIL" --account-name="$ADMIN_NAME" --account-pass="$ADMIN_PASSWORD"

# Restart Apache
sudo apachectl restart

# Flush cache
../drush/drush cc all

# Give ownership of the files directory to the web server user
sudo chown -R www-data:www-data sites/default/files

popd

