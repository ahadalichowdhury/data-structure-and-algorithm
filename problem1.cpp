#include<bits/stdc++.h>
using namespace std;
void InsertionSort(int a[],int n)
{
    int item,j;
    for(int i=1 ; i< n ; i++)
    {
        item = a[i],j=i-1;
        while(item>a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = item;
    }
    for(auto i=0 ; i<n ; i++)
        cout << a[i] << "  ";
    cout << endl;
}
int BinSearch(int a[],int n, int k)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(a[mid]==k)
        {
            return mid+1;
        }
        else if(k>a[mid])
            right=mid-1;
        else
            left=mid+1;
    }
    return -1;
}
int  main()
{
    int n,arr[1000],k;
    cin >> n ;
    for(int i=0 ; i<n ; i++)
        cin >> arr[i];
    cin >> k;
    InsertionSort(arr,n);
    int key= BinSearch(arr,n,k);
    cout<< key << endl;

}
