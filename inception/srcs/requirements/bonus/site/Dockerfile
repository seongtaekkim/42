FROM	debian:11 as builder

WORKDIR	/app

COPY	tools/app/package.json /app
RUN		apt-get update && \
		apt-get install curl -y && curl -sL https://deb.nodesource.com/setup_16.x | bash - && \
		apt-get install nodejs -y
COPY	tools/app/ /app
RUN	npm install
RUN	npm install -g react-scripts
RUN	npm run build

FROM	debian:11 as server

RUN	apt-get update && \
        apt-get install nginx -y && \
	apt-get install dumb-init -y && \
        chmod +x /usr/bin/dumb-init && \
        mkdir -p /var/run/nginx /etc/nginx/conf.d && \ 
	rm -rf /etc/nginx/conf.d/default.conf

COPY	--from=builder /app/build /var/www/html
COPY	conf/nginx.conf /install/nginx.conf
COPY	tools/script.sh /install/script.sh

RUN         chmod +x /install/script.sh


ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh"]
