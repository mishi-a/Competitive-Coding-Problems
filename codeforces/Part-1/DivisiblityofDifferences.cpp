/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
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
	if(par[y] < par[x])	// balancing the height of the trees
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/
		

using namespace std;

map <int,int> mp;
int arr[100005],arr1[100005];
int main()
{
  sync;
  int a,n,k,m;
  cin >> n >> k >> m;
  int mod=-1;
  for(int i=0;i<n;i++)
  {
  	cin >> arr[i];
  	arr1[i] = arr[i];
  	arr[i]%=m;
  	mp[arr[i]]++;
  	if(mp[arr[i]]>=k)
    {
    	mod = arr[i];
    	break;
    }		
  }
  if(mod!=-1)
  {
  	cout << "Yes" << endl;
  	int cnt=0;
  	for(int i=0;i<n;i++)
  	{
  		if(arr[i]%m==mod)
  			cout << arr1[i] << " ",cnt++;;
  		
  		if(cnt==k)
  			break;
  	}
  }
  else
  	cout << "No" << endl;
}
