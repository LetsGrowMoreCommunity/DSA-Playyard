#include <bits/stdc++.h>
using namespace std;

//All power of two numbers have only one bit set.
//If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit become unset.
//Now if a number n is a power of 2 then bitwise & of n and n-1 will be zero.

bool ispowerof2(int num){
   return (num & (num-1)); 
}
int main() {
    int num;
    cin>>num;
	if(ispowerof2(num)==1) //not 0 so not a power of 2
	    cout<<"No";
	else                  //0 so power of 2
	    cout<<"Yes";
	return 0;
}

