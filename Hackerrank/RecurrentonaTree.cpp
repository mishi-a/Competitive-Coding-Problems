#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

vector <vector <long long> > v(200005);
long long vis[200005] = {0};
long long dist[200005] = {0};
long long c[200005] = {0};
long long res1 = 0;
long long fast_fib(long long int n,long long int ans[])
{
    long long int a,b,c,d;
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return 0;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
    //cout << "hi" << " " << n << " " << ans[0] << endl;
    return ans[0];
}
void dfs(long long node)
{
    vis[node] = 1;
     long long int res[2]={0};
    res1 = (res1 + fast_fib(dist[node]+1,res))%MOD;
    for(long long i=0;i<v[node].size();i++)
    {
        if(vis[v[node][i]] == 0)
        {
            dist[v[node][i]] = dist[node]+c[v[node][i]];
            dfs(v[node][i]);
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long n;
    cin >> n;
    for(long long i=1;i<n;i++)
    {
        long long a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(long long i=1;i<=n;i++)
        cin >> c[i];
    long long ans = 0;
    for(long long i=1;i<=n;i++)
    {
        
        dist[i] = c[i];
        dfs(i);
        memset(vis,0,sizeof(vis));
        memset(dist,0,sizeof(dist));
    }
    cout << res1 << endl;
    return 0;
}

