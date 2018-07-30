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
ll arr[505],k;
int power[505];
int v[505];
int main()
{
  sync;
  ll n;
  cin >> n >> k;
  ll mux = -1;
  for(int i=0;i<n;i++)
  	cin >> arr[i],mux = max(mux,arr[i]);
  if(k>=n)
  {
  	cout << mux << endl;
  	return 0;
  }
  int curidx = 0;
  while(1)
  {
  	if(arr[curidx]==mux)
  	{
  		cout << mux << endl;
  		return 0;
  	}
  	else
  	{
  		int flag = 0;
  		for(int j=curidx+1;j<=curidx+k-v[arr[curidx]];j++)
  		{
  			if(arr[curidx%n]<arr[j%n])
  			{
  				curidx = j;
  				v[arr[j]]=1;
  				flag = 1;
  			}
  		}
  		if(flag == 0)
  	    {
  	    	cout << arr[curidx] << endl;
  	    	return 0;
  	    }
  	}
  }
}
