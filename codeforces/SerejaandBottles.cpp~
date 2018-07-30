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
set <int> s,s1;
int f[1005];
int arr[1005],arr1[1005];
int arr2[100][2];
int main()
{
  sync;
  int n,a,b;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> a >> b;
    f[a]++;
    arr2[i][0]=a;
    arr2[i][1]=b;
    arr[a]=1; 
  }
  for(int i=1;i<=n;i++)
  {
    a = arr2[i][0];
    b = arr2[i][1];
    if(a==b && f[a]!=1)
      arr1[a] = 1;
    if(a!=b)
    {
      arr1[b] = 1;
    }  
  }
  int ans=0;
  for(int i=1;i<=1000;i++)
  {
    if(arr[i]!=arr1[i])
      ans+=f[i];
  }
  cout << ans << endl;
}

