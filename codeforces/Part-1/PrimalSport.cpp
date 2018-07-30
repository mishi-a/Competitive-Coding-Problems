/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
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


using namespace std;
#define MAXN 1000005
int spf[MAXN+5];

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
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
int getMax(int n)
{
	int ans = 1;
	int p = n;
	while(n!=1)
	{
		ans = max(ans,spf[n]);
		n/=spf[n];
	}
	if(ans == p)
		ans = -10000000;
	return ans;
}
int main()
{
  sync;
  sieve();
  int n;
  cin >> n;
  int get = getMax(n);
  int l = n-get+1,r=n;
  int ans = INT_MAX;
  for(int i=l;i<=r;i++)
  {
  	//cout << i << " " << getMax(i) << endl;
  	ans = min(ans,i-getMax(i)+1);
  }
  cout << ans << endl;
}
