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

int arr[102];

int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<2*n;i++)
  {
    cin >> arr[i];
  }
  sort(arr,arr+2*n);
  int ans = INT_MAX;
  for(int i=0;i<2*n;i++)
  {
    for(int j=i+1;j<2*n;j++)
    {int res=0;
      for(int k=0;k<2*n;k+=2)
      {
        if(k==i || k==j)
        { k--;
         continue;}
        if(k+1!=i && k+1!=j)
          res += arr[k+1]-arr[k];
        else if(k+1==i)
        {
          if(k+2!=j)
          {
            res+=(arr[k+2]-arr[k]);
            k++;
          }
          else
          { 
            res+=arr[k+3]-arr[k];
            k+=2;
          }
        }
        else
        {
          res+=arr[k+2]-arr[k];
          k++;
        }      
      }
      //cout << i << " " << j << " "<< res << endl;
      ans = min(ans,res);
    }
  }
  cout << ans << endl;
}

