#include <iostream>
using namespace std;
int main()
{

    int x[] = { -1/*garbage value*/, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(x) / sizeof(x[1]);
    int l, h, mid;
    l=1;
    h=n;
    int z = 4;
    bool flag=false;

    while(l<=h)
    {
        mid=(l+h)/2;
        int xm=x[mid];
        if(xm<z)
        {
            l=mid+1;
        }
        if(xm>z)
        {
            h=mid-1;
        }
        if(xm==z)
        {
            flag=true;
            break;
        }
    }
    if(flag==true)
    {
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}
