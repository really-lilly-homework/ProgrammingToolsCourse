#!/bin/bash

# Check for correct number of args:
if [ $# -ne 2 ]; then
  echo "Error: exactly 2 args required." 1>&2; exit 1
fi

if [ -e "$1" ]; then
  echo Overwriting file "$1"
fi

# Check for file validity:
if [ ! -f $2 ]; then
  echo "Error: invalid file." 1>&2; exit 1
fi

touch "$1"

while read -r line;
do
    echo Performing byte-size measurement on "$line"
    bytecount=$(. ./perform-measurement.sh "$line" 2>/dev/null)
    if [ $? -eq 1 ]; then
	echo ...failure
    else
	echo "$bytecount" >> "$1"
	echo ...success
    fi
    
done < "$2"

exit 0
