//acmicpc.net/problem/1922
#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;
int val[1003], ans = 0;
vector<pair<int, int>> link[1003];
bool visit[1003];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, ans = 0; cin >> n >> m;
    while(m--){
        int a, b, dist;
        cin >> a >> b >> dist;
        link[a].push_back({dist, b});
        link[b].push_back({dist, a});
    }
    for(int i = 2; i <= n; i++)
        val[i] = INF;
    for(int i = 0; i < n; i++){
        int min = (1 << 31) - 1, num;
        for(int j = 1; j <= n; j++)
            if(!visit[j] && val[j] < min){
                min = val[j];
                num = j;
            }
        ans += val[num];
        visit[num] = true;
        for(auto next : link[num]){
            int dist = next.first;
            int next_node = next.second;
            if(val[next_node] > dist)
                val[next_node] = dist;
        }
    }
    cout << ans;
    
    return 0;
}
