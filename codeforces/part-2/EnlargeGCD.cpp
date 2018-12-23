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

const int MAX = 3e5+7;
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
int arr[MAX],used[15000007],pre[15000007];
int main()
{
  sync;
  int n;
  cin >> n;
  int gcd;
  for(int i=0;i<n;i++)
  {
  	cin >> arr[i];
  	pre[arr[i]]++;
  	if(i == 0)gcd = arr[0];
  	else
  	gcd = __gcd(arr[i],gcd);
  }
  ll ans = n;
  for(int i=gcd+gcd ;i<=15000000;i+=gcd)
  {
  	if(used[i] == 1)continue;
  	ll cnt = 0;
  	for(int j=i;j<=15000000;j+=i)
  	{
  		if(pre[j])	
  		{
  			cnt+=pre[j];
  		}
  		used[j] = 1;
  	}	
  	ans = min(ans,n-cnt);
  }
  if(ans == n)
  	cout << "-1" << endl;
  else
  	cout << ans << endl;
}
