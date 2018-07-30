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

vector <char> v;
set <char> s;
int main()
{
  sync;
  int a,b,l,r;
  cin >> a >> b >> l >> r;
  int sum = 2*a+b;
  int nl = l%sum;
  int nr = r%sum;
  v.pb('1');
  for(int i=0;i<a;i++)
  {
    v.pb(97+i);
  }
  if((r-l+1)>=(2*a+b))
  {
    {
      cout << a + 1 << endl;
    }
    return 0;
  }
  int x = min(nl,nr);
  int y = max(nl,nr);
  cout << x << " " << y << endl;
  if(x<=a && y<= a)
  {
    cout << fabs(y-x)+1;
  }
  else if(x>a && y <=a+b)
  {
    cout << "1" << endl;
  }
  else if(x>a+b && y<=2*a+b)
  {
    cout << fabs(y-x)+1;
  }
  else if(x<=a && (y>a &&y<=a+b))
  {
    cout << fabs(a-x)+1 << endl; 
  }
  else if(x<=a && (y>a+b && y<=2*a+b))
  {
    for(int i=1;i<= y-(a+b);i++)
    {
      if(i==x)
        continue;
      s.insert(97+i-1);
    }
    for(int i=x;i<=a;i++)
    {
      s.insert(97+i-1);
    }
    cout << s.size() << endl;
  }
  else if(x>a && (y>a+b && y<=2*a+b))
  {
    cout << y-(a+b)+1 << endl;
  }
  
  
}

