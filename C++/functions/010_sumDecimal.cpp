// sum of 2 decimal number without using + operator or say only using bitwise operators

#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second  number : ";
    cin >> num2;
    while (num2 != 0)
    {
        int carry = num1 & num2;
        num1 = num1 ^ num2;
        num2 = carry << 1;
    }
    cout << num1;
    return 0;
}