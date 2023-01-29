FROM	debian:11

RUN	apt-get update && \
	apt-get install systemctl -y && \
	apt-get install curl mariadb-client php7.4-fpm php7.4-mysql php7.4-curl php7.4-json -y && \
	mkdir -p /run/php && \
        #apt-get install curl mariadb-client redis php7 php7-phar php7-json php7-curl php7-fpm php7-mysqli php7-iconv -y && \
	apt-get install dumb-init -y && \
	chmod +x /usr/bin/dumb-init && \
        mkdir -p /var/www/wordpress && \
        apt-get install wget -y  && \
	wget -O /tmp/wordpress.tar.gz "http://wordpress.org/latest.tar.gz" && \ 
	apt-get install tar -y && \
	tar -xvzf /tmp/wordpress.tar.gz -C /var/www/wordpress --strip 1
	#curl -s -L https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp && \
        #chmod +x /usr/bin/wp && \
        #wp core download --version=5.8.1 --path=/var/www/wordpress

COPY        wp-config.php /install/wp-config.php
COPY        script.sh /install/script.sh

RUN         chmod +x /install/script.sh

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh" ]
