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

int freq[27][100005];
ll mod = 1e9+7;
ll fact[100005],inverse[100005];


ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result
 
    x = x % mod;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res;
}

ll prod(ll x, ll y)
{
	x%=mod,y%=mod;
	return (x*y)%mod;
}

void pre(string s)
{
	for(int i=0;i<s.size();i++)
	{
		freq[s[i]-'a'][i] = 1;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<s.size();j++)
		{
			freq[i][j] += freq[i][j-1];
		}
	}	
}

int answerQuery(int l,int r)
{
	vector<int> v;
	for(int i=0;i<26;i++)
	{
		v.pb(l==0 ? freq[i][r] : freq[i][r]-freq[i][l-1]);
	}
	int oddCnt=0;
	int sum = 0;
	for(int i=0;i<26;i++)
	{
		if(v[i]%2 == 0)
		{
			sum+=(v[i]/2);
		}
		else
		{
			sum+=((v[i]-1)/2);
			oddCnt++;
		}
	}
	ll ans = fact[sum];
	//cout << ans << endl;
	for(int i=0;i<26;i++)
	{
		if(v[i]>1)
			ans = prod(ans,inverse[v[i]/2]);
	}
	return prod(ans,oddCnt == 0 ? 1 : oddCnt);
}

int main()
{
  sync;
  fact[0] = 1;
  for(ll i=1;i<=100;i++ )
  {
  	fact[i] = (i*fact[i-1])%mod;
  	inverse[i] = power(fact[i],mod-2);
  }	
  string s;
  cin >> s;
  //cout << s.substr(71,4) << endl;;
  pre(s);

  int q;
  cin >> q;
  while(q--)
  {
  	int l,r;
  	cin >> l >> r;
  	l--,r--;
  	//if(q == 915){
  	//	cout << l << " " << r << endl;
  	cout << answerQuery(l,r) << endl;
  	//}	
  }
}
