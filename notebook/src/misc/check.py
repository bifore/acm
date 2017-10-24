import os

if not os.system('g++ -g -O2 -Wall -Wextra -std=gnu++14 -static "$@" -lm code.cpp -o elf'):
    for i in os.popen('ls *.in').read().strip().split('\n'):
        o = os.popen('export TIMEFORMAT="{0} %E sec"; time cat {0} | ./elf check'.format(i)).read()
        print(i, 'PASS' if open(i[:-2] + 'out').read() == o else 'FAIL')
