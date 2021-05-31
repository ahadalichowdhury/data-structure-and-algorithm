 #include<bits/stdc++.h>
using namespace std;
int Partition(int a[], int left, int right)
{
    int pivot=a[left];
    int i=left;
    int j=right;
    while(i<j)
    {
        while(a[i]<=pivot && i<=right)
        {
            i=i+1;
        }
        while(a[j]>pivot)
        {
            j=j-1;
        }
        if(i<j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[j], a[left]);

    return j;
}
void QuickSort(int a[], int left, int right)
{
    if(left< right)
    {
    int q= Partition(a, left, right);
    QuickSort(a, left, q-1);
    QuickSort(a, q+1, right);
    }

}
int main()
{
    int n;

    cin>>n;
    int a[n];

    for(int i=0; i<n; i++)

    {

        cin>> a[i];

    }

    QuickSort(a, 0, n-1);

    for(int i=0; i<n; i++)

    {

        cout<< a[i];

    }
}
