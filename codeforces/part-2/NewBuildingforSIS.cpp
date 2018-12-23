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
  int n,h,a,b,k;
  cin >> n >> h >> a >> b >> k;
  for(int i=0;i<k;i++)
  {
  	int ta,fa,tb,fb;
  	cin >> ta >> fa >> tb >> fb;
  	int ans = abs(ta-tb);
  	int cur;
  	if(ta == tb)
  	{
  		cout << abs(fa-fb) << endl;
  		continue;
  	}
  	if(fa > b || fa < a)
  	{
  		ans += min(abs(a-fa),abs(b-fa));
  	} 
  	if(fa < a)
  		ans += abs(a-fb);
  	else if(fa > b)
  		ans += abs(b-fb);
  	else
  		ans += abs(fa-fb);
  	cout << ans << endl;
  }
}
