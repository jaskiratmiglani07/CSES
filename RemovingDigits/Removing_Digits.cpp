#include<bits/stdc++.h>
using namespace std;
int f(int n, vector<int>&dp){
    if(n == 0)
    return 0;
    if(dp[n] != -1)
    return dp[n];
    int ans = 1e9;
    int temp = n;
    while(temp > 0){
        int d = temp % 10;
        temp /= 10;
        if(d > 0){
            ans = min(ans, 1 + f(n-d, dp));
        }
    }
    return dp[n] = ans;
}
int main(){
    int n;
    cin >> n;
    vector<int>dp(n+1, 0);
    // int ans = f(n, dp);
    // cout << ans;
    for(int i = 1; i <= n; i++){
        int ans = 1e9;
        int temp = i;
        while(temp > 0){
            int d = temp % 10;
            temp /= 10;
            if(d > 0){
                ans = min(ans , 1 + dp[i-d]);
            }
        }
        dp[i] = ans;
    }
    cout << dp[n] ;
}