FROM	debian:11

RUN	apt-get update && \
        apt-get install vsftpd -y && \
	apt-get install openssl -y && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.pem -out /etc/ssl/private/vsftpd.pem -subj "/C=GB/ST=seoul/L=seoul/O=Global Security/OU=IT Department/CN=seongtki.42.kr" && \
	apt-get install dumb-init -y && \
        chmod +x /usr/bin/dumb-init && \
	rm -rf /etc/vsftpd.conf

COPY	conf/vsftpd.conf /install/vsftpd.conf
COPY	tools/script.sh /install/script.sh

RUN         chmod +x /install/script.sh

EXPOSE 21

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh"]
