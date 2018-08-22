#!/bin/bash
START=$(date +%s)
# do something

#for i in {1..100}
#do

./client 100 100
#done

# your logic ends here
END=$(date +%s)
DIFF=$(( $END - $START ))
echo "It took $DIFF seconds"
