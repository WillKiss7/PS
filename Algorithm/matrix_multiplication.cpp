#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000;
typedef long long ll;
typedef vector<vector<int>> matrix;
matrix A;
matrix operator * (const matrix &a, const matrix &b){
    ll size = a.size();
    matrix ret(size, vector<int>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++)
                ret[i][j] += a[i][k] * b[k][j];
            ret[i][j] %= MOD;
        }
    }
    return ret;
}
matrix calc(ll b){
    if(b == 1) return A;
    matrix tmp = calc(b / 2);
    if(b % 2 == 0) return tmp * tmp;
    else return tmp * tmp * A;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    ll b; cin >> b;
    A.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
    matrix ans = calc(b);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << ans[i][j] % MOD << " ";
        cout << "\n";
    }
    return 0;
}

