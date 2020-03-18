# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 13:44:04 2019

@author: Abugh
"""
#Binomial cofficient using Recusion

def Bc(n, k):
    if(k == 0 or k == n):
        return 1
    return Bc(n-1, k-1)+ Bc(n-1, k)
    
print(Bc(5, 2))
#Binominal cofficient using Dynamic Programming

def BioCo(n, k):
    c = [[0 for _ in range(k+1)] for __ in range(n+1)]
    
    for i in range(0, n+1):
        for j in range(0, min(i, k)+1):
            if(j == 0 or j == i):
                c[i][j] = 1
            else:
                c[i][j] = c[i-1][j-1] + c[i-1][j]

    return c[n][k]

print(BioCo(5, 2))
#Bionomial cofficient using DP + Pascal's trangle

def bionomialCo(n, k):
    C = [0 for i in range(k+1)]
    C[0] = 1
    
    for i in range(1, n+1):
        j = min(i, k)
        while(j > 0):
            C[j] = C[j] + C[j-1]
            j -=1
    return C[k]

print(bionomialCo(5, 2))
