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

int freq[105];

int main()
{
  sync;
  int n,d,a;
  cin >> n >> d;
  for(int i=0;i<n;i++)
  	cin >> a,freq[a]++;
  for(int i=1;i<=102;i++)
  	freq[i]+=freq[i-1];
  int ans = 10000;
  for(int i=100;i>=max(d,1);i--)
  {
  	if((freq[i-d]-freq[i-d-1])!=0)
  		ans = min(ans,n-(freq[i]-freq[i-d-1]));
  }
  if(ans == 10000)
  	ans=0;
  cout << ans << endl; 
}
