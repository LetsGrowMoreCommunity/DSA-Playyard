// Fibonacci Series -   0 1 1 2 3 5 8 13 21 34 .....
#include <iostream>
using namespace std;
void fibo(int num)
{
    int first = 0;
    int second = 1;
    int next;
    for (int i = 1; i <= num; i++)
    {
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
    return;
}
int main()
{
    int num;
    cout << "Enter the term ";
    cin >> num;
    fibo(num);
    return 0;
}