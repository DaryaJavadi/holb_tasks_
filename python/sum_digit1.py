#!/usr/bin/python3
a = int(input())
a = str(a)
sum = 0
for i in range(len(a)):
    sum = int(a[i]) + sum
print(sum)
