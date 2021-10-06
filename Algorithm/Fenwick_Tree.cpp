#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000001];
ll fenwick[1000001];
int n;
void update(int idx, ll val){
    while(idx <= n){
        fenwick[idx] += val;
        idx += (idx & -idx);
    }
}
ll sum(int idx){
    ll ret = 0;
    while(idx > 0){
        ret += fenwick[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }
    for(int i = 0; i < m + k; i++){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            ll diff = c - arr[b];
            update(b, diff);
            arr[b] = c;
        }else{
            cout << sum(c) - sum(b - 1) << "\n";
        }
    }
    return 0;
}
