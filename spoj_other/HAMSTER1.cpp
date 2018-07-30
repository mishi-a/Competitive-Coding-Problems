/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>

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
int k1,k2,v;
double g = 10.0;
double res;
double func(double x)
{
   return (k2*(v*v)*sin(x)*sin(x))/(2*g) + (k1*v*v*sin(2.0*x))/g;
}

double ts(double l,double r)
{
  for(int i=0;i<200;i++)
  {
    double l1 = (2.0*l+r)/3.0;
    double l2 = (l+2.0*r)/3.0;
    if(func(l1)>func(l2))
      r = l2;
    else
      l = l1;
  }
  res = l;
  return func(l);
  
}

void solve()
{
  cin >> v >> k1 >> k2;
  double ans = ts(0.0,0.5*PI);
  cout << fixed << setprecision(3);
  cout<<res << " " << ans<< endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
}

