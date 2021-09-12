//BOJ 13548 수열과 쿼리 6
#include <bits/stdc++.h>
using namespace std;
int arr[100001], cnt[100001], table[100001];
vector<int> ans;
struct QINfo{
    int idx, x, y;
};
vector<QINfo> query;
int k, ret;
void Add(int x){
    if(cnt[x] != 0) table[cnt[x]]--;
    cnt[x]++;
    table[cnt[x]]++;
    ret = max(ret, cnt[x]);
}
void Delete(int x){
    table[cnt[x]]--;
    if(cnt[x] == ret && table[cnt[x]] == 0) ret--;  
    cnt[x]--;
    table[cnt[x]]++;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n; k = sqrt(n);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int m; cin >> m;
    ans.resize(m);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        query.push_back({i, x, y});   
    }
    sort(query.begin(), query.end(), [](const QINfo& a, const QINfo& b){
        if(a.x / k != b.x / k) return a.x / k < b.x / k;
        return a.y < b.y;
    });
    int s = 0, e = 0, res = 0;
    for(int i = 0; i < m; i++){
        while(s < query[i].x) Delete(arr[s++]);
        while(s > query[i].x) Add(arr[--s]);
        while(e < query[i].y) Add(arr[++e]);
        while(e > query[i].y) Delete(arr[e--]);
        ans[query[i].idx] = ret;
    }
    for(int output : ans) cout << output << "\n";

    return 0;
}
