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
ll arr[100005];
ll freq[100005];
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int n;
  	cin >> n;
  	ll sum = 0;
    ll mux = -1;
    for(int i=0;i<n;i++)
    	cin >> arr[i],freq[arr[i]]++,mux = max(mux,arr[i]);
    ll ans=0;

    for(int i=1;i<100005;i++)
    {
    	freq[i]+=freq[i-1];
    }
    for(int i=0;i<n;i++)
    {
    	double val = arr[i];
    	double x = 0.5;
    	double t = 0;
    	ll lidx = -1;
    	while(t <= mux)
    	{
          t = val*x;
          if(t>mux)
          	t = mux+3;
          if(lidx == -1)
          {
          	if(abs(t-(ll)t)<1e-5)
            	t--;
            ll p = t;
            ans += x;
            x+=1;
            lidx = p;
          }
          else
          {
            if(abs(t-(ll)t)<1e-5)
            	t--;
            ll p = t;
          	ans+=(ll)x*(freq[p]-freq[lidx]);
            lidx = p;
            x+=1;
          }
          //cout << x << " " << ans << endl;
    	}
    	//break;
    }
    memset(freq,0,sizeof(freq));
    cout << ans << endl;
  }
}
