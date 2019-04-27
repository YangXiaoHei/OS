#! /bin/bash

if [ $# -ne 1 ]
then
    echo "usage : %s <loop>"
    exit 1
fi

file=./test_stack_memory_address_range.c
exe_file=get_stack_memory
result=stack_memory_address_result
loop=$1

gcc -std=gnu99 $file -o $exe_file

[ -e $result ] && rm $result 2>/dev/null

for ((i=0; i<$loop; i++))
do
    ./$exe_file >> $result
done

if [ ! -e $result ]
then
    echo "result not output, something wrong occur!" 
    exit 1
fi

sort $result > tmp; cp tmp $result; rm tmp

lowest=`cat $result | head -n1`
highest=`cat $result | tail -n1`
l=`echo $lowest | cut -d' ' -f1`
h=`echo $highest | cut -d' ' -f1`
((range = $h - $l))

echo "***************************************"
echo -e "the stack memory address range is \n[$lowest] ~ [$highest]\ntotal [$range]"
echo "***************************************"






