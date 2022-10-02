/*
Conversion
Logic - Last se traverse kro aur 2 to the power se start then multiply with last digit then increase power and mul to next digit....
    1. Binary to Decimal
    2. Octal to Decimal
    3. HexaDecimal to Decimal
Logic - Find the highest power of conversion from which number is divisible then reduce the number do this until 0
    4. Decimal to Binary
    5. Decimal to Octal
    6. Decimal to HexaDecimal


*/
#include <bits/stdc++.h>
using namespace std;
int Binary_decimal(int num)
{
    int ans = 0;
    int base = 1; // 2 to the power 0
    while (num > 0)
    {
        int lastDigit = num % 10;
        ans = ans + lastDigit * base;
        base = base * 2;
        num = num / 10;
    }
    return ans;
}
int Octal_decimal(int num)
{
    int ans = 0;
    int base = 1; // 8 to the power 0
    while (num > 0)
    {
        int lastDigit = num % 10;
        ans = ans + lastDigit * base;
        base = base * 8;
        num = num / 10;
    }
    return ans;
}
int Hexa_decimal(string num)
{
    int ans = 0;
    int base = 1; // 16 to the power 0
    int size = num.size();
    for (int i = size - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            ans = ans + base * (num[i] - '0');
        }
        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            ans = ans + base * (num[i] - 'A' + 10);
        }
        base = base * 16;
    }

    return ans;
}
int Decimal_Binary(int num)
{
    int ans = 0;
    int base = 1;
    while (base <= num) // Finding highest power
    {
        base *= 2;
    }
    base /= 2; // in while is run even if differece is not greater the base
    while (base > 0)
    {
        int lastDigit = num / base;
        num -= lastDigit * base;
        base /= 2;
        ans = ans * 10 + lastDigit;
    }
    return ans;
}
int Decimal_Octal(int num)
{
    int ans = 0;
    int base = 1;
    while (base <= num) // Finding highest power
    {
        base *= 8;
    }
    base /= 8; // in while is run even if differece is not greater the base
    while (base > 0)
    {
        int lastDigit = num / base;
        num -= lastDigit * base;
        base /= 8;
        ans = ans * 10 + lastDigit;
    }
    return ans;
}

string Decimal_Hexa(int num)
{
    string ans = " ";
    int base = 1;
    while (base <= num) // Finding highest power
    {
        base *= 16;
    }
    base /= 16; // in while is run even if differece is not greater the base
    while (base > 0)
    {
        int lastDigit = num / base;
        num -= lastDigit * base;
        base /= 16;
        if (lastDigit <= 9)
            ans = ans + to_string(lastDigit);
        else
        {
            char c = 'A' + lastDigit - 10;
            ans.push_back(c);
        }
    }
    return ans;
}
int main()
{
    // 1.
    int Bin_num;
    cout << "Enter binary number : ";
    cin >> Bin_num;
    cout << "Decimal value of " << Bin_num << " is " << Binary_decimal(Bin_num) << endl;

    // 2.
    int Oct_num;
    cout << "Enter Octal number : ";
    cin >> Oct_num;
    cout << "Decimal value of " << Oct_num << " is " << Octal_decimal(Oct_num) << endl;

    // 3.
    string Hex_num;
    cout << "Enter Hexa number : ";
    cin >> Hex_num;
    cout << "Decimal value of " << Hex_num << " is " << Hexa_decimal(Hex_num) << endl;

    // 4.
    int decBin_num;
    cout << "Enter Decimal number : ";
    cin >> decBin_num;
    cout << "Binary value of " << decBin_num << " is " << Decimal_Binary(decBin_num) << endl;

    // 5.
    int decOct_num;
    cout << "Enter Decimal number : ";
    cin >> decOct_num;
    cout << "Binary value of " << decOct_num << " is " << Decimal_Octal(decOct_num) << endl;

    // 6.
    int decHex_num;
    cout << "Enter Decimal number : ";
    cin >> decHex_num;
    cout << "Binary value of " << decHex_num << " is " << Decimal_Hexa(decHex_num) << endl;
    return 0;
}