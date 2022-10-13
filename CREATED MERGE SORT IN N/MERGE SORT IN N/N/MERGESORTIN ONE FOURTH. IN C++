#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int start,int mid1, int mid, int mid2,int end)
{

    int n1 =mid1-start+1;
    int n2 = mid-mid1;
    int n3 = mid2-mid;
    int n4 =end-mid2 ;

    int akrr[n1+1], brr[n2+1], crr[n3+1], drr[n4+1];
    akrr[n1]=10000000;
    brr[n2]=100000000;
    crr[n3]=100000000;
   drr[n4]=1000000000;

    for (int q = 0; q < n1; q++)
    {
        akrr[q] = arr[start + q];
       
    }
    for (int q = 0; q < n2; q++)
    {
        brr[q] = arr[mid1 + q+1];
       
    }
    for (int q = 0; q < n3; q++)
    {
        crr[q] = arr[mid + q+1];
        
    }
    for (int q = 0; q < n4; q++)
    {
        drr[q] = arr[mid2 + q+1];
       
    }

    int w = 0, h = 0;
    int z = 0, y = 0, f = start;
    while (w <= n1 && h <=n2 && z <=n3 && y <= n4 && f<=end)
    {
        if (akrr[w] < brr[h] && akrr[w] < crr[z] && akrr[w] < drr[y])
        {
            arr[f] = akrr[w];
            
            w++;
            f++;

        }
         else if ( brr[h] < crr[z] && brr[h] <drr[y])
        {
            arr[f] = brr[h];
            h++;
            f++;
        }
       else  if (crr[z] < drr[y])
        {
            arr[f] = crr[z];
            z++;
            f++;
        }
        else 
        {
            arr[f] = drr[y];
            y++;
            f++;
        }
        
    }

}
void mergesort(int arr[], int start, int end)
{ 

    if (start < end)
    {

     int mid=(start+end)/2;
     int mid1= (start+mid)/2;////half of start and mid
     int mid2=(mid+1+end)/2;; ////half of mid and end;

        mergesort(arr, start, mid1);
        mergesort(arr, mid1+1 , mid);
        mergesort(arr, mid+1, mid2);
        mergesort(arr, mid2+1, end);
        merge(arr,start,mid1,mid,mid2,end);
    }
}

int main()
{
    int arr[] = {5,4,3,2,1,6,7,23,21,22,87,90,276};
    cout << "before sorted array";
    for (int i = 0; i <4; i++)
    {
        cout << arr[i]<<endl;
    }
    mergesort(arr, 0, 12);
    cout << "after sort"<<endl;;

    for (int i = 0; i <13; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
