FROM	debian:11

RUN	apt-get update && \
	apt-get install mariadb-server -y && \
	apt-get install dumb-init && \ # 실행파일 위치 고정인가 ?
        chmod +x /usr/bin/dumb-init && \
        mkdir -p /run/mysqld /var/lib/mysql && \
        mariadb-install-db --datadir=/var/lib/mysql --auth-root-authentication-method=normal && \
        chown -R mysql:mysql /var/lib/mysql /run/mysqld

COPY	init_query.sql /install/init_query.sql
COPY	install.sh /install/install.sh

RUN	chmod +x /install/install.sh

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD		["sh", "-c", "/install/install.sh"]
