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
int arr[MAX];
int solve()
{
	int n;
  	cin >> n;
  	for(int i=0;i<n;i++) cin >> arr[i];	
  	for(int i=n-1;i>=0;i--)
  	{
  		if(arr[i]!=-1)
  		{
  			int t = arr[i]-1;
  			for(int j=i-1;j>=0 && t!=0 ;j--)
  			{
  				if(arr[j]!=-1 && arr[j]!=t)
  					return -1;
  				if(arr[j] == -1)
  					arr[j]=t;
  				t--;
  				i = j;
  			}
  		}
  	}
  	int cnt = 0,p=0;
  	for(int i=0;i<n;i++)
  	{
  		if(arr[i] == 1)
  			cnt++;
  	}
  	if(cnt == 0)
  		return -2;
  	if(cnt == 1)
  	{
  		for(int i=0;i<n;i++)
  		{
  			if(arr[i]>1)
  				p++;
  			else if(arr[i] == 1)
  			{
  				if(p == 0)
  					return -2;
  				break;
  			}
  		}
  	}
  	int last = 0,ans = -1;
  	int start = 0;
  	if(arr[0] > 1)
  		last = -1*(arr[0]-1);
  	if(arr[0] == -1)
  	{
  		for(int i=0;i<n;i++)
  		{
  			if(arr[i] == 1)
  			{
  				last = i;
  				start = i;
  				break;
  			}	
  		}
  	}
  	for(int i=start+1;i<n;i++)
  	{
  		if(arr[i] == 1 )
  		{
  			if(ans == -1)
  				ans = i-last,last=i;
  			else
  				ans = __gcd(ans,i-last),last = i;
  		}
  	}
  	//cerr << ans << " " << arr[start] << endl;
  	int j = arr[start]-1;
  	for(int i=start;i<n;i++)
  	{
  		if(arr[i]!=-1)
  		{
  			if(arr[i] != (j%ans)+1)
  				return -1;
  		}
  		j++;
  	}
  	return ans;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int val = solve();
  	if(val == -2)
  		cout << "inf" << endl;
  	else if(val == -1)
  		cout << "impossible" << endl;
  	else
  	{
  		cout << val << endl;
  	}
  }
}
