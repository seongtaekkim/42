FROM	debian:11


RUN	apt-get update && \
	apt-get install wget -y && \
        apt-get install prometheus -y && \
	apt-get install dumb-init -y && \
        chmod +x /usr/bin/dumb-init

COPY        conf/prometheus.yml /install/prometheus.yml
COPY        tools/script.sh /install/script.sh

RUN         chmod +x /install/script.sh && \
            chmod +x /install/prometheus.yml

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh"]
