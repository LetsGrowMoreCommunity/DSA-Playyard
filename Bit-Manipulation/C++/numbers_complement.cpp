#include <bits/stdc++.h>
using namespace std;

// function findComplement finds the complement of the no.
// the parameter for the function is num that we take from the user from main function.
//n is the no. of digits in n.
// each time the for loops runs xor is taken between the number i.e  num and 1 left shifted i times.
//finally function returns num.
int findComplement(int num) {
    int n=log2(num);
        for (int i = 0 ; i <= n;i++){
            num = num ^ (1<<i);
        }
        return num;
    }
int main() {
    int num;
    cin>>num;
	cout<<findComplement(num);
}

