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

ll arr[MAX],occupied[MAX];
int main()
{
  sync;
  ll n,m,l;
  cin >> n >> m >> l;
  for(int i=1;i<=n;i++) cin >> arr[i];

  ll ans = 0;	
  for(int i=1;i<=n;i++)
  {
  	ll start = i,end = -1;
  	for(int j=i;arr[j]>l;j++)
    {
    	occupied[j] = 1;
  		end = j;
    }
  	if(end!=-1)
  	{
  		ans++;
  		i = end;
  	}
  }
  // for(int i=0;i<=n;i++)
  // 	cerr << occupied[i] << " ";
  // cerr << endl;
  // cerr << ans << endl;
  for(int i=0;i<m;i++)
  {
  	
  	int q;
  	cin >> q;
  	if(q == 0)
  	{
       cout << ans << endl;
  	}
  	else
  	{
  		ll a,b;
  		cin >> a >> b;
  		arr[a]+=b;
  		if(arr[a]>l){
  		if(occupied[a] ==0)
  		{
  			if(occupied[a-1] == 0 && occupied[a+1] == 0)
  			{
  				ans++;
  				occupied[a]=1;
  			}
  			else if(occupied[a-1] == 1 && occupied[a+1] == 1)
  			{
  				ans--;
  				occupied[a]=1;
  			}
  			else
  				occupied[a] =1;
  		}
  	   }
  	 //   for(int i=0;i<=n;i++)
  	 //  cerr << occupied[i] << " ";
    // cerr << endl;
  	}
  }

}
