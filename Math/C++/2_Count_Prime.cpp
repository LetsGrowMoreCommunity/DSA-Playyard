// Count Prime 
// In this question we have to count the number of prime numbers present in the range of 1 to n 
// Prime Numbers are numbers which are divisible by one and itself
// Time Complexity : O(n*sqrt(n))
// Space Complexity : O(1)

// Code:
#include <bits/stdc++.h>
using namespace std;
// function to check if the given number is prime or not
bool prime_check(int a){
    if(a==1) return false;  // 1 is not a prime number 
    for(int i=2;i<=sqrt(a);i++){ 
        if(a%i==0) return false;  //if the number is divisible by a number which comes before it's square root,then it won't be a prime number
    }return true;
}
int main(){
    int n,count=0;
    cin>>n;
    for(int i=1;i<=n;i++){  //to find the number of prime numbers present in the range of 1 to n,we will run a loop
        if(prime_check(i)) count++; //if the number is prime, then add 1 to count 
    }
    cout<<"The number of prime numbers present between 1 to "<<n<<" : "<<count<<endl;

    return 0;
}

// Input 1:
// 10
// Output 1:
// The number of prime numbers present between 1 to 10 : 4
// Input 2:
// 30
// Output 2:
// The number of prime numbers present between 1 to 30 : 10