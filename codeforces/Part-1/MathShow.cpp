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

int arr[50];

int main()
{
  sync;
  int n,k,m,t=0;
  cin >> n >> k >> m;
  int mm = m;
  for(int i=0;i<k;i++)
  {
    cin >> arr[i];
    t+=arr[i];
  }
  sort(arr,arr+k);
  int ans=0;
  for(int i=0;i<k;i++)
  {
    if(m/arr[i]>=n)
      m -= arr[i]*n,ans+=n;
    else
    {
      ans += (m/arr[i]);
      break;
    }   
  }
  //cout << ans << endl;
  int cscore = 0;
  for(int i=1;i<=n;i++)
  {
     int time = mm;
     int cscore = 0;
     cscore+=(k+1)*i;

     time-=(i)*t;
     if(time<0)
      break;
     int nn = n-i;
     //cout << nn << " " << k << " " << time << " " << cscore << endl; 
     for(int j=0;j<k;j++)
     {
        if(time/arr[j]>=nn)
            time -= arr[j]*nn,cscore+=nn;
        else
        {
            cscore += (time/arr[j]);
            break;
        }   
     } 
     //cout << cscore << endl;
     ans = max(ans,cscore);
     
  } 
  cout << ans << endl;
}
