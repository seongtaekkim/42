# !/bin/sh

# mark : for only one setting
cat .setup 2> /dev/null

if [ $? -ne 0 ]; then
  # execute background to setting
  /usr/bin/mysqld_safe --datadir=/var/lib/mysql &
  sed -i "s/.*bind-address\s*=.*/bind-address=0.0.0.0\nport=3306/g" /etc/mysql/mariadb.conf.d/50-server.cnf
  # check : mysqld is alive
  if ! mysqladmin --wait=10 ping; then
    printf "MariaDB Daemon Unreachable\n"
    exit 1
  fi

  eval "echo \"$(cat /install/init_query.sql)\"" | mariadb
  pkill mariadb
  touch .setup
fi

# execute foreground
/usr/bin/mysqld_safe --datadir=/var/lib/mysql
