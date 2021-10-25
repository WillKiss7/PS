#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 100001;
int sz[N], d[N], p[N], top[N], in[N], out[N];
vector<int> arr, adj[N], c[N];

int seg_size;
struct Seg{
    int tree[N * 4];
    int x, y, val;
    int st_update(int _x, int _val){
        x = _x; val = _val;
        return update();
    }
    int update(int s = 1, int e = seg_size, int pos = 1){
        if(e < x || x < s) return tree[pos];
        if(s == e) return tree[pos] = val;
        return tree[pos] = update(s, (s + e) / 2, pos * 2) ^ update((s + e) / 2 + 1, e, pos * 2 + 1);
    }
    int st_query(int _x, int _y){
        x = _x; y = _y;
        return query();
    }
    int query(int s = 1, int e = seg_size, int pos = 1){
        if(e < x || y < s) return 0;
        if(x <= s && e <= y) return tree[pos];
        return query(s, (s + e) / 2, pos * 2) ^ query((s + e) / 2 + 1, e, pos * 2 + 1);
    }
} seg;
bool isVisited[N];
void dfs(int v){
    isVisited[v] = true;
    for(int next : adj[v]){
        if(isVisited[next]) continue;
        c[v].push_back(next);
        dfs(next);
    }
}
void dfs1(int v){
    sz[v] = 1;
    for(int &next : c[v]){
        d[next] = d[v] + 1;
        p[next] = v;
        dfs1(next);
        sz[v] += sz[next];
        if(sz[next] > sz[c[v][0]]) swap(next, c[v][0]);
    }
}
int pv;
void dfs2(int v){
    in[v] = ++pv;
    for(int next : c[v]){
        top[next] = (next == c[v][0] ? top[v] : next);
        dfs2(next);
    }
    out[v] = pv;
}
int query(int a, int b){
    int ret = 0;
    while(top[a] != top[b]){
        if(d[top[a]] < d[top[b]]) swap(a, b);
        int st = top[a];
        ret ^= seg.st_query(in[st], in[a]);
        a = p[st];
    }
    if(d[a] > d[b]) swap(a, b);
    ret ^= seg.st_query(in[a], in[b]);
    return ret;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q; seg_size = n;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); dfs1(1); dfs2(1); 
    for(int i = 0; i < n; i++){
        seg.st_update(in[i + 1], arr[i]);
    }
    while(q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) seg.st_update(in[a], b);
        else cout << query(a, b) << "\n";
    }
    return 0;
}
