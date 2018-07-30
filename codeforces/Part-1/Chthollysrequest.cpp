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

int main()
{
  sync;
  ll k,p;
  cin >> k >> p;
  ll init = 11,sum = 0;
  ll val = 11;
  ll len = 2;
  for(ll i=1;i<=k;i++)
  {
    sum+=init;
    init+=val;
    //cout << sum <<" " << init <<  endl;
    vector<ll>v;
    ll x = init;
    while(x!=0)
    {
    	v.pb(x%10);
    	x=x/10;
    }
    if(i==k)
    {
    	break;
    }
    reverse(v.begin(),v.end());
    if(v[len/2]==9 )
    {
        ll idx=(len-1)/2;
        sum+=init;
        i++;
    	while(idx>=0 && v[idx]==9)
    	{
    		v[idx]=0;
    		v[len-1-idx] =0;
    		idx--;
    	}
    	if(v[0]==0)
    	{
    		len+=2;
            val*=10;
            init = pow(10,len-1)+1;
    	}
    	else
    	 {
    	 	v[idx]++;
    	    v[len-1-idx]++;
    	    ll cnt = 0;
    	    init=0;
    	    for(int i=len-1;i>=0;i--)
    	    {
              init +=(pow(10,cnt)*v[i]);
              cnt++;
    	    }              
    	}
    }
    //cout << init << endl;
  }
  cout << sum%p << endl;
}
