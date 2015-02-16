# Build all problem programs
#! /bin/bash

PROB="problems"

cd $PROB
echo "$PROB/"
for f in *; do
	if [ -d $f ]; then
		echo "  $f/"
		for file in $f/*.c; do
			echo "    $(basename $file)"
		done
	elif [ -e $f ]; then
		echo "  $f"
	fi
done
