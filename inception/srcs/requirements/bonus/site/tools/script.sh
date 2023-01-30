# !/bin/sh

cp /install/nginx.conf /etc/nginx/conf.d/default.conf
sleep 5; # wait  for run nginx

nginx -g 'daemon off;'
