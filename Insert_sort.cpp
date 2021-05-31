 #include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the array size:"<<endl;
    cin>>n;
    int arr[100];
    int  i,temp,pos;
    cout<<"Elements of array:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<n; i++)
    {
        temp=arr[i];
        pos=i;
        /// 4>10

        while(pos > 0 && arr[pos-1] > temp)
        {
          arr[pos]=arr[pos-1];
          pos--;
        }
        arr[pos]=temp;
    }
    for(i=0; i<n; i++)
    {

        cout<<arr[i]<<endl;

    }
}

