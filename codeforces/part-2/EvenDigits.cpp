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
vector <ll> v;
int main()
{
  sync;
  int t;
  cin >> t;
  int val = 1;
  while(t--)
  {
  	ll n,n1;
  	cin >> n;
  	n1 = n;
  	while(n!=0)
  	{
  		v.pb(n%10);
  		n/=10;
  	}
  	reverse(v.begin(),v.end());
  	ll ans = 0,res=0;
  	ll cnt = 0;
  	int lastOdd;
  	int flag = 0;
  	for(int i=v.size()-1;i>=0;i--)
  	{
  		if(v[i]%2==1)
  		{
  			flag = 1;
  			lastOdd = i;
  			if(v[i]==9&&i-1>=0)
  			{
  				//cout << i << endl;
  				int j=i-1;
  				v[i] = (v[i]+1)%10;
  				//cout << v[i] << endl;
  				while(j>=0 && v[j]==9&&v[j+1]==0)
  				{
  					if(j==0)
  						break;
  					else
  					{
  						v[j] = (v[j]+1)%10;
  						j--;
  					}
  				}
  				if(v[0]!=9)
  				{
  					v[j] = (v[j]+1)%10;
  				}

  			}
  		}
  		
  	}
  	//cout << lastOdd << endl;
  	if(flag)
  	{
  		if(v[lastOdd]%2!=0)
  			ans = ((v[lastOdd]+1)%10)*(ll)pow(10,v.size()-1-lastOdd);
  		else
  			ans = ((v[lastOdd])%10)*(ll)pow(10,v.size()-1-lastOdd);
  		cnt = v.size()-lastOdd;
  		for(int i=lastOdd-1;i>=0;i--)
  			ans = ans + v[i]*(ll)pow(10,cnt),cnt++;
  		ans = ans-n1;

  	}
  	//cout << ans <<endl;
  	if(v[0]==9)
  		ans = 1e17;
  	v.clear();
  	n=n1;
  	flag=0;
  	while(n!=0)
  	{
  		v.pb(n%10);
  		n/=10;
  	}
  	reverse(v.begin(),v.end());
  	for(int i=v.size()-1;i>=0;i--)
  	{
  		if(v[i]%2==1)
  		{
  			flag = 1;
  			lastOdd = i;
   		}
  		
  	}
  	if(flag )
  	{
  		res = (v[lastOdd])*(ll)pow(10,v.size()-1-lastOdd);
  		cnt = v.size()-lastOdd;
  		for(int i=lastOdd-1;i>=0;i--)
  			res = res + v[i]*(ll)pow(10,cnt),cnt++;
  		ll x = res;
  		ll a =0;
  		ll sum=0;
  		while(1)
  		{
  			if(x%10==0)
  			{
  				sum = sum + (ll)pow(10,a);
  				x/=10;
  				a++;
  			}
  			else
  				break;
  		}
  		res = n1-res+sum+1;
  	}
  	cout << "Case #"<<val<<": " << min(ans,res) << endl;
  	v.clear();
  	val++;
  }
}
	