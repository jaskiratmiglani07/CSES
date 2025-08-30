#include<bits/stdc++.h>
using namespace std;
//2 0 0 2
const int M= 1e9+7;
int n, m;
vector<vector<long long>>dp;
vector<int>x;
long long ways(int i, int v){
    if(v < 1 || v > m) return 0;
    if(x[i] != 0 && x[i] != v) return 0;//if x[i] is a non-zero value, it must be equal to v.
    if(i == n-1) return 1;
    if(dp[i][v] != -1)
    return dp[i][v];
    long long cnt = 0;
    cnt = (cnt + ways(i+1, v)) % M;
    cnt = (cnt + ways(i+1, v+1)) % M;
    cnt = (cnt + ways(i+1, v-1)) % M;
    return dp[i][v] = cnt;
}
int main(){
    cin >> n; 
    cin >> m;
    x.resize(n);
    for(int i = 0; i < n; i++)
    cin >> x[i];
    dp.assign(n, vector<long long>(m+1, 0));
    // if(x[0] == 0){
    //     for(int v = 1; v <= m; v++){
    //         ans = (ans + ways(0, v) % M);
    //     }
    // } else {
    //     ans = ways(0, x[0]);
    // }
    if(x[n-1] == 0){
        for(int v = 1; v <= m; v++) dp[n-1][v] = 1;
    } else {
        dp[n-1][x[n-1]] = 1;
    }
    for(int i = n-2; i >= 0; i--){
        for(int v = 1; v <= m; v++){
            if(x[i] != 0 && x[i] != v) continue;
            long long cnt = dp[i+1][v] % M;
            if(v > 1) cnt = (cnt + dp[i+1][v-1]) % M;
            if(v < m) cnt = (cnt + dp[i+1][v+1]) % M;
            dp[i][v] = cnt;
        }
    }
    long long ans = 0;
    if(x[0] == 0){
        for(int v = 1; v <= m; v++) ans = (ans + dp[0][v]) % M;
    } else {
        ans = dp[0][x[0]];
    }
    cout << ans % M << endl;
}