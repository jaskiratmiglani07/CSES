#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int>c(n);
    for(int i = 0; i < n; i++)
    cin >> c[i];
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));   
    for(int j = 0; j <= x; j++)
    dp[0][j] = 1e9;
    for(int i = 0; i <= n; i++)
    dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(c[i - 1] <= j)
            dp[i][j] = min(1 + dp[i][j - c[i - 1]], dp[i - 1][j]);
            else
            dp[i][j] = dp[i - 1][j];
        }
    }
    if(dp[n][x] != 1e9)
    cout << dp[n][x];
    else
    cout << -1;
}