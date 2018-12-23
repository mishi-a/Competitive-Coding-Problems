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
unordered_map<int,int> freq;
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	std::vector<int> v;
  	int n,k;

  	cin >> n >> k;
  	if(k>2e7)
  	{
  		cout << "0" << endl;
  		continue;
  	}
  	for(int i=0;i<n;i++)
  	{
  		int a;
  		cin >> a;
  		if(freq[a]==0)
  			v.pb(a);
  		freq[a]++;
  	}
  	ll ans = 0;
  	for(int i=0;i<v.size();i++)
  	{
  		if(freq[v[i]])
  		{
  			int val = k-v[i];
  			if(val<=0)
  				continue;
  			if(val == v[i])
  			{
  				ans += ((freq[v[i]]*1LL*(freq[v[i]]-1))/2);
  				freq[v[i]]=0;
  			}
  			else
  			{
  				ans += (freq[v[i]]*1LL*freq[val]);
  				freq[v[i]] = 0;
  				freq[val]=0;
  			}
  		}
  	}
  	cout << ans << endl;
  	freq.clear();
  }
}
