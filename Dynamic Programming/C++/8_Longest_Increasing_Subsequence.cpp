#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int *inc = new int[n];
    inc[0]=1;
    for(int i=1; i<n; i++)
    {
        inc[i]=1;
        for(int j=i-1; j>=0; j--)
        {
            if(arr[i]<=arr[j])
            {
                continue;
            }
            int possibleAns=inc[j]+1;
            if(possibleAns>inc[i])
            {
                inc[i]=possibleAns;
            }
        }
    }
    int best=0;
    for(int i=0; i<n; i++)
    {
        if(best<inc[i])
        {
            best=inc[i];
        }
    }
    delete [] inc;
    return best;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
