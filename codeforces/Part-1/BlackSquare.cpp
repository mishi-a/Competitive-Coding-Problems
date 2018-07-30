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
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
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
    return res;
}
*/
using namespace std;
char arr[105][105];
vector <int> v,v1;
int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> arr[i][j];
      if(arr[i][j] == 'B')
      {
       v.pb(i);
       v1.pb(j);
      }
    }
  }
  if(v.size() == 0)
  {
    cout << "1" ;
    return 0;
  }
  int cnt = 0;
  sort(v.begin(),v.end());
  sort(v1.begin(),v1.end());
  int len = v[v.size()-1]-v[0]+1;
  int wid = v1[v1.size()-1]-v1[0]+1;
  if(max(len,wid) > min(n,m))
     cout << "-1" << endl;
  else
  {
    for(int i=v[0];i<=v[v.size()-1];i++)
    {
      for(int j=v1[0];j<=v1[v1.size()-1];j++)
      {
        if(arr[i][j] == 'W')
          cnt++;
      }
    }
    if(len > wid)
    {
      cnt = cnt + len*(len-wid);
    }
    else if(wid > len)
    {
      cnt = cnt + wid*(wid-len);
    }
    cout << cnt << endl;
  }
  
  
}

