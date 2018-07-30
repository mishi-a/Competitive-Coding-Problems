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

struct node
{
 string s;
 int a;
 int b;
};

vector <node> v;

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int d;
    cin >> d;
    for(int i=0;i<d;i++)
    {
      node* x = new node;
      cin >> x->s >> x->a >> x->b;
      v.pb(*x);
    }
    int q;
    cin >> q;
    while(q--)
    {
      int p;
      cin >> p;
      string res;
      int cnt= 0;
      for(int i=0;i<v.size();i++)
      {
        if(p>=v[i].a && p<=v[i].b)
        {
          cnt++;
          if(cnt == 1)
            res = v[i].s;
          else
          {
            res = "UNDETERMINED" ;      
            break;
          }
        }
      }
      if(cnt == 0)
           res = "UNDETERMINED" ;
       cout << res << endl;
    }  
    if(t>0)
      cout << endl;
    v.clear();
  }
}

