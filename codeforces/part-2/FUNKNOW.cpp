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
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int n;
  	cin >> n;
  	vector<int> v;
  	for(int i=0;i<n;i++)
  	{
  		int a;
  		cin >> a;
  		v.pb(a);
  	}
  	int ans = 0;
  	int a,b,c,d,e;
  	cin >> a >> b >> c >> d >> e;
  	int diff;
  	for(int i=1;i<n-3;i++)
  	{
  		for(int j=i+2;j<n-1;j++)
  		{
  			diff = v[i]*d+v[j]*b;
  			int mun = -1;
  			int sum = 0;
  			for(int k=0;k<i;k++ )
  			{
  				mun = max(v[k],mun);
  			}
  			sum += (e*mun);
  			mun = -1;
  			for(int k=i+1;k<j;k++ )
  			{
  				mun = max(v[k],mun);
  			}
  			sum+= (c*mun);
  			mun = -1;
  			for(int k=j+1;k<n;k++ )
  			{
  				mun = max(v[k],mun);
  			}
  			sum +=(a*mun);
  			ans = max(ans,sum);
  		}

  	}
  	cout << ans-diff << endl;

  }  
}
