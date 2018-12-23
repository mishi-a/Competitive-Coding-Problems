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

const int MAX = 2e5;
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
ll x1[MAX],x2[MAX],y2[MAX];
ll px1[MAX],py1[MAX],px2[MAX],py2[MAX];
ll sx1[MAX],sy1[MAX],sx2[MAX],sy2[MAX];
int main()
{
  ll y1[MAX];
  sync;
  ll n;
  cin >> n;
  for(int i=0;i<n;i++)
  	cin >> x1[i] >> y1[i]  >> x2[i] >> y2[i];

  px1[0]=x1[0],py1[0]=y1[0],px2[0]=x2[0],py2[0]=y2[0];
  for(int i=1;i<n;i++)
  {
  	px1[i] = max(px1[i-1],x1[i]);
  	py1[i] = max(py1[i-1],y1[i]);
  	px2[i] = min(px2[i-1],x2[i]);
  	py2[i] = min(py2[i-1],y2[i]);
  }
  sx1[n-1]=x1[n-1],sy1[n-1]=y1[n-1],sx2[n-1]=x2[n-1],sy2[n-1]=y2[n-1];
  for(int i=n-2;i>=0;i--)
  {
  	sx1[i] = max(sx1[i+1],x1[i]);
  	sy1[i] = max(sy1[i+1],y1[i]);
  	sx2[i] = min(sx2[i+1],x2[i]);
  	sy2[i] = min(sy2[i+1],y2[i]);
  }
  if(px1[n-1] <= px2[n-1] && py1[n-1] <= py2[n-1] )
  	cout << px1[n-1] << " " << py1[n-1] << endl;
  else if(px1[n-2] <= px2[n-2] && py1[n-2] <= py2[n-2])
  	cout << px1[n-2] << " " << py1[n-2] << endl;
  else if(sx1[1] <= sx2[1] && sy1[1] <= sy2[1])
  	cout << sx1[1] << " " << sy1[1] << endl;
  else
  {
  	for(int i=1;i<n-1;i++)
  	{
  		int x11 = max(px1[i-1],sx1[i+1]);
  		int y11 = max(py1[i-1],sy1[i+1]);
  		int x22 = min(px2[i-1],sx2[i+1]);
  		int y22 = min(py2[i-1],sy2[i+1]);
  		if(x11 <= x22 && y11 <= y22)
  		{
  			cout << x11 << " " << y11 << endl;
  			return 0;
  		} 
  	}
  }
}
