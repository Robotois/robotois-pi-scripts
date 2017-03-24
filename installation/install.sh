#!/bin/sh

echo "--- Installing BCM library for C/C++\n"

tar zxvf bcm2835-1.52.tar.gz && cd bcm2835-1.52 && ./configure && make && sudo make install && cd ..

echo "\n--- Installing \"node\" and \"npm\"\n"

sudo tar -C /usr/local --strip-components 1 -xvJf node-v6.10.1-linux-armv7l.tar.xz

echo "\n--- Updating the package sources\n"

sudo apt-get update

echo "\n--- Latest git version\n"

sudo apt-get install git

echo "\n--- Now the packages required for the Acces Point application\n"

sudo apt-get install isc-dhcp-server hostapd iw -y
