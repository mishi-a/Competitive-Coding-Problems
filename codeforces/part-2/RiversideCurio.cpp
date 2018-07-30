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

int m[100005];
int mux[100005];
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  	cin >> m[i];
  mux[0]=m[0];
  for(int i=1;i<n;i++)
  	mux[i]=max(m[i],mux[i-1]);

  int ans = 0;
  for(int i=n-1;i>=0;i--)
  {
  	ans += max(0,(mux[i]-m[i]));
  	//cout << ans << endl;	
  }
  for(int i=0;i<n;i++)
  {
  	if(m[i]!=0)
  	{
  		int j=i-1;
  		while(j>=0&&m[j]==0)
  			j--;
  		if(m[j]!=0 && m[j+1]==0)
  		{
  			if(m[i]-m[j]>1)
  				ans+=((m[i]-m[j]-1)*(m[i]-m[j]))/2;
  		}
  		if(m[j]==0)
  		{
  			if(m[i] > 1)
  				ans+=((m[i]-1)*(m[i]))/2;
  		}
	}
  }
  cout << ans << endl;
}
 