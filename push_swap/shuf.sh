#!/bin/bash
if [[ $# -ne 1 ]]
then
	echo "Usage:\n$0 [number of elements]"
	exit 1
fi
LIST=$(perl -e "use List::Util 'shuffle'; my @out = (shuffle 0..$1)[0..$1]; print \"@out\"")
echo ${LIST[@]}
set -v