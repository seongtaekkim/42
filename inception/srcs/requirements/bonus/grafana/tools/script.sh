# !/bin/sh

sed -i "s/PROMETHEUS_HOST/$PROMETHEUS_HOST/g" /monitor/grafana/conf/provisioning/datasources/datasource.yml
sed -i "s/PROMETHEUS_PORT/$PROMETHEUS_PORT/g" /monitor/grafana/conf/provisioning/datasources/datasource.yml


/usr/sbin/grafana-server -homepath /monitor/grafana/
