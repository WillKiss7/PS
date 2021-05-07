//acmicpc.net/problem/1197
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
priority_queue<piii, vector<piii>, greater<piii>> pq;
int parent[10003];
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void uf(int a, int b){
    a = find(a); b = find(b);
    if(a > b) swap(a, b);
    parent[b] = a;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, ans = 0; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    while(m--){
        int a, b, dist;
        cin >> a >> b >> dist;
        pq.push({dist, {a, b}});
    }
    while(!pq.empty()){
        int dist = pq.top().first;
        int node1 = pq.top().second.first, node2 = pq.top().second.second;
        pq.pop();
        if(find(node1) == find(node2)) continue;
        ans += dist;
        uf(node1, node2);
    }
    cout << ans;
    
    return 0;
}
