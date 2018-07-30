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
#define MAXN   100001
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
// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed

 
// stores smallest prime factor for every number
int spf[MAXN];
int dp[MAXN];
int pre[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> Factor(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int cal (int idx)
{
  set <int> s;
  vector <int> p = Factor(v[idx]);
  for(int i=0;i<p.size();i++)
  {
    s.insert(p[i]);
  }
  if(s.size() < p.size())
    return -1;
  else
  {
    int mux = -1;
    for(int i=0;i<p.size();i++)
    {  
      mux = max(pre[p[i]],mux);
      pre[p[i]] = idx;
    } 
    return mux+1;
  }
  
}

int main()
{
  sync;
  sieve();
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    cin >> n;
    for(int i=0;i<n;i++)
    {
      int a;
      cin >> a;
      v.pb(a);
    }
    int l=0,r=0;
    int li =-1;
    while(r<n)
    {
      int index = cal(r);
      //cout << index << endl;
      if(index == -1)
      {  dp[r] = -1;li = r;}
      else
      {
        if(index <= li)
          index = li+1;
        r == 0 ? dp[r] = index : dp[r] = max(dp[r-1],index);
      }
      r++;
    }
    ll res = 0;
    for(int i=0;i<n;i++)
    {
      //cout << dp[i] << endl;
      if(dp[i]!=-1)
      { 
         ll size = (i-dp[i]+1);
         res = res + size;
//         cout << "hi" << endl;
      }
    }
    cout << res << endl;
    v.clear();
  }
}

