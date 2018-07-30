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
  ll t;
  cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    ll ans=0;
    for(ll i=0;i<s.length();)
    {
    	ll j=i+1;
    	//cout << i << endl;
    	ll start = j;
    	ll cnt=1;
    	while(j<s.length()&&s[j]==s[i])
        {
        	j++;
        	cnt++;
        }
       ans+=((cnt*(cnt-1))/2);
       //cout << ans << " " << i << " " << j << endl;
       if(i-1>=0&&j<s.length()&&s[i-1]==s[j])
       	 ans++;
       i = i+j-start+1;
    }	
    cout << ans << endl;
  }
}
