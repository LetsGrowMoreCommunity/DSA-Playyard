// Addition of 2 binary number

#include <bits/stdc++.h>
using namespace std;
string reverse_ans(int num)
{
    int ans = 0;
    while (num > 0)
    {
        int last = num % 10;
        ans = ans * 10 + last;
        num = num / 10;
    }
    return to_string(ans);
}
string sumBinary(int a, int b)
{
    int ans = 0;
    int prevCarry = 0;
    while (a > 0 && b > 0)
    {
        int a_last = a % 2;
        int b_last = b % 2;
        if (a_last == 0 && b_last == 0)
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 0;
        }
        else if (a_last == 1 && b_last == 1)
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 1;
        }
        else
        {
            if (prevCarry == 1)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
        }
        a = a / 10;
        b = b / 10;
    }

    // case 2 - if a is left and b finshed
    // case 3 - if b is left and a finshed

    if (prevCarry == 1)
        ans = ans * 10 + prevCarry;
    string final_ans = reverse_ans(ans);
    return final_ans;
}
int main()
{
    int num1, num2;
    cout << "Enter first binary number : ";
    cin >> num1;
    cout << "\nEnter second binary number : ";
    cin >> num2;
    cout << sumBinary(num1, num2);
    return 0;
}