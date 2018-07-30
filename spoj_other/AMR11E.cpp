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

vector <int> v(10005,0);
int prime[10005] = {0};
vector <int> v1;
void pre()
{
  for(int i = 2;i<5001;i++)
  {
    if(prime[i] == 0) 
    {
      for(int j=2*i;j<10001;j+=i)
      {
        prime[j] = 1;
        
        v[j]++;
      }
    }
  }
  v1.pb(-1); 
  for(int i=1;i<10001;i++)
  {
   
    if(v[i] >= 3)
    {
      v1.emplace_back(i);
    }
  }
}

int main()
{
  pre();
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    cout << v1[n] << endl;
  }
}

