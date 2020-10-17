#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001 * 2
string str;
int A[MAXN];
void manachers(string S, int N){
    int r = 0, p = 0;
    for (int i = 0; i < N; i++){
        if (i <= r) A[i] = min(A[2 * p - i], r - i);
        else A[i] = 0;
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1])
            A[i]++;
        if (r < i + A[i]){
            r = i + A[i];
            p = i;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    char tmp;
    while(cin >> tmp){
        str += '#';
        str += tmp;
    }
    str += '#';
    int len = str.size();
    manachers(str, len);
    int ans = -1;
    for (int i = 0; i < len; i++)
        ans = max(ans, A[i]);
    cout << ans;
    return 0;
}

