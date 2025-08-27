#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long f(int i, int j, vector<vector<char>>&grid, vector<vector<long long>>&dp){
    if(i == 0 && j == 0 && grid[i][j] != '*')
    return 1;
    if(i < 0 || j < 0 || grid[i][j] == '*')
    return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
    return dp[i][j] =( f(i-1, j, grid, dp) + f(i, j-1, grid, dp)) % MOD;
}
int main(){
    long long n;
    cin >> n;
    vector<vector<char>>grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<long long>>dp(n+1, vector<long long>(n, 0));
    // int ans = f(n-1, n-1, grid, dp);
    // cout << ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0 && grid[i][j] != '*')
            dp[i][j] = 1;
            else if(i < 0 || j < 0 || grid[i][j] == '*')
            dp[i][j] = 0;
            else{
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n-1][n-1];
}