# !/bin/sh

echo "listen = 9000" >> /etc/php/7.4/fpm/pool.d/www.conf
echo "env[MARIADB_HOST] = \$MARIADB_HOST" >> /etc/php/7.4/fpm/pool.d/www.conf
echo "env[MARIADB_USER] = \$MARIADB_USER" >> /etc/php/7.4/fpm/pool.d/www.conf
echo "env[MARIADB_PWD] = \$MARIADB_PWD" >> /etc/php/7.4/fpm/pool.d/www.conf
echo "env[MARIADB_DB] = \$MARIADB_DB" >> /etc/php/7.4/fpm/pool.d/www.conf

if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
  cp /install/wp-config.php /var/www/wordpress/wp-config.php # copy my setting file
  sleep 5; # wait maridb to be runed
  if ! mysqladmin -h $MARIADB_HOST -u $MARIADB_USER --password=$MARIADB_PWD --wait=60 ping > /dev/null; then
    printf "mariadb can't login\n"
    exit 1
  fi
  wp core install --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PWD" --admin_email="$WP_ADMIN_EMAIL" --skip-email --path=/var/www/wordpress
  #wp plugin install redis-cache --activate --path=/var/www/wordpress
  #wp plugin update --all --path=/var/www/wordpress
  wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PWD --path=/var/www/wordpress
  #wp redis enable --path=/var/www/wordpress
fi

# after run dumb init
php-fpm7.4 --nodaemonize 
