 #include<bits/stdc++.h>

using namespace std;


void mergesort(int a[], int n);

void Merge(int left[],int nl, int right[], int nr, int a[]);

int main()

{

    int n, i;

    cin>>n;

    int a[n];


    for(i=0; i<n; i++)

    {

        cin>> a[i];

    }

    mergesort(a, n);


    cout<< "merge sort is "<<endl;

    for(i=0; i<n; i++)

    {

        cout<< a[i]<<endl;

    }



}

void mergesort(int a[], int n)

{

    int mid, i;

    if(n<2)

        return;


    mid=n/2;

    int left[mid], right[n-mid];


    for(i=0; i<=mid-1; i++)

        left[i]=a[i];

    for(i=mid; i<=n-1; i++)

        right[i-mid]=a[i];


    mergesort(left, mid);

    mergesort(right, n-mid);

    Merge(left, mid, right, n-mid, a);



}

void Merge(int left[],int nl, int right[], int nr, int a[])

{

    int i, j, k;

    i=j=k=0;


    while(i<nl && j<nr)

    {

        if(left[i]<=right[j])

        {

            a[k]=left[i];

            i++;

        }

        else

        {

            a[k]=right[j];

            j++;

        }

        k++;

    }

    while(i<nl)

    {

        a[k]=left[i];

        i++;

        k++;

    }

    while(j<nr)

    {

        a[k]=right[j];

        j++;

        k++;

    }



}



