#!/bin/bash

./app1.bin &
PID=$!
echo "Started background process with PID: $PID"
sleep 3
kill $PID && echo "Killed process $PID"
