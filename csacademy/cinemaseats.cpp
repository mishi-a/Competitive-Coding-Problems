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

vector <int> v;
int arr[100005]={0};
int csum[100005];
int n;
bool func(int val)
{
  for(int i=0;i<=n-val;i++)
  {
    if(i==0 ? csum[i+val-1] > 1 : csum[i+val-1]-csum[i-1]>1)
      continue;
    else
    {
      if(csum[n-1]-csum[i+val-1] < (n-1-i-val+1) || csum[i-1] < i)
        return true;
    }
  }
  return false;
}
int main()
{
  sync;
  string s;
  cin >> s;
  n = s.length();
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='1')
      arr[i]=1;
    else
      v.pb(i);
  }
  for(int i=0;i<s.length();i++)
  {
    i==0 ? csum[i] = arr[i] : csum[i] = csum[i-1]+arr[i];
  }
  int res = 0;
  int l=1,r=s.length()-1;
  while(l<=r)
  {
    int mid = (l+r)/2;//cout << mid << endl;
    if(func(mid))
    {
      l=mid+1;
      res = max(res,mid);
    }
    else
    {
      r = mid-1;
    }
  }
  cout << res << endl;
}

