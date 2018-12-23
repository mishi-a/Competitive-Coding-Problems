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

vector<ll> v[3005];

int main()
{
  sync;
  ll n,m;
  cin >> n >> m;
  ll cur = 0;
  for(ll i=0;i<n;i++)
  {
  	ll p,c;
  	cin >> p >> c;
  	if(p == 1)
  		cur++;
  	v[p].pb(c);
  }
  for(ll i=1;i<=m;i++)
  	sort(v[i].begin(),v[i].end());
  ll ans = LLONG_MAX;
  for(ll i=cur;i<=n;i++)
  {
  	vector<ll> r;
  	ll needed = i - v[1].size();
  	//cout << cur << " " << needed << endl;
  	ll flag = 0;
  	ll cst = 0;
  	ll freq[m];
  	//memset(freq,-1,sizeof(freq));
  	for(ll j=1;j<=m;j++)
  		freq[j]=-1;
  	for(ll j=2;j<=m;j++)
  	{	
  		freq[j] = v[j].size();
  		if(needed == 0)
  		{//cout << " hi";
  			flag = 1;
  			break;
  		}
  		//cout << v[j].size() << " " << i << endl;
  		if(v[j].size()>=i)
  		{
  			ll idx = v[j].size()-(i-1);
  			for(ll k=0;k<idx;k++)
  			{
  				cst+=v[j][k];
  				needed--;
  				freq[j]--;
  				if(needed == 0)
		  		{
		  			flag = 1;
		  			break;
		  		}
  			}
  			for(ll k=idx;k<v[j].size();k++)
  				r.pb(v[j][k]);
  		}
  		else
  			for(ll k =0;k<v[j].size();k++)
  				r.pb(v[j][k]);
  	}
  	if(needed == 0 && flag == 1)
  	{
  		//cout << needed << " " << flag << endl;
  		ll flag1 = 0;
  		for(ll j=2;j<=m;j++)
  		{
  			if((freq[j]!=-1 && freq[j]>=i) || (freq[j]==-1 && v[j].size()>=i))
  			{
  				//cout << j << endl;
  				flag1 = 1;
  				break;
  			}
  		}
  		if(flag1 == 0)
  			ans = min(ans,cst);
  	}
  	if(needed > 0)
  	{
  		nth_element(r.begin(),r.begin() + needed,r.end());
  		for(int j=0;j<needed;j++)
  			cst+=r[j];
  		/*cout << needed << " " << i << endl;
  		for(int k=0;k<r.size();k++)
  			cout << r[k] << " " ;
  		cout << endl;*/
  		ans = min(ans,cst);
  	}
  }
  if(ans == LLONG_MAX)
    cout << "0" << endl;
  else
    cout << ans << endl;
 }