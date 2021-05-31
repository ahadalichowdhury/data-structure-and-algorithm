#include<bits/stdc++.h>
using namespace std;

int main()
{
    int coin, v, i, j;

    cout<<  "enter the total size "<< endl;
    cin>> v;

    cout<< "enter the coin size "<< endl;
    cin>> coin;

    int coin[coin+1];

    cout<< "enter coin values ";
    for(i=0; i<=coin; i++)
    {
        coin[i];
    }

    int t[coin+1][v+1];

    for(i=0; i<=coin; i++)
    {
        for(j=0; j<=v; j++)
        {
            if(j==0)
            {
                t[i][j]=0;
            }
            else if(i==0)
            {
                t[i][j]=1000;
            }
            else
            {
                if(j-coin[i]>= 0)
                {
                   if(t[i-1][j]<= 1+t[i][j-coin[i])
                   {
                       t[i][j]=t[i-1][j];
                   }
                   else
                   {
                       t[i][j]=1+t[i][j-coin[i]);
                   }
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
    }
/*
    for(=0; i<=coin; i++)
    {
        for(j=0; j<=v; j++)
        {
            cout<< "    "<< t[i][j];
        }
        cout<< endl;
    }
*/

    i=coin;
    j=v;

    cout<< "the number of minimum coin  "<< t[i][j]<< endl;
    cout<< "picked coin is "<< endl;

    while(t[i][j] !=0)
    {
        if(t[i-1][j]== t[i][j])
            i--;

        else
        {
            cout<< coin[i];
            j=j-coin[i];
        }

    }
    cout<< endl;



}
