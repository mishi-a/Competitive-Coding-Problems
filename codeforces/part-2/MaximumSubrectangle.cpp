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

int a[2005],b[2005];
bool acompare(pii a,pii b)
{
	if(a.FI < b.FI)
		return true;
	else if(a.FI == b.FI)
		return a.SE > b.SE;
}
int arr[4000005];
int main()
{
  sync;
  int n,m;
  ll x;
  cin >> n >> m;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<m;i++) cin >> b[i];
  for(int i=1;i<m;i++) b[i]+=b[i-1];
  for(int i=1;i<n;i++) a[i]+=a[i-1];	
  cin >> x;	
  for(int i=0;i<m;i++)
  	for(int j=i;j<m;j++)
  	{
  		arr[i == 0 ? b[j] : b[j]-b[i-1]] = max(j-i+1,arr[i == 0 ? b[j] : b[j]-b[i-1]]);
  	}
  for(int i=1;i<=4000001;i++)
  	arr[i] = max(arr[i],arr[i-1]);
  int ans = -1;
  for(int i=0;i<n;i++)
  	for(int j=i;j<n;j++)
  	{
  		int sum = i == 0 ? a[j] : a[j]-a[i-1];
  		int k = x/sum;
  		if (k > 4e6)
  		{
  			ans = max(ans,(j-i+1)*arr[4000000]);
  		}
  		else
  		//cerr << k << endl;
  		ans = max(ans,(j-i+1)*arr[k]);
  	}
  cout << ans << endl;	
 
}
