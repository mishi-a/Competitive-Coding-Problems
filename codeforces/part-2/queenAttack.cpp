#include <bits/stdc++.h>

using namespace std;
set<pair<int,int> > s;
int main()
{
    int n,k;
    cin >> n >> k;
    int rq,cq;
    cin >> rq >> cq;
    rq = n+1-rq;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin >> a >> b;
        s.insert({n+1-a,b});
    }
    int ans = 0;
    int r0 = rq-1;
    int c0 = cq-1;
    while(r0 > 0 && c0 > 0)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        r0--;
        c0--;
    }
    //cout << ans << endl;
    r0 = rq+1,c0 = cq+1;
    while(r0 <= n && c0 <= n)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        r0++;
        c0++;
    }
    //cout << ans << endl;
    r0 = rq+1,c0 =cq-1;
    //cout << r0 << " " << c0 << endl;
    while(r0<=n && c0>0)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        r0++;
        c0--;
    }
    //cout << ans << endl;
    r0 = rq-1,c0 = cq+1;
    while(r0>0 && c0 <=n)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        r0--;
        c0++;
    }
    //cout << ans << endl;
    r0 = rq-1;
    c0 = cq;
    while(r0 > 0)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        r0--;
    }
    //cout << ans << endl;
    r0 = rq+1;
    c0 = cq;
    while(r0<=n)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        r0++;
    }
    //cout << ans << endl;
    r0 = rq;
    c0 = cq - 1;
    while(c0 > 0)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        c0--;
    }
    //cout << ans << endl;
    r0 = rq;
    c0 = cq+1;
    while(c0<=n)
    {
        if(s.find({r0,c0})==s.end())
        {
            ans++;
        }
        else
            break;
        c0++;
    }
        
    cout << ans << endl;
    
}