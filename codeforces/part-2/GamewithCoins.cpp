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
int arr[MAX];
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)cin >> arr[i];
  if(n<=2 || (n%2 == 0 )) 
  {
  	cout << -1 << endl;
  	return 0;
  }
  int ans = 0;
  for(int i=1;i<=n;i++)
  {
  	if(2*i+1>n) break;
  	int l = 2*i,r=2*i+1;
  	if(2*l+1>n)
  	{
  		ans += max(arr[i],max(arr[l],arr[r]));
  		arr[i]=arr[l]=arr[r]=0;
  	}
  	else if(2*r+1 > n)
  	{
  		ans += max(arr[i],arr[r]);
  		arr[l] = max(0,arr[l]-max(arr[i],arr[r]));
  		arr[i] = arr[r] = 0;
  	}
  	else
  	{
  		ans+=arr[i];
  		arr[l] = max(0,arr[l]-arr[i]);
  		arr[r] = max(0,arr[r]-arr[i]);
  		arr[i] = 0;
  	}
  	cerr << ans << endl;
  	for(int i=1;i<=n;i++)
  		cout << arr[i] << " ";
  	cout << endl;
  }
  cout << ans << endl;
}
