/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

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

vector<ll> v;
set<ll> s;
ll res;
void findDiv(ll a,ll b)
{
	for(ll i=2;i*i<=a;i++)
	{
		if(a%i == 0)
		{
			s.insert(i);
			s.insert(a/i);
		}
	}
	for(ll i=2;i*i<=b;i++)
	{
		if(b%i == 0)
		{
			s.insert(i);
			s.insert(b/i);
		}
	}
	s.insert(a);
	s.insert(b);
	set<ll>::iterator itr = s.begin();
	while(itr!=s.end())
	{
		v.pb(*itr);
		itr++;
	}
	res = a;
}

ll check(ll a,ll b)
{
	ll flag = 0;
	//cout << a << " " << b << endl;
	for(ll i=0;i<v.size();i++)
	{
		if(v[i]!=-1 && a%v[i]!=0 && b%v[i]!=0)
			v[i]=-1;
		else if(v[i]!=-1)
		{
			flag = v[i];
		}
	}
	if(flag==0)
		return -1;
	else
		return flag;
}

int main()
{
  sync;
  ll n;
  cin >> n;
  
  for(ll i=0;i<n;i++)
  {
  	ll a,b;
  	cin >> a >> b;
  	if(i == 0)
  	{
  		findDiv(a,b);
  	}
  	else
  	{
  		res = check(a,b);
  		if(res == -1)
  		{
  			cout << "-1" << endl;
  			return 0;
  		}
  	}
  }
  cout << res << endl;
}
