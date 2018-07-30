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
  int n,pos,l,r,ans;
  cin >> n >> pos >> l >> r;
  if(l==1&&r==n)
  {
  	cout << "0" << endl;
  	return 0;
  }
  if(l==1)
  {
  	if(pos<=r)
  		ans = r-pos+1;
  	else
  		ans = pos-r+1;
  	cout << ans << endl;
   return 0;
  }
  if(r==n)
  {
  	if(pos>=l)
  		ans = pos-l+1;
  	else
  		ans = l-pos+1;
  	  cout << ans << endl;
   return 0;
  }
  
  if(pos>=l && pos<=r)
  	ans = 2+min((pos-l),(r-pos))+(r-l);
  else if(pos<l)
  	ans = (l-pos)+(r-l)+2;
  else
  	ans = (pos-r)+(r-l)+2;
  cout << ans << endl;
}
