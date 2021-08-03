
//Time complexity-0(n)
//Space Complexity-0(1)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;   

    int findNthdigit(int n) {
        if(n < 10) return n;//in this casee the nth digit is the same
        
    
        long long c = 9, k = 1;
        while(n > c * k){//this we check to ensure that if the n is greater than the 9 digits of len 1 then it belongs to somelonger length digits
            n -= c * k;//so thats why we re decrementing such that ut gradually
            c *= 10;//if the len is greater than 0ne then it must be multiplie by 10 in each time while loop runs
            k++;
        }
        int result = c / 9 + (n - 1) / k;//this is for finding the number in that specifc range
        
       
        while(n % k != 0) {
           result /= 10;
           n++;
        }
        return result % 10;//this step is to finallyr retur that integer digit extract the nth digit
    }
int main()
{
    int n;
   
    cin>>n;
    cout << findNthdigit(n);
    return 0;
    
}
/*Input: n = 3
Output: 3
Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
