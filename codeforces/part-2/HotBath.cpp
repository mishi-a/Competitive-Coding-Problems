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
  ll t1,t2,x1,x2,t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  ll y1 = x1;
  long double ans = 1e8;
  ll y11 = 0,y22 = 0;
  if(t1 == t0 && t2 == t0 )
  {
    cout << x1 << " " << x2 << endl;
    return 0;
  }
  else if(t1 == t0)
  {
    cout << x1 << " " << 0 << endl;
    return 0;
  }
  else if(t2 == t0)
  {
    cout << 0 << " " << x2 << endl;
    return 0;
  }
  while(y1>0)
  {
  	ll y2 = ceil(((t1-t0)*y1)/((t0-t2)*1.0));
  	//cout << y2 << endl;
    if(y2>x2)
  	{	y1--;
  		continue;
  	}
  	long double val = (t1*y1 + t2*y2)/((y1+y2)*1.0);
  	if(abs(val-ans) <= 1e-6)
  	{
  		ans = val;
  		if(y1+y2 > y11+y22)
  		{
  			y11 = y1;
  			y22 = y2;
  		}
  	}
  	else if(val-t0 < ans-t0)
  	{
  		ans = val;
  		y11 = y1;
  		y22 = y2;
  	}
  	//cout << y11 << " " << y22 << " " << val <<  endl;
  	y1--;
  }
  if(y11 == 0 && y22 ==0)
  	cout << 0 << " " << x2 << endl;
  else
    cout << y11 << " " << y22 << endl;
}
