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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
ll arr[505];
//can be of form pq,p2,p3,p4
ll cubeRoot(ll num)
{
	ll l= 1,r = 2e6;
	ll res = 0;
	while(l<=r)
	{
		ll mid = (l+r)/2;
		if(mid*mid*mid <= num )
		{
			res = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	return res;
}
vector<ll> v;
int fact[505];
map<ll,ll> mp,mp1;

ll mod = 998244353;

ll mult(ll num,ll p , ll q)
{
	if(p == 1)
	{
		num = (num*q)%mod;
	}
	else
	{
		num = (num*(q+1))%mod;
	}
	//cerr << num << endl;
	return num%mod;
}

int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> arr[i];
  for(int i=0;i<n;i++)
  {
  	ll b = cubeRoot(arr[i]);
  	//cerr << b << endl;
  	ll c = sqrt(arr[i]);
  	if(b*b*b == arr[i])
  	{
  		mp[b]+=3;
  	}
  	else if(c*c == arr[i])
  	{
  		ll d = sqrt(c);
  		if(d*d == c)
  		{
  			mp[d]+=4;
  		}
  		else
  			mp[c]+=2;
  	}
  	else
  	{
  		//v.pb(arr[i]);
  		fact[i] = 1;
  	}	
  }
  //cerr << v[0] << " " << v[1] << endl;
  for(int i=0;i<n;i++)
  {
  	int flag = 0;
  	if(fact[i] == 0) continue;
  	for(int j=0;j<n;j++)
  	{
  		if(i == j) continue;
  		if(arr[i] == arr[j]) continue;
  		ll x = __gcd(arr[i],arr[j]);
  		//cerr << x << endl;
  		if(x!=1)
  		{
  			flag = 1;
  			mp[x]+=1;
  			mp[arr[i]/x]+=1;
  			break;
  		}
  	}
  	if(flag == 0)
  		{
  			mp1[arr[i]]++;

  			//cerr << "hi "  << arr[i] << endl;
  		}	

  }
  ll ans = 1;
  for(auto it = mp.begin();it!=mp.end();it++)
  {
  	     //cerr << it->FI << "  " << it->SE << endl;
  		ans = mult(ans,it->FI,it->SE);
  }
  //cerr << ans << endl;
  for(auto it = mp1.begin();it!=mp1.end();it++)
  {
  	    cerr << it->FI << "  " << it->SE << endl;
  		ans = mult(ans,1,((it->SE)+1)*((it->SE)+1));
  }
  cout << ans << endl;
}
