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

set <int> s;

void pf(int n)
{
  while(n!=0)
  {
    if(n%2 == 0)
    {
     n = n/2;
     s.insert(2);
    }
    else
     break;
  }
  for(int i=3;i<=sqrt(n);i++)
  {
      while(n!=0)
      {
        if(n%i == 0)
        {
          n = n/i;
          s.insert(i);
        }
        else
          break;    
      }
  }

  if(n > 2)
    s.insert(n);
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    pf(n);
    set <int> :: iterator itr;
    itr = s.begin();
    int ans = n;
    while(itr!=s.end())
    {
      ans = (ans/(*itr))*(*itr-1);
      itr++;
    } 
    cout << ans << endl;
    s.clear();
  }
}

