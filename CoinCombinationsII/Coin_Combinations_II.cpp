#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7; 
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int>c(n);
    for(int i = 0; i < n; i++)
    cin >> c[i];
    vector<vector<int>>dp(n, vector<int>(x+1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;    
    for(int i = 0; i < n; i++){
    for(int j = 1; j <= x; j++){
        int take = 0;
        if(j - c[i] >= 0) take = dp[i][j - c[i]];
        int not_take = 0;
        if(i > 0) not_take = dp[i-1][j];
        dp[i][j] = (take + not_take) % MOD;
    }
    }
    cout << dp[n-1][x] << endl;  
}