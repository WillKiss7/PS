int parent[10003];
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void uf(int a, int b){
    a = find(a); b = find(b);
    if(a > b) swap(a, b);
    parent[b] = a;
}
