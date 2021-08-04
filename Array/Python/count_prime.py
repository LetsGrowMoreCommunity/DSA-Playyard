 #Count-primes(ARRAYS)
from math import sqrt
l=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
n=len(l)
max_val = l[0];
for i in range(len(l)):
    if(l[i]>max_val):
        max_val = l[i]
        # USING SIEVE TO FIND ALL PRIME NUMBERS
prime = [True for i in range(max_val+1)]
prime[0]=False
prime[1]=False
k=int(sqrt(max_val))+1
for p in range(2, k, 1):
    if(prime[p]==True):
        for i in range(p * 2, max_val+1, p):
            prime[i]=False
count=0
for i in range(0, n, 1):
    if(prime[l[i]]):
            count+=1
print(count)

#output 5
    
