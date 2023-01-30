# !/bin/sh

cp /install/nginx.conf /etc/nginx/conf.d/default.conf # copy my setting
sleep 5; # wait wordpress run

# after dumb init run
nginx -g 'daemon off;'
