#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  
  if( n < (int)(ceil(m/2.0)-1) || n > m+1)
  {
    cout << "-1" ;
    return 0;
  }
  if(n==m+1)
  {
    cout << "0";
    while(m--)
    {
      cout << "10" ;
    }
    return 0;
  }
  list <int> l (m,1);
  list <int> :: iterator itr;
  for(itr = l.begin();itr!=l.end() && n>0;)
  {
    if(m == n)
    {
      ++itr;
      l.insert(itr,0);
      m--;
      n--;
    }
    else
    {
      ++itr;
      ++itr;
      l.insert(itr,0);
      m-=2;
      n-=1;
    }
  }
  for(itr = l.begin();itr!=l.end();itr++)
  {
    cout << *itr;
  }
}
