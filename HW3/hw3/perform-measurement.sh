#!/bin/bash

# Check for args:
if [ $# -ne 1 ]; then
    echo "Error: perform-measurement requires exactly 1 arg"  1>&2
    exit 1
fi

# Make temp file for errors
#temp=$(mktemp /tmp/errors.XXXXXXX)

touch temp
touch file

echo trying to find "$1"

# Try to download file
wget -O file "$1" 2>temp

# Check for errors 
nErrors=$(wc -l < temp)
if grep -i 'error' temp; then
   echo "Could not download the requested file" 1>&2; exit 1
fi


#rm "$temp"
echo 0
   
exit 0
