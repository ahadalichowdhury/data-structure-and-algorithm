#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    char x[100], y[100];

    cout<< "enter the first string: "<< endl;
    gets(x);
    n=strlen(x);

    cout<< "enter the second string : "<< endl;
    gets(y);
    m=strlen(y);

    int t[n+1][m+1];

    for(int i=0; i<=n; i++)
    {
        t[i][0]=0;
    }
    for(int i=0; i<=m; i++)
    {
        t[0][i]=0;
    }

    

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(x[i-1]==y[j-1])
            {
                t[i][j]=t[i-1][j-1]+1;

            }
            else
            {
                if(t[i-1][j]>=t[i][j-1])
                    t[i][j]=t[i-1][j];

                else
                    t[i][j]=t[i][j-1];

            }
        }
        
    }

    cout<< " the table is: "<< endl;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<< " " << t[i][j] << " ";
        }
        cout<< endl;
    }

    int i=n;
    int j=m;
    int k=0;
    char subse[100];
    while(t[i][j]!=0)
    {
        if(x[i-1]==y[j-1])
        {
            subse[k++]=x[i-1];
            i--;
            j--;
        }
        else if(t[i-1][j]>=t[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout <<"the subsequence is: " ;
    cout<< strrev(subse);


}
//abcbdab
//bdcaba
