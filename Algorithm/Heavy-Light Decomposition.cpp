#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 100001;
int sz[N], d[N], p[N], top[N], in[N], out[N];
vector<int> adj[N], c[N];

struct Input{
    int u, v, w;
};
vector<Input> arr;
int seg_size;
struct Seg{
    int tree[N * 4];
    int x, y, val;
    void set_updaterange(int _x, int _val){
        x = _x; val = _val;
    }
    int update(int s = 1, int e = seg_size, int pos = 1){
        if(e < x || x < s) return tree[pos];
        if(s == e) return tree[pos] = val;
        return tree[pos] = max(update(s, (s + e) / 2, pos * 2), update((s + e) / 2 + 1, e, pos * 2 + 1));
    }
    void set_queryrange(int _x, int _y){
        x = _x; y = _y;
    }
    int query(int s = 1, int e = seg_size, int pos = 1){
        if(e < x || y < s) return 0;
        if(x <= s && e <= y) return tree[pos];
        return max(query(s, (s + e) / 2, pos * 2), query((s + e) / 2 + 1, e, pos * 2 + 1));
    }
} seg;
bool isVisited[N];
void dfs(int v){
    for(int next : adj[v]){
        if(isVisited[next]) continue;
        isVisited[next] = true;
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
        seg.set_queryrange(in[st], in[a]);
        ret = max(ret, seg.query());
        a = p[st];
    }
    if(d[a] > d[b]) swap(a, b);
    seg.set_queryrange(in[a] + 1, in[b]);
    ret = max(ret, seg.query());
    return ret;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; seg_size = n;
    for(int i = 0; i < n - 1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        arr.push_back({u, v, w});
    }
    isVisited[1] = true;
    dfs(1); dfs1(1); dfs2(1);
    for(Input tmp : arr){
        seg.set_updaterange((d[tmp.u] > d[tmp.v] ? in[tmp.u] : in[tmp.v]), tmp.w);
        seg.update();
    }
    int q; cin >> q;
    while(q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1){
            a--;
            int vt = (d[arr[a].u] > d[arr[a].v] ? arr[a].u : arr[a].v);
            seg.set_updaterange(in[vt], b);
            seg.update();
        }else{
            cout << query(a, b) << "\n";
        }
    }
    return 0;
}
