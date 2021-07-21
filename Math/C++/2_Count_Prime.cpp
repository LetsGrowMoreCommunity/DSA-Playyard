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
// function to count the number of prime numbers present in the range of n
int count_prime_numbers(int n){    
    if (n<=1) return 0; //0 and 1 are not prime numbers
    int count=0;
    for(int i=1;i<=n;i++){  //to find the number of prime numbers present in the range of 1 to n,we will run a loop
        if(prime_check(i)) {
            count++; //if the number is prime, then add 1 to count             
        }
    }return count;
}
void printnumbers(int n){    
    for(int i=1;i<=n;i++){  //to find the number of prime numbers present in the range of 1 to n,we will run a loop
    if(prime_check(i)) {
        cout<<i<<" , "; //printing numbers which are prime 
        }
}}

int main(){
    int n;
    cin>>n;  
    int s =count_prime_numbers(n); 
    if (s==0) cout<<s;
    else {cout<<"There are "<<s<<" prime numbers less than "<<n<<" ,they are ";
    printnumbers(n);}
    return 0;
}

// Input 1:
// 10
// Output 1:
// There are 4 prime numbers less than 10 ,they are 2 , 3 , 5 , 7 ,
// Input 2:
// 30
// Output 2:
// There are 10 prime numbers less than 30 ,they are 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 