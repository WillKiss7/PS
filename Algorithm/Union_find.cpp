int p[10003];
int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
void uf(int a, int b){
    a = find(a); b = find(b);
    if(a > b) swap(a, b);
    p[b] = a;
}
