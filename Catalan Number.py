#Catalan Number using recursion
def catalyNumber(n):
    number = 0
    if n <= 1:
        return 1
    for i in range(0, n):
       number += catalyNumber(i)* catalyNumber(n-i-1)

    return number

print(catalyNumber(4))
#Catalan Number using DP
