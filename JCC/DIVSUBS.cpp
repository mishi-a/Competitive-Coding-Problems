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

int arr[100005]={0};
ll b[100005]={0};
int n;
map <int,int> mp;
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for(int i=1;i<=n;i++)
       cin >> arr[i];
         
    for(int i=1;i<=n;i++)
       b[i]=b[i-1]+(ll)arr[i];
    mp[0]=0;
    for(int i=1;i<=n;i++)
    {
      b[i]%=n;
      if(mp.find(b[i])!=mp.end())
      {
        cout << i-mp[b[i]] << endl;
        for(ll k=mp[b[i]]+1;k<=i;k++)
          cout << arr[k] << " ";
        cout << endl;
        break;
      }
      else
       mp[b[i]]=i;
    }
    mp.clear();   
    //cout << "hi" << endl;
  }
}

