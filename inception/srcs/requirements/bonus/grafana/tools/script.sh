# !/bin/sh


# run
#/monitor/grafana/bin/grafana-server/

echo "provisioning = conf/provisioning" >> /usr/share/grafana/conf/defaults.ini
#enable_gzip = true
#http_port = 3000
#domain=localhost
#protocol=http
echo "domain = seongtki.42.fr" >> /usr/share/grafana/conf/defaults.ini
echo "root_url = %(protocol)s://%(domain)s:%(http_port)s/grafana" >> /usr/share/grafana/conf/defaults.ini
echo "serve_from_sub_path = true" >> /usr/share/grafana/conf/defaults.ini
/usr/sbin/grafana-server -homepath /usr/share/grafana/
