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
ll arr[1005][3];
vector<pair<ll,ll> > v;
ll seq[6000005];
int main()
{
  sync;
  ll n,q;
  cin >> n >> q;
  for(ll i=0;i<n;i++)
  	cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  for(ll i=0;i<n;i++)
  	for(ll j=i+1;j<n;j++)
  	{
  		ll xdiff = arr[i][0]-arr[j][0];
  		ll ydiff = arr[i][1]-arr[j][1];
  		double dist = sqrt(xdiff*xdiff + ydiff*ydiff );
  		double mun = (dist-arr[i][2]-arr[j][2]);
  		ll mux = floor(dist+arr[i][2]+arr[j][2]);
  		if(mun< 0 && dist < fabs((arr[i][2]-arr[j][2])))
  		{
  			mun = (max(arr[i][2],arr[j][2])-(dist+min(arr[i][2],arr[j][2])));
  		}
  		else if(mun <0 && dist >= fabs(arr[i][2]-arr[j][2]))
  		{
  			mun = 0;
  		}
  		v.pb({ceil(mun),mux});
  	}
  for(int i=0;i<v.size();i++)
  {
  	seq[v[i].FI]++,seq[v[i].SE+1]--;
  }
  for(int i=1;i<6e6;i++)
  	seq[i]+=seq[i-1];
  while(q--)
  {
  	int k;
  	cin >> k;
  	cout << seq[k] << endl;
  }
}
