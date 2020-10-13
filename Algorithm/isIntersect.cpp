#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
    ll x, y;
    bool operator > (const point& a) const {return this->x > a.x || (this->x == a.x && this->y > a.y);}
    bool operator <= (const point& a) const {return this->x < a.x || (this->x == a.x && this->y <= a.y);}
};
int ccw(point a, point b, point c){
    ll op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}
int isIntersect(point a, point b, point c, point d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return ab <= 0 && cd <= 0;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    cout << isIntersect(a, b, c, d);
    return 0;
}
