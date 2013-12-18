#!/bin/bash
EXEC=$1
PASS=1
shift

for each; do
    printf "check %s ... " `basename $each`
    cat $each | ./mkstd.sh > $each.o
    if ! cat $each | $EXEC | cmp $each.o -; then
        echo fail.
        PASS=0
    else
        echo pass.
    fi
    rm $each.o
done

exit $((1 - PASS))

