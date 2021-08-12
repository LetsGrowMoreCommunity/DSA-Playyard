lst = [int(item) for item in input().split()]
# Function to find count of prime
def countPrimes(l : [int]) :
    n=len(l)
    max_val = l[0];
    # Find maximum value in the array
    for i in range(len(l)):
        if(l[i]>max_val):
            max_val = l[i]
        
    # USING SIEVE TO FIND ALL PRIME NUMBERS
    prime = [True for i in range(max_val+1)]
    prime[0]=False
    prime[1]=False
    
    k=int(sqrt(max_val))+1
    for p in range(2, k+1):
    # If prime[p] is not changed,
    # then it is a prime
        if(prime[p]):
            for i in range(p * p, max_val+1, p):
                prime[i]=False
    count=0
    # Find all primes in arr[]
    for i in range(0, n, 1):
        if(prime[l[i]]):
            count+=1
    
    return count

print(countPrimes(lst))

#input 1, 2, 3, 4, 5, 6, 7 
#output 4

#input 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
#output 5
