FROM		alpine:3.17.1

RUN			apk update && \
			apk add mariadb mariadb-client && \
			wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
        	chmod +x /usr/bin/dumb-init && \
        	mkdir -p /run/mysqld /var/lib/mysql && \
        	mariadb-install-db --datadir=/var/lib/mysql --auth-root-authentication-method=normal && \
        	chown -R mysql:mysql /var/lib/mysql /run/mysqld

#COPY		init_query.sql /tmp/init_query.sql
COPY		install.sh /tmp/install.sh

RUN			chmod +x /tmp/install.sh

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD			["sh". "-c", "/tmp/install.sh"]