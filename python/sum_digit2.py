#1/usr/bin/python3
a = int(input())
c = 0
sum = 0
while a > 0:
    c = a % 10
    a = a // 10
    sum = sum + c
print(sum)
