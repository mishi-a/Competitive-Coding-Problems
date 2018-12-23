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

void solve()
{
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i == x && j == y) continue;
			int totVis = m-1+n-1+min(i-1,j-1)+min(m-j,i-1)+min(n-i,j-1)+min(m-j,n-i)+1;
			if(i == x || j == y || (abs(x-i) == abs(y-j)))
			{
				ans += ((n*m)-totVis);
				if(i == x)
				{
					if(j<y)
						ans+=(m-y);
					else
						ans+=y-1;
				} 
				else if(j == y)
				{
					if(i<x)
						ans+=n-x;
					else
						ans+=x-1;
				}
				else
				{
					int dist = abs((x-i));
					if(i<x && j>y)
					{
						ans+=min(j-1,n-i)-dist;
					}
					else if(i>x && j>y)
					{
						ans+=min(i-1,j-1)-dist;
					}
					else if(i>x && j<y)
					{
						ans+=min(m-j,i-1)-dist;
					}
					else
					{
						ans+=min(n-i,m-j)-dist;
					}

				}
			}
			else
				ans += ((n*m)-totVis-1);
			//cerr << i <<"  "<< j << " " << ans  << " " << totVis << endl;
		}

	}
	cout << ans<< endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	solve();
  }
}
