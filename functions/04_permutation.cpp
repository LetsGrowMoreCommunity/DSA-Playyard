// Combination nCr = fact(n) / fact(n-r) * fact(r)

#include <iostream>
using namespace std;
int fac(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    int n, r;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter the ways: ";
    cin >> r;
    cout << "Comibnation of " << n << " and " << r << " is " << fac(n) / (fac(r) * fac(n - r));

    return 0;
}