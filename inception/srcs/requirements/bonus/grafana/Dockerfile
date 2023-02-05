FROM	debian:11

RUN	apt-get update && \
	apt-get install -y apt-transport-https && \
  	apt-get install -y software-properties-common wget gpg && \
	mkdir -p /etc/apt/keyrings/ && \
	wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor > /etc/apt/keyrings/grafana.gpg && \
	echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | tee /etc/apt/sources.list.d/grafana.list && \
  	apt-get update && \
  	apt-get install grafana -y && \
  	apt-get install grafana-enterprise -y  && \
  	mkdir -p /monitor/grafana && \
	mv /usr/share/grafana/* /monitor/grafana && \
	apt-get install dumb-init -y && \
    chmod +x /usr/bin/dumb-init 

COPY	conf/grafana.ini /monitor/grafana/conf/custom.ini
COPY	tools/script.sh /install/script.sh
COPY    conf/datasource.yml /monitor/grafana/conf/provisioning/datasources/datasource.yml
COPY    conf/dashboard.yml /monitor/grafana/conf/provisioning/dashboards/dashboard.yml
COPY	conf/monitoring.json /monitor/grafana/dashboards/monitoring.json

WORKDIR	/monitor/grafana

RUN         chmod +x /install/script.sh

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/install/script.sh"]
