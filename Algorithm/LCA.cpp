int parent[100003][18], depth[100003], n;
vector<int> link[100003];
void make_st(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        link[u].push_back(v); link[v].push_back(u);
    }
    depth[1] = 1; //루트가 1일 때
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : link[now]){
            if(depth[next] != 0) continue;
            depth[next] = depth[now] + 1;
            parent[next][0] = now;
            q.push(next);
        }
    }
    for(int i = 1; i < 18; i++)
        for(int j = 1; j <= n; j++)
            parent[j][i] = parent[parent[j][i - 1]][i - 1]; //sparse table

}
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
        int c;
        for(c = 0; (1 << c) <= n; c++);
        c--;
        for(int i = c; i >= 0; i--)
            if(depth[a] - (1 << i) >= depth[b])
                a = parent[a][i];
        if(a == b) return a;
        for(int i = c; i >= 0; i--)
            if(parent[a][i] != 0 && parent[a][i] != parent[b][i])
                {a = parent[a][i]; b = parent[b][i];}
        return parent[a][0];
}
