#include <iostream>
using namespace std;
int main()
{
    int arr[] = { -1/*garbage value*/, 2, 66, 11, 23, 24, 88, 64 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int z=2;
    int i=1;
    while(i<=n && z!=arr[i])
    {
        i++;
    }
    if(i<=n)
    {
        cout<< "found";
    }
    else
    {
        cout<< "not found";
    }
    return 0;
}



 
