# !/bin/sh


# run
#/monitor/grafana/bin/grafana-server/

#echo "provisioning = conf/provisioning" >> /usr/share/grafana/conf/defaults.ini
#enable_gzip = true
#http_port = 3000
#domain=localhost
#protocol=http

#sed -i "s/root_url = %(protocol)s://%(domain)s:%(http_port)s//root_url = %(protocol)s://%(domain)s:%(http_port)s/grafana//g" /usr/share/grafana/conf/defaults.ini  
#echo "domain = seongtki.42.fr" >> /usr/share/grafana/conf/defaults.ini
#echo "root_url = %(protocol)s://%(domain)s:%(http_port)s/grafana/" >> /usr/share/grafana/conf/defaults.ini
#echo "serve_from_sub_path = true" >> /usr/share/grafana/conf/defaults.ini
#sed -i "s/serve_from_sub_path = false/serve_from_sub_path = true/g" /usr/share/grafana/conf/defaults.ini

sed -i "s/PROMETHEUS_HOST/$PROMETHEUS_HOST/g" /monitor/grafana/conf/provisioning/datasources/datasource.yml
sed -i "s/PROMETHEUS_PORT/$PROMETHEUS_PORT/g" /monitor/grafana/conf/provisioning/datasources/datasource.yml


/usr/sbin/grafana-server -homepath /monitor/grafana/
