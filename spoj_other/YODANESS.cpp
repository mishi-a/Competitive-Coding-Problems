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
vector <string> v;
int arr1[30005];
int arr[30005] = {0};
map <string,int> mp;
int n;
long long  getsum(int index)
{
 index+=1;
 long long  sum = 0;
 while(index > 0)
 {
   sum+=arr[index];
   index -=(index&(-index));
 }
 return sum;
}
 
void update(int index,int val)
{
  index+=1;
  while(index <= n)
  {
    arr[index]+=val;
    index +=(index & (-index));
  }
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {

    cin >> n;
    memset(arr1,1,sizeof(arr1));
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      v.pb(s);
    }
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      mp.insert({s,i});
    }
    ll res = 0;
    for(int i = 0;i<n;i++)
    {
      update(i,1);
    }
    for(int i=0;i<n;i++)
    {
      res += getsum(((mp.find(v[i]))->second)-1);
      update((mp.find(v[i])->second),-1);
    }
    cout << res << endl;
    mp.clear();
    memset(arr,0,sizeof(arr));
    v.clear();
  }
}

