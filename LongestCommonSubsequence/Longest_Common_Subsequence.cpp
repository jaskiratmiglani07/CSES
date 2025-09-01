#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int>a;
vector<int>b;
vector<vector<int>>dp;
int lcs(int i, int j){
    if(i < 0 || j < 0)
    return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
    if(a[i] == b[j]){
        return dp[i][j] = 1 + lcs(i-1, j-1);
    }else{
        return dp[i][j] = max(lcs(i-1, j) ,lcs(i, j-1));
    }
}
int main(){ 
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    dp.assign(n+1, vector<int>(m+1, 0));
    for(int i = 0; i < n; i++)
    cin >> a[i];
    for(int j = 0; j < m; j++)
    cin >> b[j];
    // int ans = lcs(n-1, m-1);
    // cout << ans;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m];
    cout << endl;
    int i = n;
    int j = m;
    vector<int>res;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            res.push_back(a[i-1]);   
            i--;
            j--;         
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = res.size()-1; i >= 0; i--)
    cout << res[i] << " ";
    cout << endl;
}