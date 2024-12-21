#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "The maximum process ID allowed on this system is: $pid_max"

