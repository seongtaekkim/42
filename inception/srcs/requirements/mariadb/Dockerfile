FROM	debian:11

RUN	apt-get update && \
	apt-get install mariadb-server -y && \
	apt-get install dumb-init && \ 
        chmod +x /usr/bin/dumb-init && \
        mkdir -p /run/mysqld /var/lib/mysql && \
        mariadb-install-db --datadir=/var/lib/mysql --auth-root-authentication-method=normal && \
        chown -R mysql:mysql /var/lib/mysql /run/mysqld

COPY	conf/init_query.sql /install/init_query.sql
COPY	tools/install.sh /install/install.sh

RUN	chmod +x /install/install.sh

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD		["sh", "-c", "/install/install.sh"]
