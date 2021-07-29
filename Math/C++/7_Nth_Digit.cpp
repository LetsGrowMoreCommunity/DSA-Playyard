
//Time complexity-0(n)
//Space Complexity-0(n)
#include <iostream>
using namespace std;   
int findNth(int n) {
        
         int len = 1;
        long count = 9;
        int start = 1;

        while (n > len * count) {
            n -= len * count;
            len += 1;
            count *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return (s[(n-1)%len])-'0';
        
    
        
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