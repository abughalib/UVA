# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 23:44:04 2020

@author: Abugh
"""
import math
#Efficient way of finding Prime Factorization

#x = int(input())
x = 99
setOfFactors = {1, x}

while(x % 2 == 0):
    setOfFactors.add(2)
    x = x//2

for i in range(3, int(math.sqrt(x))+1):
    if(x % i == 0):
        setOfFactors.add(i)

print(setOfFactors)
