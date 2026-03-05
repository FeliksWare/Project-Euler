#!/usr/bin/env python3

index = 1
a = 0;
b = 1;

while len(str(b)) < 1000:
    index += 1
    c = a + b
    a = b
    b = c

print(index)
