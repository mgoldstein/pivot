#!/bin/bash

PREFIX=/var/www/html2
src_path=/var/nfs_export/pivot/app/current_pivot
dest_path=${PREFIX}/current_pivot
release=$(readlink ${src_path})
release_path=${PREFIX}/${release}

application_stop() {
  service httpd stop
}

download_bundle() {
  :
}

before_install() {
  [[ -d ${release_path} ]] && exit
}

install_dependencies() {
  :
}

install_application() {

  [[ ! -d ${release_path} ]] && mkdir -p ${release_path}
  rsync -az ${src_path}/drupal/ ${release_path}

}

after_install() {

  cp ${src_path}/../settings.php ${release_path}/sites/default
  ln -s /var/nfs_export/pivot/statics/files ${release_path}/sites/default/files

  [[ -L ${dest_path} ]] && rm ${dest_path}
  ln -s $(readlink ${src_path}) ${dest_path}
  chown -Rh apache:apache ${release_path}
  chown -h apache:apache ${dest_path}

}

application_start() {
  service httpd start
}

validate_service() {
  :
}


download_bundle
before_install
application_stop
install_application
after_install
application_start
validate_service
