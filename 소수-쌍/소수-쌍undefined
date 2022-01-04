#include <bits/stdc++.h>
using namespace std;
int arr[53], a[53], b[53], n;
bool sosu[2003], visit[53];
vector<int> ans;
bool dfs(int x)
{
    if(visit[x]) return false;
    visit[x] = true;
    for(int i = 1; i <= n; i++)
    {
        if(sosu[arr[x] + arr[i]]) continue;
        if(b[i] == -1 || dfs(b[i]))
        {
            a[x] = i;
            b[i] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sosu[1] = true;
    for(int i = 2; i * i <= 2000; i++)
    {
        if(sosu[i]) continue;
        for(int j = i * i; j <= 2000; j += i)
            sosu[j] = true;
    }
    for(int i = 2; i <= n; i++)
    {
        if(!sosu[arr[1] + arr[i]])
        {
            int cnt = 0;
            memset(a, -1, sizeof(a));
            memset(b, -1, sizeof(b));
            a[1] = i;
            b[i] = 1;
            for(int j = 2; j <= n; j++)
            {
                memset(visit, false, sizeof(visit));
                visit[1] = true;
                if(dfs(j)) cnt++;
            }
            if(cnt + 1 == n) ans.push_back(arr[i]);
        }
    }
    if(ans.empty())
        cout << -1;
    else
    {
        sort(ans.begin(), ans.end());
        for(auto output : ans)
            cout << output << " ";
    }
    return 0;
}
