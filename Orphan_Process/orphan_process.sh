#!/bin/bash

echo "Parent PID is: $$"

# creating a fork process

(
	echo "Child PID is: $$"
	echo "Child sleeping for 10 secs"
	sleep 10
	echo "Child woke up"
)&
echo "Parent exiting"
exit 0


