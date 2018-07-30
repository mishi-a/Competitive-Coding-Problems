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

int cnt[1000005]={0};
int cnt1[1000005]={0};

int main()
{
  sync;
  int n;
  cin >> n;
  int mux = -1;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    mux = max(mux,a);
    cnt[a]++;
  }
  int mux1 = -1;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    cnt1[a]++;
    mux1 = max(mux1,a);
  }
  int sum1,sum2;
  for(int i=mux;i>=0;i--)
  {
    int res = 0;
    for(int j=i;j<=mux;j+=i)
    {
      if(cnt[j]>0)
      {
        res = 1;
        sum1 = j;
        
      }
    }
    if(res == 0)
       continue;
    for(int j=i;j<=mux1;j+=i)
    {
      if(cnt1[j]>0)
      {
        res = 2;
        sum2 = j;
        
      }
    }
    if(res == 2)
    {
      break;
    }
  }
  cout << sum1 + sum2 << endl;
}

