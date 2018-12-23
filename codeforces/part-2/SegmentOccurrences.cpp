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

int freq[1005];
int main()
{
  sync;
  int n,m,q;
  cin >> n >> m >> q;
  string s,t;
  cin >> s >> t;
  for(int i=0;i<=n-m;i++)
  {
  	string sub = s.substr(i,m);
  	if(sub == t)
  	{
  		freq[i]=1;
  	}
  }
  for(int i=1;i<n;i++)
  {
  	freq[i]+=freq[i-1];
  }
  for(int i=0;i<q;i++)
  {
  	int a,b;
  	cin >> a >> b;
  	a--;
  	b--;
  	if(b-m+1 <a)
  		cout << "0" << endl;
  	else
  	{
  		if(a == 0)
  			cout << freq[b-m+1] << endl;
  		else
  			cout << freq[b-m+1]-freq[a-1] << endl;
  	}
  }
}
