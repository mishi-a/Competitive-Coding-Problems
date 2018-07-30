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

int n,l;
int arr[50];
int sum;
int arr1[300][300];
int solve(int idx,int rem)
{
	 if(arr1[idx][rem]!=-1)
	 	return arr1[idx][rem];
	if(rem <= 0 || idx>=n)
		return 0 ;
	int ans = 0;
	if(idx == n-1)
	{
		double val = (((arr[n-1]+rem)*100)/(n*1.0));
		int x = val;
			if(val-x>=0.5)
				x++;
		return x;
	}
	else
	{
		for(int i=0;i<=rem;i++)
		{
			double val = (((arr[idx]+i)*100)/(n*1.0));
			int x = val;
			if(val-x>=0.5)
				x++;
			ans = max(ans,x+solve(idx+1,rem-i));
		}
	}
	return (arr1[idx][rem]=ans);
}
int main()
{
  sync;
  int t;
  cin >> t;
  int cnt=0;
  while(t--)
  {
  	sum=0;
  	memset(arr,0,sizeof(arr));
  	memset(arr1,-1,sizeof(arr1));
  	cin >> n >> l;
  	cnt++;
  	for(int i=0;i<l;i++)
  	{
  		cin >> arr[i];
  		sum+=arr[i];
  	}
  	sum = n-sum;
  	//cout << sum << endl;
  	cout << "Case #"<<cnt << ": "<<solve(0,sum) << endl;
  }
}
