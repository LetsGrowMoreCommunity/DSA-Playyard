// Write all prime number between two given numbers
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int num1, num2;
    cout << "Enter 2 numbers : " << endl;
    cin >> num1 >> num2;
    for (int i = num1; i <= num2; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }

    return 0;
}