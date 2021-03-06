#include <bits/stdc++.h>
using namespace std;
vector<int> link[60];
int c[60][60], f[60][60], d[60], result;

void flow_max(int start, int end){
    while(1){
        fill(d, d + 58, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int y : link[x]){
                if(c[x][y] - f[x][y] > 0 && d[y] == -1){
                    q.push(y);
                    d[y] = x;
                    if(y == end) break;
                }
            }
        }
        if(d[end] == -1) break;
        int flow = (1 << 31) - 1;
        for(int i = end; i != start; i = d[i])
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        result += flow;
        for(int i = end; i != start; i = d[i]){
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char a, b; int val;
        cin >> a >> b >> val;
        if(a == b) continue;
        link[a - 'A'].push_back(b - 'A');
        link[b - 'A'].push_back(a - 'A');
        c[a - 'A'][b - 'A'] += val;
        c[b - 'A'][a - 'A'] += val;
    }
    flow_max(0, 25);
    cout << result;
    return 0;
}
