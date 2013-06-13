pivot-tv
========

Pivot.tv Website

Installation
------------
The repo is setup to support both fresh installations and installations based on
an existing database.

*Fresh installation (Debian base Linux only)*

- Run *./build.sh*

*Existing database install*

- Adjust the settings.php file in sites/default to point to the database
- Restart apache, memcached
- Clear all caches
