/*
Sum of N natural number
*/
#include <iostream>
using namespace std;
int sum(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i;
    }
    return ans;
}
int main()
{
    int num;
    cout << "Enter the nth term : ";
    cin >> num;
    cout << sum(num) << endl;
    return 0;
}