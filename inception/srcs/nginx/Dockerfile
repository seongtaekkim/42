FROM	debian:11

RUN	apt-get update && \
        apt-get install nginx openssl -y && \
	apt-get install dumb-init -y && \
        chmod +x /usr/bin/dumb-init && \
        mkdir -p /etc/nginx/tls /var/run/nginx && \
            openssl req -new -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/tls/seongtki.42.fr.crt -keyout /etc/nginx/tls/seongtki.42.fr.key -subj "/C=KR/ST=Seoul/L=Songpa-gu/O=42/OU=42Seoul/CN=seongtki.42.fr" && \
            ln -sf /dev/stdout /var/log/nginx/access.log && \
            ln -sf /dev/stderr /var/log/nginx/error.log && \
            rm -rf /etc/nginx/conf.d/default.conf

COPY        nginx.conf /install/nginx.conf
COPY        setting.sh /install/setting.sh

RUN         chmod +x /install/setting.sh

# expose though using bridge
EXPOSE      443

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/setting.sh" ]
