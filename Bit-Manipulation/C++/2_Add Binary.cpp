class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.length()-1;
        int j=b.length()-1;//taking the input
        int carry=0;
        
        while(i>=0 || j>=0)
        {
            int temp=carry;
            if(i>=0) temp+=(a[i]-'0'); // converting string into integer
            if(j>=0) temp+=(b[j]-'0');
            ans+=to_string(temp%2); // finding the binary of the no,if both digit is 1 then append 0
            carry=temp/2; // if sum is 2 then carry 1
            i--,j--;
        }
        if(carry!=0) ans+=to_string(carry);//
        reverse(ans.begin(),ans.end());//since we needto print from bottom to up
        return ans;
    }
};
int main()
{
    string a;string b;
    cin>>a>>b;
    cout << addBinary(a, b) << endl;
    return 0;
}
//Example 1:

//Input: a = "1010", b = "1011"
//Output: "10101"
//Example 1:

//Input: a = "11", b = "1"
//Output: "100"