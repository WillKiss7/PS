//bipartite matching
vector<int> link[203];
int d[203];
bool c[203];
bool dfs(int x){
    for(auto next : link[x]){
        if(c[next]) continue;
        c[next] = true;
        if(d[next] == 0 || dfs(d[next])){
            d[next] = x;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int tmp1, tmp2;
        cin >> tmp1;
        while(tmp1--){
            cin >> tmp2;
            link[i].push_back(tmp2);
        }
    }
    for(int i = 1; i <= n; i++){
        fill(c + 1, c + m + 1, false);
        if(dfs(i)) cnt++;
    }
    cout << cnt;
    return 0;
}
