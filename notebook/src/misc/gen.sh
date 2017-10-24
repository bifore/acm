#! /bin/sh
while read p;
do
    mkdir $p;
    cp template.cpp $p/code.cpp;
    sed -i "1istring PB_NAME = \"$p\";\n" $p/code.cpp;
    cp check.py $p;
done < ps.txt
