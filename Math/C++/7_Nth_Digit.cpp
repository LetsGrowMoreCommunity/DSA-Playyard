
//Time complexity-0(n)
//Space Complexity-0(n)
#include <iostream>
using namespace std;   
int findNth(int n) {
        
         int len = 1;
        long count = 9;//it has been kept 9 because initially there are 9 digits of len 1 that is 1-9
        int start = 1;

        while (n > len * count) {//this we check to ensure that if the n is greater than the 9 digits of len 1 then it belongs to somelonger length digits
            n -= len * count;//so thats why we re decrementing such that ut gradually belongs to the range 1-9
            len += 1;//so likewise we increase the len
            count *= 10;//if the len is greater than 0ne then it must be multiplie by 10 in each time while loop runs
            start *= 10;
        }
        start += (n - 1) / len;//this is for finding the number in that specifc range
        string s = to_string(start);//then we need to convert it to the string 
        return (s[(n-1)%len])-'0';//this step is to finallyr retur that integer digit and thats why we are subtracting'0'.
        
    
        
    }
int main()
{

    int n;
    string s;
    cin>>n;
    cout << findNth(n);
    return 0;

}
/*Input: n = 3
Output: 3
Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
