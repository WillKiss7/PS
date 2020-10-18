#include <bits/stdc++.h>
using namespace std;
#define MAX 100003
int v, e, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int>> SCC;
int DFS(int cur){
    S.push(cur);
    int result = dfsn[cur] = ++cnt;
    for(int next : adj[cur]){
        if(dfsn[next] == 0) result = min(result, DFS(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
    if(result == dfsn[cur]){
        vector<int> curSCC;
        while(1){
            int tmp = S.top(); S.pop();
            curSCC.push_back(tmp);
            finished[tmp] = true;
            sn[tmp] = SN;
            if(tmp == cur) break;
        }
        sort(curSCC.begin(), curSCC.end());
        SCC.push_back(curSCC);
        SN++;
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= v; i++)
        if(dfsn[i] == 0) DFS(i);
    sort(SCC.begin(), SCC.end());
    cout << SN << "\n";
    for(auto curSCC : SCC){
        for(int cur : curSCC)
            cout << cur << " ";
        cout << -1 << "\n";
    }
    return 0;
}
