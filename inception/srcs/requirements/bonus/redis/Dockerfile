FROM	debian:11

RUN	apt-get update && \
        apt-get install redis -y && \
	apt-get install dumb-init -y && \
        chmod +x /usr/bin/dumb-init 

COPY	tools/script.sh /install/script.sh

RUN	chmod +x /install/script.sh

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh" ]
