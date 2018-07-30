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
  int t;
  cin >> t;
  while(t--)
  {
  	int x,y,z,a,b,c;
  	cin >> x >> y >> z >> a >> b >> c;
  	vector <int> v;
    v.pb(x),v.pb(y),v.pb(z);
    sort(v.begin(),v.end());
  	int ans = (x+y+z)*a;
  	if(x==y==z)
  	{
  		ans = min(ans,c*x);
  		if(x%2==0)
  			ans = min(ans,(3*x*b)/2);
  	}
  	//cout << ans << endl;
    if(1)
    {
      
      int x1 = v[0],x2=v[1],x3 = v[2];
      x3 = x3-(x2-x1);
      x2 = x1;
      if(x3>2*x1)
      	ans = min(ans,(x3-2*x1)*a+(v[1]-v[0]+2*x1)*b);
      else if(x3 == 2*x1)
      	ans = min(ans,(v[1]-x1+x3)*b);
      else
      {
      	if(x3%2==0)
      	{
      		ans = min(ans,(v[1]-x1+(x1-(x3/2))+x3)*b);
      	}
      	else
      	{
      		x3--;
      		ans = min(ans,a+(v[1]-x1+(x1-(x3/2))+x3)*b);
      		ans = min(ans,c+(v[1]-x1+(x1-1-(x3/2))+x3)*b);

      	}
      }
    } // 	cout << ans << endl;

    ////
    ans = min(ans,c*v[0]+(v[0]+v[1]+v[2]-3*v[0])*a);//cout << ans << endl;
    ans = min(ans,c*v[0]+(v[1]-v[0])*b+(v[2]-v[1])*a);//cout << ans << endl;
    int k = v[0]+v[1]-v[2];
    int x1 = v[0];
    int x2 = v[1];
    int x3 = v[2];
    if(x3-k-(x2-x1)==2*(x1-k) && k>=0)
     ans = min(ans,(c*k+(x2-x1+x3-(k+x2-x1))*b));//cout << ans << endl;
    cout << ans << endl;
  }
}
