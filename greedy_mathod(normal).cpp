#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    vector<lli> bills;

    bills.push_back(100);
    bills.push_back(20);
    bills.push_back(10);
    bills.push_back(5);
    bills.push_back(1);

    lli cash;
    cin>>cash;

    int count=0;

    for(int i=0; i<bills.size(); i++)
    {
        count+=cash/bills[i];
        cash=cash%bills[i];
    }

    cout<< count << endl;




}
