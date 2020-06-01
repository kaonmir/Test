#!/bin/bash

clear
cd /home/ubuntu/cau15841-pintos2-qemu/threads
make
cd build
../../utils/pintos -ma=$1 alloctest

