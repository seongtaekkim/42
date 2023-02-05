FROM	debian:11

RUN	apt-get update && \
	apt-get install systemctl -y && \
	apt-get install php php-fpm -y && \
	apt-get install curl mariadb-client php7.4-fpm php7.4-mysql php7.4-curl php7.4-json -y && \
	mkdir -p /run/php && \
	apt-get install dumb-init -y && \
	chmod +x /usr/bin/dumb-init && \
    mkdir -p /var/www/wordpress && \
    apt-get install wget -y  && \
	apt-get install tar -y && \
	curl -s -L https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp && \	
	chmod +x /usr/bin/wp && \
	wp core download --path=/var/www/wordpress --allow-root

COPY        conf/wp-config.php /install/wp-config.php
COPY        tools/script.sh /install/script.sh

RUN         chmod +x /install/script.sh

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh" ]
