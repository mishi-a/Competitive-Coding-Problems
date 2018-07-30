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
ll arr[105][105];
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    ll n;
    ll a,b;
    cin >> n;
    ll flag = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin >> arr[i][j];
        if(arr[i][j] == 0)
        {
          a = i;
          b = j;
        }
      }
    }
    if(n==1)
    {
      cout << "1" << endl;
      continue;
    }
    ll sum =0,sum1=0;
    for(int i=0;i<n;i++)
    {
      sum = sum + arr[a][i];
      sum1 = sum1+arr[(a==0)?1:0][i];
    }
    arr[a][b] = (sum1-sum);
    ll rsum=0,csum=0,dsum=0;
    for(int i=0;i<n;i++)
    {
      rsum=0;
      for(int j=0;j<n;j++)
      {
        rsum+=arr[i][j];
      }
      if(rsum != sum1)
      {
        flag = 1;
        break;
      }
    }
    for(int i=0;i<n;i++)
    {
      rsum=0;
      for(int j=0;j<n;j++)
      {
        rsum+=arr[j][i];
      }
      if(rsum != sum1)
      {
        flag = 1;
        break;
      }
    }
    rsum = 0;
    for(int i=0;i<n;i++)
    {
      rsum += arr[i][i];
      csum += arr[i][n-1-i];
    }
    if(rsum!=sum1 || csum!=sum1)
     flag = 1;
    flag == 0 ?(arr[a][b]==0?cout << "-1" : cout << arr[a][b]) : cout << "-1";
    cout << endl;
  }
}

