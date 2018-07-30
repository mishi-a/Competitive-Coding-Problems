/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>

/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/
using namespace std;
set <ll> s;

void primefactor(ll n)
{
  while(n%2 == 0)
  {
    n = n/2;
    s.insert(2);
  } 
  for(int i=3;i<=sqrt(n);i++)
  {
    while(n%i == 0)
    {
      s.insert(i);
      n = n/i;
    }
  }
  if(n > 2)
    s.insert(n);
}

ll power(ll x,ll y,ll p)
{
  ll ans = 1;
  while(y>0)
  {
    if(y%2 == 1)
    {
      ans = (ans%p*x%p)%p;
      y--;
    }
    y = y >>  1;
    x = (x%p*x%p)%p;
  }

  return ans%p;
}

int main()
{
  sync;
  ll n;
  cin >> n;
  primefactor(n-1);
  set <ll> :: iterator itr;
  for(ll i = 2;i<=n-1;i++)
  {
    itr = s.begin();
    while(itr!=s.end())
    {
      if(power(i,(n-1)/(*itr),n)%n == 1)
      {
        break;
      }
      itr++;
    }
    if(itr == s.end())
    {
      cout << i << " " ;
      break;
    }
  }
  ll res = n-1;
  itr  = s.begin();
  while(itr!=s.end())
  {
    res = res*(*itr-1)/(*itr);
    itr++;
  }
  cout << res << endl;
  
}

