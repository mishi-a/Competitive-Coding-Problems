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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;

int primes[100004],k,i,j; // primes[] stores all primes
vector<int> v;
int sieve() // function to generate primes till sqrt(1000000000) using sieve
{
	int a[100000]={0};
	k=0;
	a[1]=1;
	for(i=2;i<=100000;i++)
	{
		if(a[i]==0)
		{
		  primes[k++]=i;
		  for(j=i*2;j<=100000;j+=i)
		  {
			a[j]=1;
		  }
	   }
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
  	int l,r;
  	cin >> l >> r;
  	for(int i=l;i<=r;i++)
  	{
  		int flag = 0;
  		for(int j=0;primes[j]*primes[j] <= i && j < k;j++)
  		{
  			if(i%primes[j] == 0)
  			{
  				flag = 1;
  				break;
  			}
  		}
  		if(flag == 0)
  			v.pb(i);
  	}
  	int q;
  	cin >> q;
  	while(q--)
  	{
  		int n;
  		cin >> n;
  		int idx = lower_bound(v.begin(),v.end(),n)-v.begin();
  		//cout << idx << endl;
  		if(idx  == v.size())
  			cout << -1 << endl;
  		else
  			cout << v[idx] << endl;
  	}
  	v.clear();
  }  
}
