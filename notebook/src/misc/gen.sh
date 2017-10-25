#! /bin/sh
while read p;
do
    mkdir $p;
    cp template.cpp $p/code.cpp;
    sed -i "s/PB_NAME/$p/g" $p/code.cpp;
    cp check.py $p;
done < ps.txt
