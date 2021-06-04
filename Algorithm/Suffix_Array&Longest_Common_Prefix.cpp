#include <bits/stdc++.h>
using namespace std;

string str;
int t, n;
int *g, *tg, *SA, *RANK, *LCP;
bool cmp(int x, int y){
    if(g[x] == g[y]) return g[x + t] < g[y + t];
    return g[x] < g[y];
}
void getSA(){
    t = 1;
    for(int i = 0; i < n; i++){
        SA[i] = i;
        g[i] = str[i] - 'a';
    }
    while(t <= n){
        g[n] = -1;
        sort(SA, SA + n, cmp);
        tg[SA[0]] = 0;
        for(int i = 1; i < n; i++){
            if(cmp(SA[i - 1], SA[i]))
                tg[SA[i]] = tg[SA[i - 1]] + 1;
            else
                tg[SA[i]] = tg[SA[i - 1]];
        }
        for(int i = 0; i < n; i++) g[i] = tg[i];
        t <<= 1;
    }
}
void getLCP(){
    for(int i = 0; i < n; i++)
        RANK[SA[i]] = i;
    int len = 0;
    for(int i = 0; i < n; i++){
        int k = RANK[i];
        if(k){
            int j = SA[k - 1];
            while(str[j + len] == str[i + len]) len++;
            LCP[k] = len;
            if(len) len--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> str;
    n = str.length();
    g = new int[n + 1]; tg = new int[n + 1]; SA = new int[n + 1]; RANK = new int[n + 1]; LCP = new int[n + 1];
    getSA();
    getLCP();
    for(int i = 0; i < n; i++) cout << SA[i] + 1 << " ";
    cout << "\n" << "x ";
    for(int i = 1; i < n; i++) cout << LCP[i] << " ";
    
    return 0;
}
