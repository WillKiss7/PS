//BOJ_11658
#include <bits/stdc++.h>
using namespace std;
int n, arr[1025][1025], seg[1024 * 4][1024 * 4], x, y, c, xs, ys, xe, ye;

int merge(int posx, int s, int e, int pos){
    if(s == e)
        return seg[posx][pos] = seg[posx * 2][pos] + seg[posx * 2 + 1][pos];
    return seg[posx][pos] = merge(posx, s, (s + e) / 2, pos * 2) + merge(posx, (s + e) / 2 + 1, e, pos * 2 + 1);
}
int seg_inity(int x, int posx, int s, int e, int pos){
    if(s == e){
        return seg[posx][pos] = arr[x][s];
    }
    return seg[posx][pos] = seg_inity(x, posx, s, (s + e) / 2, pos * 2) + seg_inity(x, posx, (s + e) / 2 + 1, e, pos * 2 + 1);
}
void seg_initx(int s, int e, int pos){
    if(s == e){
        seg_inity(s, pos, 1, n, 1);
        return;
    }
    seg_initx(s, (s + e) / 2, pos * 2);
    seg_initx((s + e) / 2 + 1, e, pos * 2 + 1);
    merge(pos, 1, n, 1);
}
int outputy(int posx, int s, int e, int pos){
    if(e < ys || ye < s) return 0;
    if(ys <= s && e <= ye) return seg[posx][pos];
    return outputy(posx, s, (s + e) / 2, pos * 2) + outputy(posx, (s + e) / 2 + 1, e, pos * 2 + 1);
}
int outputx(int s, int e, int pos){
    if(e < xs || xe < s) return 0;
    if(xs <= s && e <= xe) return outputy(pos, 1, n, 1);
    return outputx(s, (s + e) / 2, pos * 2) + outputx((s + e) / 2 + 1, e, pos * 2 + 1);
}
int updatey(int posx, int s, int e, int pos){
    if(y < s || e < y) return seg[posx][pos];
    if(s == e && s == y)
        return seg[posx][pos] += c;
    return seg[posx][pos] = updatey(posx, s, (s + e) / 2, pos * 2) + updatey(posx, (s + e) / 2 + 1, e, pos * 2 + 1);
}
void updatex(int s, int e, int pos){
    if(x < s || e < x) return;
    if(s == e && s == x){
        updatey(pos, 1, n, 1);
        return;
    }
    updatex(s, (s + e) / 2, pos * 2);
    updatex((s + e) / 2 + 1, e, pos * 2 + 1);
    updatey(pos, 1, n, 1);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];
    seg_initx(1, n, 1);
    for(int i = 0; i < m; i++){
        int w; cin >> w;
        if(w == 0){
            cin >> x >> y >> c;
            int tmp = c;
            c = c - arr[x][y];
            arr[x][y] = tmp;
            updatex(1, n, 1);
        }else{
            cin >> xs >> ys >> xe >> ye;
            cout << outputx(1, n, 1) << "\n";
        }
    }
    return 0;
}
