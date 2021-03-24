#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100003
struct line{
    ll s, p;
    double st;
};
vector<ll> A, B;
vector<line> f;
ll dp[MAX];
inline double cross(line &a, line &b){
    return (b.p - a.p) / (a.s - b.s);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        A.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        B.push_back(tmp);
    }
    for(int i = 1; i < n; i++){
        line tmp = {B[i - 1], dp[i - 1], 0};
        while(!f.empty()){
            tmp.st = cross(f.back(), tmp);
            if(f.back().st < tmp.st) break;
            f.pop_back();
        }
        f.push_back(tmp);
        ll x = A[i];
        int pos = f.size() - 1;
        if(x < f.back().st){
            int s = 0, e = f.size() - 1;
            while(e - s >= 2){
                int mid = (s + e) / 2;
                (x < f[mid].st ? e : s) = mid;
            }
            pos = s;
        }
        dp[i] = f[pos].s * A[i] + f[pos].p;
    }
    cout << dp[n - 1];
  
    return 0;
}
