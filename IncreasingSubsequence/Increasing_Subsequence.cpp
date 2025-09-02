#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>x;
int main(){
    cin >> n;
    x.resize(n);
    for(int i = 0; i < n; i++)
    cin >> x[i];
    vector<int>temp;
    temp.push_back(x[0]);
    for(int i = 1; i < n; i++){
        if(x[i] > temp.back())
        temp.push_back(x[i]);
        else{
        int idx = lower_bound(temp.begin(), temp.end(), x[i]) - temp.begin();
        temp[idx] = x[i];
        }
    }
    cout << temp.size();
}