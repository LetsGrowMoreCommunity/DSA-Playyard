// Factorial
#include <iostream>
using namespace std;
void fac(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    cout << fact;
    return;
}
int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    fac(num);
    return 0;
}