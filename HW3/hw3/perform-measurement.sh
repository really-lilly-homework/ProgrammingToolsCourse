#!/bin/bash

# Check for args:
if [ $# -ne 1 ]; then
    echo "Error: perform-measurement requires exactly 1 arg"  1>&2
    exit 1
fi

# Make temp file for errors
output=$(mktemp /tmp/errors.XXXXXXX)
download=$(mktemp /tmp/download.XXXXXXX)

# Try to download file
wget -o "$output" "$1" -O "$download" >/dev/null

# Check for errors 
if (grep -i 'error' "$output"); then
   echo 0; exit 1
fi

bytes=$(wc -c < "$download")
echo "$bytes"

rm "$output" "$download"
   
exit 0
