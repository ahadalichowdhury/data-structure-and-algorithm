#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int r, int c){
    int dp[r+1][c+1];
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j){
                dp[i][j]=max((val[i - 1]+dp[i - 1][j - wt[i - 1]]),(dp[i - 1][j]));
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[r][c];

}
int main(){

    int t;
    cin>>t;
    int W[t+1], C[t+1], r=t, w=0;
    
    for(int i=0; i<t; i++){
        cin>>W[i]>>C[i];
        w+=W[i];
    }
    for(int i=1; i<=w; i++){
        cout << knapsack(i, W, C, r, i) <<"  ";
    }
}
