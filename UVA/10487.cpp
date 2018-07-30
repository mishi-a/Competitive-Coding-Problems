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
int arr[1005];
int main()
{
  sync;
  int cnt = 0;
  while(1)
  {
    int n;
    cnt++;
    cin >> n;
    if(n==0)
      break;
    cout << "Case " << cnt << ":" << endl;
    for(int i=0;i<n;i++)
    {
      cin >> arr[i];
    }
    int m;
    cin >> m;
    
    for(int i=0;i<m;i++)
    {
      int q;
      cin >> q;
      int l=0,r=n-1;
      int curr = INT_MAX;
      while(l<r)
      {
        if(arr[l]+arr[r] > q)
        {
          if(fabs(arr[l]+arr[r]-q)<fabs(curr-q))
            curr = arr[l]+arr[r];
          r--;
        }
        else if(arr[l]+arr[r] < q)
        {
          if(fabs(arr[l]+arr[r]-q)<=fabs(curr-q))
            curr = arr[l]+arr[r];
          //cout << curr << endl;
          l++;
        }
        else
        {
          curr = q;
          break;
        }
      }
      cout << "Closest sum to " << q << " is " << curr << endl;
    } 
  }
}
        
