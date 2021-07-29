/* 
Problem: Happy Number

Description: A happy number is a number defined by the following process:
1. Starting with any positive integer, replace the number by the sum of the squares of its digits.
2. Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
3. Those numbers for which this process ends in 1 are happy.

*/

#include <iostream>

using namespace std;
int isHappy(int num){  
    int rem = 0, sum = 0;  
    
    while(num > 0){  //calculates the sum of digits of an integer
        rem = num%10;  
        sum = sum + (rem*rem);  
        num = num/10;  
    }  
    return sum;  
}  
int main()  
{  
    int num;  
    cout<<"Enter the number: ";
    cin>>num;
    int result = num;  
      
    while(result != 1 && result != 4){  
        result = isHappy(result);  
    }  
    if(result == 1)  
        cout<<num<<" is a happy number."; //happy number ends with 1.
    else if(result == 4)
		cout<<num<<" is a happy not number.";  //if loop continues. 
   
    return 0;  
}  

/*
Explanation : For example if we give 32 as an input.
32= 3^2 + 2^2 = 13
12= 1^2 + 3^2 = 10
10= 1^2 + 0^2 = 1 
Hence it's a Happy number.

Input: n = 17
Explanation:
1^2 + 7^2 = 53
5^2 + 3^2 = 34
3^2 + 4^2 = 25
2^2 + 5^2 = 29 ..... This keeps on increasing and decreasing and loop continues hence, this is unhappy number.

Point to Remember:
If the process results in an endless cycle of numbers containing 4, then the number is called an unhappy number.
If output is 1 then it's an happy number.

Solution of Happy number by taking user input in c++. 
*/
