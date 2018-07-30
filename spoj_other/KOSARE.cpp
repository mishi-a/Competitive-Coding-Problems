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
#define FI first
#define SE second
#define MOD 1000000007
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

//**********MODULAR EXPONENTIATION******************/


using namespace std;

vector <vector<int> > v(1000006);
int n,m;

int power(int x, int y)
{
    int res = 1;      // Initialize result
    ll  p = MOD;
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res%p;
}
//parameter box index and set which stores unique element till now of chosen box
int solve(int start,set<int> s)
{
   if(start>=n)
  {
    return 0;
  }
  set <int> p = s;
  //if size of set == m then we can include or exclude remaining so ans is 2^remaining
  if(s.size() == m)
  {
    return power(2,n-1-start);
  }
  else
  {
     //include start+1 box
     for(int i=0;i<v[start].size();i++)
        s.insert(v[start][i]);
     int ans1 = solve(start+1,s)%MOD;
     //exclude start+1 box
     int ans2 =  solve(start+2,p)%MOD;
     return (ans1%MOD + ans2%MOD)%MOD;
  }
}

int main()
{
  sync;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    int k;
    cin >> k;
    for(int j=0;j<k;j++)
    {
      int x;
      cin >> x;
      v[i].pb(x);
    }
  }
  int res = 0;
  set <int> s;
  //Checking for each subset in which ith box is fixed 
  for(int i=0;i<n;i++)
  {
    for(int k=0;k<m;k++)
      s.insert(v[i][k]);
    res = (res%MOD + solve(i,s)%MOD)%MOD;
    s.clear();
  }
  cout << res%MOD << endl;
}

