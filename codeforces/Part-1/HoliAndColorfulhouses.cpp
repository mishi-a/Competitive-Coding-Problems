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
char arr[1005];
int n,q;
int solve(int x,int y)
{
	//cout << x << y << endl;
	if(x==y)
		return 0;
	
	int ans = 0;
	for(int i=x;;)
    {
      if(i==n)
      {
      	if(arr[1]!=arr[i])
      		ans++;
      	i = 1;
      }	
      else
      {
      	if(arr[i+1]!=arr[i])
      	 ans++;
        i=i+1;
      }
      
      if(i==y)
      	break;
    }
    int cnt = 0;
    for(int i=x;;)
    {   
    	if(i==1)
    	{
    		if(arr[n]!=arr[i])
    			cnt++;
    		i = n;
    	}
    	else
    	{
    		if(arr[i-1]!=arr[i])
    			cnt++;
    		i--;
    	}
    	if(i==y)
    		break;
    }
    return min(ans,cnt);
}

int main()
{
  sync;
  int t,x,y;
  cin >> t;
  while(t--)
  {
  	
  	cin >> n >> q;
  	for(int i=1;i<=n;i++)
  		cin >> arr[i];
  	while(q--)
  	{
  		cin >> x >> y;
  		cout << solve(x,y) << endl;
  	}
  }
}
