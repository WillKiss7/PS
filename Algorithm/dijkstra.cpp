//Dijkstra
#define SIZE 10000
#define INF (1 << 31) - 1
#define pii pair<int, int>
void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<pii> link[SIZE];
    int dp[SIZE];
    fill(dp + 1, dp + SIZE + 1, INF);
    pq.push({0, 1});
    dp[1] = 0;
    while(!pq.empty()){
        int dist = pq.top().first, now = pq.top().second;
        pq.pop();
        if(dp[now] < dist) continue;
        for(pii tmp : link[now]){
            int dis = tmp.first, next = tmp.second;
            if(dp[next] > dist + dis){
                dp[next] = dist + dis;
                pq.push({dist + dis, next});
            }
        }
    }
}
