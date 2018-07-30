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

int arr[105],arr1[105];
vector<double> v;

int main()
{
  sync;
  int f,r;
  while(1)
  {
  	  cin >> f;
  	  if(f==0)
  	  	break;
  	  cin >> r;
	  for(int i=0;i<f;i++)
	  	cin >> arr[i];
	  for(int i=0;i<r;i++)
	  	cin >>arr1[i];

	  for(int i=0;i<r;i++)
	  {
	  	for(int j=0;j<f;j++)
	  	{
	  		v.pb((arr1[i]*1.0)/arr[j]);
	  	}
	  }
	  sort(v.begin(),v.end());
	
	  double mux = -1;
	  for(int i=1;i<f*r;i++)
	  {
	  	if(v[i]>=v[i-1])
	  	{
	  		if(v[i]/v[i-1]>=mux)
	  			mux = v[i]/v[i-1];
	  	}
	  }
	  printf("%.2lf\n",mux);	
	  v.clear();
  }
  
}
