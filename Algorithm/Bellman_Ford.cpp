//Bellman_Ford
#define ll long long
#define pii pair<ll, ll>
#define INF 1e18
#define SIZE 503
vector<pii> link[SIZE];
ll dist[SIZE];
void Bellman_Ford(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        link[a].push_back({c, b});
    }
    bool minuscycle = false;
    fill(dist + 1, dist + n + 1, INF);
    dist[1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(pii tmp : link[j]){
                ll dis = tmp.first, next = tmp.second;
                if(dist[j] != INF && dist[next] > dist[j] + dis){
                    dist[next] = dist[j] + dis;
                    if(i == n) minuscycle = true;
                }
            }
        }
    }
    if(minuscycle) cout << -1;
    else for(int i = 2; i <= n; i++) cout << ((dist[i] != INF) ? dist[i] : -1) << "\n";
}
