#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long f(int x, vector<int>&c, vector<long long>&dp){
    if(x == 0)
    return 1;
    if(x < 0)
    return 0;
    if(dp[x] != -1)
    return dp[x];
    long long ans = 0;
    for(int i = 0; i < c.size(); i++)
    ans =( ans + f(x - c[i], c, dp)) % MOD;
    return dp[x] = ans;
}
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int>c(n);
    for(int i = 0; i < n; i++)
    cin >> c[i];
    vector<long long>dp(x+1,-1);
    long long ans = f(x, c, dp);
    cout << ans;
}