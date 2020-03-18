# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 23:44:04 2020

@author: Abugh
"""
#Finding GCD and LCM

def gcd(x: int, y: int):
    if(x == 0):
        return y;
    else:
        return gcd(y%x, x)

def lcm(x: int, y: int):
    return x*y/(gcd(x, y))


print(int(lcm(10, 3)))
