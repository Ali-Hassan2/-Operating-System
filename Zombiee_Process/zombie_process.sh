#!/bin/bash

echo "Parent Process PID is: $$"

# creating a fork process
(
	echo "Child Process PID: $$"
	exit 0

)&

echo "Parent is not reading the child's exit code until that the child will be a zombie process"

sleep 5


