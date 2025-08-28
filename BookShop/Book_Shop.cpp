#include<bits/stdc++.h>
using namespace std;
int f(int i, int x, vector<int>&h, vector<int>&s, vector<vector<int>>&dp){
    if(x < 0 || i < 0)
    return 0;
    if(dp[i][x] != -1)
    return dp[i][x];
    int ans = INT_MIN;
    if(h[i] <= x)
    dp[i][x] = ans = max(s[i] + f(i-1,x-h[i], h, s, dp), f(i-1, x, h, s, dp));
    else
    dp[i][x] = ans = f(i-1, x, h, s, dp);
    return dp[i][x];
}
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int>h(n);
    vector<int>s(n);
    for(int i = 0; i < n; i++)
    cin >> h[i];
    for(int i = 0; i < n; i++)
    cin >> s[i];
    vector<vector<int>>dp(n, vector<int>(x+1, 0));
    for(int i = 0; i < n; i++)
    dp[i][0] = 0;
    for(int j = 0; j <= x; j++){
        if(j >= h[0])
        dp[0][j] = s[0];
        else
        dp[0][j] = 0;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(h[i] <= j){
                dp[i][j] = max(s[i] + dp[i-1][j-h[i]], dp[i-1][j]);
            } else
            dp[i][j] = dp[i-1][j];
        }
    }
    // int result = f(n-1, x, h, s, dp);
    // cout << result;
    cout << dp[n-1][x];
}