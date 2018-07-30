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

vector <int > v;
int mark[400005] = {0};
int main()
{
  sync;
  int n;
  cin >> n;
  int cnt = 1;
  int x =0;
  int index = -1;
  int res = 0;
  for(int i=0;i<2*n;i++)
  {
    string s;
    cin >> s;
    if(s == "add")
    {
      int n;
      cin >> n;
      v.pb(n);
      x = v.size();
    } 
    else
    {
      while(true)
      {
        if(index == x-1)
        {
          break;
        }
        if(v[x-1]!=cnt && mark[v[x-1]] == 0)
        {
          res++;
          index = x-1;
          break;
        }
        else if(v[x-1] == cnt)
        {
          mark[v[x-1]] = 1;
          break;
        }
        else
          x--;
      }
      cnt++;
    }
  }
  cout << res << endl;
}

