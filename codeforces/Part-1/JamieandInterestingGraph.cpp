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
vector <vector<int> > v(100005);
int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  cout << "3 " << n+1 << endl;
  cout << "1 " <<n <<" 3" <<endl;
  v[1].pb(n);
  v[n].pb(1);
  m--;
  int last = n;
  for(int i=2;i<n;i++)
  {
  	cout << last << " " << i << " 1" << endl;
  	v[last].pb(i);
  	v[i].pb(last);
    last = i;
    m--;
  }
  // cout << v[2][0] << " " << v[2][1] << endl;
  if(m>0)
  {
  	for(int i=1;i<=n;i++)
  	{
  		for(int j=i+1;j<=n;j++)
  		{
  			// cout << i << " " << v[i][1] << " " << j << endl;
  			if(v[i].size()>1 && v[i][0]!=j && v[i][1]!=j)
  			{
              cout << i << " " << j << " 10000000" << endl;
              m--;
  			}
  			else
  			{
  				if(v[i].size()==1 && v[i][0]!=j)
  				{
  					cout << i << " " << j << " 10000000" << endl;
                    m--;
  				}
  			}
  			if(m==0)
  				return 0;
  		}
  	}
  }
}
