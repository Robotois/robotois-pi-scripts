#!/bin/sh
#/etc/init.d/robotois-service

### BEGIN INIT INFO
# Provides: index
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Initialize robotois webserverpi
# Description:       This file is the sh script that starts webserverpo for robotois
### END INIT INFO

export PATH=$PATH:/usr/bin
export NODE_PATH=$NODE_PATH:/usr/bin/node

case "$1" in
start) exec forever start --sourceDir=/home/pi/Robotois/webserverpi --uid="webserverpi" -p /home/pi/Robotois/webserverpi index.js
;; stop)
exec forever stop --sourceDir=/home/pi/Robotois/webserverpi index.js
;;
*)
echo "Usage: /etc/init.d/robotois-service {start|stop}"
exit 1
;;
esac
exit 0
