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
  int n;
  cin >> n;
  int minl,maxr;
  int prev;
  for(int i=0;i<n;i++)
  {
    cin >> arr[i];
  }
  if(n<=2)
  {
    cout << "no" << endl;
    return 0;
  }
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1;j++)
    {
      if(max(arr[i],arr[i+1])<max(arr[j],arr[j+1]) && min(arr[i],arr[i+1])<min(arr[j],arr[j+1]) && max(arr[i],arr[i+1])>min(arr[j],arr[j+1]))
        {
         //cout << i << " " << j << endl;
        cout<<"yes";
        return 0;
        }
    }
  }
  cout << "no" << endl;
}
