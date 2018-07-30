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

ll A[100005],B[100005];
ll tCount[100005];
ll ways[100005];
ll mul[100005];
ll mod = 1e9+7;
ll power(ll base,ll p)
{
  ll ans = 1;
  while(p>0)
  {
    if(p%2) ans = ((ans%mod)*(base%mod))%mod;
    p/=2;
    base = ((base%mod)*(base%mod))%mod;
  }
  return ans;
}

int main()
{
  sync;
  ll n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  	cin >> A[i],tCount[i]=1;
  for(int i=0;i<n;i++)
  	cin >> B[i];
  tCount[n]=1;
  for(int i=n-1;i>=0;i--)
  {
    tCount[i]=tCount[i+1];
  	if(!A[i])
  		tCount[i]=((tCount[i]%mod)*(m%mod))%mod;
    if(!B[i])
  		tCount[i]=((tCount[i]%mod)*(m%mod))%mod;  
  }
  int cnt=0;
  ways[n]=0;
  for(int i=n-1;i>=0;i--)
  {
  
  	if(A[i]==0&&B[i]==0)
  	{
  		cnt+=2;
  		ways[i] = (((((m*(m-1))/2)%mod)*(tCount[i+1]%mod))%mod+ (m*ways[i+1])%mod)%mod;
  	}
  	else if(A[i]==0&&B[i]!=0)
  	{
  		cnt++;
  		ways[i] = (((m-B[i])*tCount[i+1])%mod+ways[i+1]%mod)%mod;
  	}
  	else if(A[i]!=0&&B[i]==0)
  	{
  		cnt++;
  		ways[i] = (((A[i]-1)*tCount[i+1])%mod+ways[i+1]%mod)%mod;
  	}
  	else if(A[i]<B[i])
  	{
  		ways[i]=0;
  	}
  	else if(A[i]==B[i])
  		ways[i]=ways[i+1];
    else
    	ways[i] = tCount[i+1];
    //cout << ways[i] << endl;
  }
  ll den = power(m,cnt);
  //cout << ways[0] << " " << power(den,mod-2) << endl;
  cout << (ways[0]*power(den,mod-2))%mod << endl;
}
