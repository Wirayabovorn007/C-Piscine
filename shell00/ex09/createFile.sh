#!/usr/bin/bash

for i in {0..41}
do
if [ $i -eq 41 ]; then
echo -n "42" >> testFile
else
echo -n "0" >> testFile
fi
done
