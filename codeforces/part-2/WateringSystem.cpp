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
vector <int> v;
int main()
{
  sync;
  int n,a,b,sum=0;
  cin >> n >> a >> b;
  int x;
  for(int i=0;i<n;i++)
  {
  	cin >> x;
  	v.pb(x);
  	sum+=x;
  }
  int f = v[0];
  int h = 0;
  int flag = 0;
  sort(v.begin()+1,v.end(),greater<int>());
  for(int i=1;i<n;i++)
  {
  	double curr = ((f*1.0)/sum)*a;
  	if(curr-b>=0)
  	{
  		flag = 1;
  		break;
  	}
  	else
  	{
  		h++;
  		sum-=v[i];
  	}
  }
  if(flag == 1)
  {
  	cout << h << endl;
  }
  else
  {
  	cout << n-1 << endl;
  }
}
