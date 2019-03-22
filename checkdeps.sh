#!/bin/sh
## GNU Make
printf "? GNU Make ... "
if [ -x "$(command -v make)" ]
then
	echo "yes."
else
	echo "failed."
	exit 1
fi

## JACK2
printf "? JACK2 >= 1.9 ... "
pkg-config jack --atleast-version="1.9"
if [ $? == 0 ]
then
	echo "yes."
else
	echo "failed."
	exit 1
fi
