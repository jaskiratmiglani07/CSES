#include<bits/stdc++.h>
using namespace std;
int func(int n, vector<int>&dp){
    if(n == 0)
    return 1;
    if(n < 0)
    return 0;
    if(dp[n] != -1)
    return dp[n];
    int ans = 0;
    const int MOD = 1e9+7;
    for(int i = 1; i <= 6; i++)
    ans = (ans + func(n-i, dp)) % MOD;
    return dp[n] = ans;
}
int main(){
    int n;
    cin >> n;
    vector<int>dp(n+1,-1);
    int ans = func(n, dp);
    cout << ans;
}