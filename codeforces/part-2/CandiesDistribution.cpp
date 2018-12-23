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
int l[1005],r[1005],arr[1005];
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> l[i];
  for(int j=0;j<n;j++) cin >> r[j];
  for(int i=0;i<n;i++)
  	arr[i]=1;
  for(int i=0;i<n;i++)
  {
  	int le = i-1;
  	int k = l[i];
  	while(le>=0)
  	{
  	   if(k> l[le])
  	   {
  	   	 arr[le]++;
  	   	 k--;
  	   }	
  	   le--;
  	}
  	if(k != 0)
  	{
  		cout << "NO" << endl;
  		return 0;
  	}
  	int ri = i+1;
  	int p = r[i];
  	while(ri<n)
  	{
  		if(p > r[ri])
  			arr[ri]++;
  		
  		if(p > r[ri])
  			p--;
  		ri++;
  	}
  	if(p!=0)
  	{
  		cout << "NO" << endl;
  		return 0;
  	}
  }
  int flag = 0;
  for(int i=0;i<n;i++)
  {
  	int le = i-1;
  	int cnt = 0;
  	while(le>=0)
  	{
  		if(arr[le]>arr[i])
  			cnt++;
  		le--;
  	}	
  	if(cnt!=l[i])
  	{
  		cout << "NO" << endl;
  		return 0;
  	}
  	cnt = 0;
  	int ri = i+1;
  	while(ri<n)
  	{
  		if(arr[ri]>arr[i])
  			cnt++;
  		ri++;
  	}	
  	if(cnt!=r[i])
  	{
  		cout << "NO" << endl;
  		return 0;
  	}
  }
  cout << "YES" << endl;
  for(int i=0;i<n;i++)
  {
  	cout << arr[i] << " ";
  }
  cout << endl;
}
