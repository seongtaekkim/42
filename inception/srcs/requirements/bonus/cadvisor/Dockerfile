FROM	debian:11

RUN	apt-get update && \
	#apt-get install curl wget -y && \
        #curl -L	https://github.com/google/cadvisor/releases/download/v0.47.5/cadvisor --output /usr/bin/cadvisor --silent && \
        apt-get install cadvisor -y && \
	chmod +x /usr/bin/cadvisor && \
	apt-get install dumb-init -y && \
        chmod +x /usr/bin/dumb-init 

COPY	tools/script.sh /install/script.sh

RUN         chmod +x /install/script.sh

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh"]
