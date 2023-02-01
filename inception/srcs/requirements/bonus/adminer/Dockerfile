FROM	debian:11

RUN	apt-get update && \
	apt-get install php php-fpm -y && \
	apt-get install curl mariadb-client php7.4-fpm php7.4-mysql php7.4-curl php7.4-json -y && \
	mkdir -p /run/php && \
	apt-get install dumb-init -y && \
	chmod +x /usr/bin/dumb-init 

COPY        tools/script.sh /install/script.sh

RUN         chmod +x /install/script.sh

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh" ]
