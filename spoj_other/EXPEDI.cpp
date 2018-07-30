#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define pii pair <int,int> 
using namespace std;

void solve()
{
  int n;
  cin >> n;
  list <pii > v;
  priority_queue <int> pq;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }
  int l,p;
  cin >> l >> p;
  list <pii > :: iterator itr;
  for(itr =v.begin();itr!=v.end();itr++)
  {
    itr -> first = l - (itr -> first);
    if(itr->first < 0 )
     { itr = v.erase(itr);
       itr--;}
  }
  v.sort();
  /*for(itr =v.begin();itr!=v.end();itr++)
  {
    cout << (*itr).first << " " << (*itr).second << endl;
  }*/
  int dist = p;
  int res = 0;
  while(dist < l)
  {
    for(itr = v.begin();itr!=v.end();)
    {
      if(itr->first <=dist )
      {   
        pq.push(itr->second);
        itr = v.erase(itr);
      }
      else
        break;
    }
    int x;
    if(pq.empty())
    {
        cout << -1 << endl ;return;
    }
    else
    {
       x = pq.top();
       pq.pop();
    }  
    dist += x;
    //cout << dist << "dist " << endl;
    res++;
  }
  cout << res << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}
