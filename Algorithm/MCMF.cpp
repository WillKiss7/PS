 #include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;
int c[803][803], f[803][803], cost[803][803], d[803];
vector<int> adj[803];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        c[0][i] = 1;
        adj[0].push_back(i);
        adj[i].push_back(0);
    }
    for(int i = n + 1; i <= n + m; i++){
        c[i][n + m + 1] = 1;
        adj[i].push_back(n + m + 1);
        adj[n + m + 1].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        for(int j = 0; j < num; j++){
            int work, cos; cin >> work >> cos;
            c[i][n + work] = 1;
            adj[i].push_back(n + work);
            adj[n + work].push_back(i);
            cost[i][n + work] = cos;
            cost[n + work][i] = -cos;
        }
    }
    int result = 0, cnt = 0;
    while(1){
        int prev[803], dist[803];
        bool inQ[803] = {0};
        //SPFA
        queue<int> q;
        fill(prev, prev + 803, -1);
        fill(dist, dist + 803, INF);
        
        dist[0] = 0;
        inQ[0] = true;
        
        q.push(0);
        
        while(!q.empty()){
            int now = q.front();
            q.pop();
            inQ[now] = false;
            for(int next : adj[now]){
                if(c[now][next] - f[now][next] > 0 && dist[next] > dist[now] + cost[now][next]){
                    dist[next] = dist[now] + cost[now][next];
                    prev[next] = now;
                    if(!inQ[next]){
                        q.push(next);
                        inQ[next] = true;
                    }
                }
            }
        }
        if(prev[n + m + 1] == -1) break;
        int flow = INF;
        for(int i = n + m + 1; i != 0; i = prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i = n + m + 1; i != 0; i = prev[i]){
            result += flow * cost[prev[i]][i];
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        cnt++;
    }
    cout << cnt << "\n" << result;
    
    return 0;
}
