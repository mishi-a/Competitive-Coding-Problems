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
int arr[12000];
int main()
{
  sync;
  int n,s,h,m;
  cin >> n >> s;

  for(int i=0;i<n;i++)
  {
  	cin >> h >> m;
  	int v = 60*h+m;
  	arr[i]=v;
  //	cout << arr[i] << " ";
  }
  if(arr[0]-1>=s)
  {
  	cout << 0 << " " << 0 << endl;
  	return 0;
  }
  //cout << endl;
  for(int i=1;i<n;i++)
  {
  	if(arr[i]-arr[i-1]>=2*s+2)
  	{
  	 	int x = arr[i-1]+s+1;
  	 	cout << x/60 << " " << x%60 << endl;
  	 	return 0;
  	}
  }
  cout << ((arr[n-1]+s+1)/60) <<" " << (arr[n-1]+s+1)%60 << endl; 
}
