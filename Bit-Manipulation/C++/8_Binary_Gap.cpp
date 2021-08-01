time complexity of the program-0(N) 
Space complexity -O(1)
#include <bits/stdc++.h>

using namespace std;
    int binaryGap(int N) {
       
        
        int Gap =INT_MIN ;
        int i = 1;//since its told to convert find the ditance between 
        int   count=0;
        
        while(N)
        {  count++;
                if(N&1)//calculating the binary
                    Gap = max(Gap, i - count);//minimum the gap should be 1
                count = i;
            
            i++;
            N = N>>1;;//to convert to binary
        }
        
        return Gap;
        
    }
int main()
{
    int N;
    cin>>N;
    cout<<binaryGap(N)<<endl;
    return 0;
}
/*Example 2:

Input: n = 5
Output: 2
Explanation: 5 in binary is "101".
Example 3:

Input: n = 6
Output: 1
Explanation: 6 in binary is "110"./*