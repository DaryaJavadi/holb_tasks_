#!/usr/bin/python3
a = int(input())
b = int(input())
c = int(input())
if a < b and a < c:
    print("The smallest number is:", a)
elif b < a and b < c:
    print("The smallest number is:", b)
else:
    print("The smallest number is:", c)
