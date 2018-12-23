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
int arr[305][305];
int dp[300][305],dp1[300][305],ans[605];
int get(int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j < n;j++)
		{
			if(arr[j][i] == 1)
			{
				//cerr << j << " " << i << endl;
				dp[j][0]++;
				for(int k=j;k<n;k++)
				{
					for(int l=k+1;l<n;l++)
					{
						if(arr[k][i] == 1 && arr[l][i] == 1)
						{
							ans[l-k]++;
							if(k == j)
							{
								dp[l][0]++;
							}
						}
					}
				}
				return i;
			}
		}
	}
}
bool contains(int c,int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i][c] == 1)
			return true;
	}
	return false;
}
void updAnswer(int r,int c,int last,int cnt,int n,int m,int p)
{
	//cerr << r << " " << c << " " << last << " " << cnt << " " << n << " " << m << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(dp[i][j]!=0)
			{
				//cerr << i << " " << j << " " << dp[i][j] << endl;
				for(int k=r;k<=p;k++)
				{
					if(arr[k][c] == 1)
					{
						ans[j+abs(k-i)+abs(c-last)]+=dp[i][j];		
					}
					if(k == p)
					{
						dp1[i][j+abs(c-last)]+=dp[i][j];
						//cout << i << " " << j+abs(c-last) << " " << dp1[i][j+abs(c-last)] << endl; 
					}	
				}
				
				
			}
			
		}
	}
}
void updAnswer1(int r,int c,int last,int cnt,int n,int m,int p)
{
	//cerr << r << " " << c << " " << last << " " << cnt << " " << n << " " << dp[r][0] << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<c+n;j++)
		{
			if(dp1[i][j]!=0)
			{
				for(int k=r;k<=p;k++)
				{
					if(arr[k][c] == 1)
					{
						ans[j+abs(k-i)+abs(c-last)]+=dp1[i][j];
					}

					if(k== p)
						dp[i][j+abs(c-last)]+=dp1[i][j];
				}
				//cerr << i << " " << j <<" " << dp1[i][j] << endl;
				
			}
			
		}
	}
}
void solve(int n,int m)
{
	int last = -1;
	if(last == -1)
	{
		last = get(n,m);
	}
	int cnt = 1;
	//cerr << last << endl;
	for(int i=last+1;i<m;i++)
	{
		if(contains(i,n))
		{
			int tot = 0;
			int p = -1;
			for(int j=n-1;j>=0;j--)
				if(arr[j][i]==1){
					p=j;
					break;
				} 
			for(int j=0;j<=p;j++)
			{
				if(arr[j][i] == 1)
				{
					//cerr << j << " " << i << endl;
					tot++;
					if(cnt%2 == 1)
						updAnswer(j,i,last,tot,n,m,p);
					else
						updAnswer1(j,i,last,tot,n,m,p);
					break;
				}
			}
			if(cnt%2 == 1)
				dp1[p][0]++;
			else
				dp[p][0]++;
			for(int j=p;j>=0;j--)
			{
				for(int k=j-1;k>=0;k--)
				{
					if(arr[j][i] == 1 && arr[k][i] == 1)
					{
						ans[abs(k-j)]++;
						if(j == p)
						{
							if(cnt%2 == 1)
								dp1[k][0]++;
							else
								dp[k][0]++;
						}
					}	
					
				}
			}
			/*for(int i=1;i<=n+m-2;i++)
						cerr << ans[i] << " ";
					cerr << endl;*/
			if(cnt%2 == 1)
				memset(dp,0,sizeof(dp));
			else
				memset(dp1,0,sizeof(dp));
			last = i;
			cnt++;
			
		}
	}
	for(int i=1;i<=n+m-2;i++)
		cout << ans[i] << " ";
	cout << endl;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int n,m;
  	cin >> n >> m;
  	char ch;
  	for(int i=0;i<n;i++)
  	{
  		for(int j=0;j<m;j++)
  		{
  			cin >> ch;
	  		if(ch == '0') arr[i][j] = 0;
	  		else
	  			arr[i][j] = 1;	
  		}
  	}
  	solve(n,m);
  	memset(ans,0,sizeof(ans));
  	memset(dp,0,sizeof(dp));
  	memset(dp1,0,sizeof(dp1));
  }
}
