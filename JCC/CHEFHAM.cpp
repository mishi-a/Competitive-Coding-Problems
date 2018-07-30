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

int arr[100005],arr1[100005],n;
int l;
void solve()
{
  if(n==1)
  	return ;
  if(n==2)
  {
  	swap(arr[0],arr[1]);
  	return;
  }
  for(int i=0;i<n-1;i+=2)
  {
    if(arr[i]!=arr[i+1])
    {
    	swap(arr[i],arr[i+1]);
    }
    else
    {
    	if(i==0&&n>=4)
    	{
    		swap(arr[i],arr[i+2]);
    		swap(arr[i+1],arr[i+3]);
    		i+=2;
    	}
    	else if(n>=	4)
    	{
    		swap(arr[i],arr[i-2]);
    		swap(arr[i+1],arr[i-1]);
    	}
    }
  }
  if(n%2==1)
    {
    	if(l!=arr[n-1]&&arr[n-1]!=arr[n-2])
    		swap(arr[n-1],arr[n-2]);
    	else{
    		if(arr1[0]!=arr[n-1]&&arr[0]!=arr[n-1])
    		  swap(arr[0],arr[n-1]);
    	     else 
    	    	swap(arr[1],arr[n-1]);
    	   }
    }
 
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	cin >> n;
  	for(int i=0;i<n;i++)
  	{
  		cin >> arr[i];
  		arr1[i]=arr[i];
  	}
  	l = arr[n-2];
  	solve();
  	int cnt = 0;
  	for(int i=0;i<n;i++)
  	{
  		if(arr[i]!=arr1[i])
  			cnt++;
  	}
  	cout << cnt << endl;
  	for(int i=0;i<n;i++)
  		cout << arr[i] << " ";
  	cout << endl;
  }
}
