# !/bin/sh

sed -i "s/CADVISOR_HOST/$CADVISOR_HOST/g" /install/prometheus.yml
sed -i "s/CADVISOR_PORT/$CADVISOR_PORT/g" /install/prometheus.yml
sed -i "s/PROMETHEUS_PORT/$PROMETHEUS_PORT/g" /install/prometheus.yml

cp /install/prometheus.yml /etc/prometheus/prometheus.yml

prometheus --config.file=/etc/prometheus/prometheus.yml --storage.tsdb.path=/monitor/prometheus --storage.tsdb.retention=200h --web.listen-address=:${PROMETHEUS_PORT}
