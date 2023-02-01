# !/bin/sh

sleep 10
# run
/usr/bin/cadvisor -logtostderr -port=${CADVISOR_PORT} -url_base_prefix=${CADVISOR_URL_BASE_PREFIX}
