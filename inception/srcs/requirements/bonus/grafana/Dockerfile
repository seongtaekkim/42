FROM	debian:11

RUN	apt-get update && \
	apt-get install -y apt-transport-https && \
  	apt-get install -y software-properties-common wget gpg && \
	mkdir -p /etc/apt/keyrings/ && \
	wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor > /etc/apt/keyrings/grafana.gpg && \
	echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | tee /etc/apt/sources.list.d/grafana.list && \
  	#wget -q -O /usr/share/keyrings/grafana.key https://apt.grafana.com/gpg.key && \
  	#echo "deb [signed-by=/usr/share/keyrings/grafana.key] https://apt.grafana.com stable main" | tee -a /etc/apt/sources.list.d/grafana.list && \
  	apt-get update && \
  	apt-get install grafana -y && \
  	apt-get install grafana-enterprise -y  && \
	apt-get install dumb-init -y && \
        chmod +x /usr/bin/dumb-init 

#COPY	conf/grafana.ini /usr/share/grafana/conf/defaults.ini
COPY	tools/script.sh /install/script.sh

RUN         chmod +x /install/script.sh

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh"]
