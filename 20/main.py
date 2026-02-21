#!/usr/bin/env python3

num = 1
for i in range(1, 101):
    num *= i

digits = map(int, str(num))

print(sum(digits))
