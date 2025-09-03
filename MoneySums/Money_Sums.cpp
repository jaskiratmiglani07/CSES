#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int n;
vector<int>x;
unordered_set<int>us;
vector<vector<int>>dp;
void f(int i, int sum){
    if(i == -1){
        if(us.find(sum) == us.end())
        us.insert(sum);
        return;
    }
    if(dp[i][sum] != -1)
    return;
    else
    dp[i][sum] = 1;
    f(i-1, sum - x[i]);
    f(i-1, sum);
}
int main(){
    cin >> n;
    x.resize(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
    cin >> x[i];
    sum += x[i];
    }
    dp.assign(n, vector<int>(sum+1, -1));
    f(n-1, sum);
    int ans = us.size() - 1;
    cout << ans << endl;
    vector<int> sums(us.begin(), us.end()); 
    sort(sums.begin(), sums.end());          
    for(int s : sums)
    if(s > 0) cout << s << " ";        
}