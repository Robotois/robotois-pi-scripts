#! /bin/sh
# /etc/init.d/test

### BEGIN INIT INFO
# Provides:          test
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Example initscript
# Description:       This file should be used to construct scripts to be
#                    placed in /etc/init.d.
### END INIT INFO

# Carry out specific functions when asked to by the system
case "$1" in
   start)
    echo "Starting test.js"
    # run application you want to start
    #node /home/pi/test.js > /home/pi/test.log
    /home/pi/downloads/node-v0.10.24-linux-arm-pi/bin/node /home/pi/test.js >> /home/pi/test.log
   ;;
   stop)
    echo "Stopping test.js"
    # kill application you want to stop
    killall -9 node
    # Not a great approach for running
    # multiple node instances
    ;;
  *)
    echo "Usage: /etc/init.d/test {start|stop}"
    exit 1
    ;;
esac

exit 0
