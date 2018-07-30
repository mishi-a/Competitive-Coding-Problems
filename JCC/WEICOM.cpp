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
int flag = 0;
int n;
int create(std::vector<int> v)
{
	int arr[55][55];
	memset(arr,0,sizeof(arr));
	// for(int i=0;i<v.size();i++)
	// 	cout << v[i] << " ";
	// cout << endl;
	for(int i=0;i<n;i++)
		arr[i][i]=-1;
    int val;
	for(int i=0;i<n;i++)
	{
		if(i<v.size())
		  val = v[i];
	    else
	      val = 0;
		int cnt = 0;
		for(int j=0;j<n;j++)
			if(arr[i][j]==1)
				val--;
		if(val<0)
			return 0;
		for(int j=0;j<n;j++)
		{
			if(j==i)
				continue;
			if(cnt == val)
				break;
            if(arr[i][j]==0)
			{
				arr[i][j]=1;
				arr[j][i]=-1;
				cnt++;
			}
			
		}
		for(int j=0;j<n;j++)
		{
			if(j==i)
				continue;
			if(arr[i][j]!=1)
				arr[j][i]=1;
		}
		//cout << cnt << " " << i << " " << val << endl;
		if(cnt!=val)
			return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]!=1)
				cout << "0";
			else
				cout << arr[i][j];
		} 
		cout << endl;
	}
	return 1;
}
void solve(vector<int> x,int k,int cnt)
{
	//cout << "flag " << flag << endl;
	if(flag==1)
      	return;
	if(k==0)
	{
	    flag =create(x);
		return ;
	}
	if(cnt>=n)
		return;
	cnt++;
	for(int i=0;i<n;i++)
	{
      x.pb(i);
      solve(x,k-i*i,cnt);
      x.pop_back();
      if(flag==1)
      	return;
	}
	return ;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int k;
  	cin >> n >> k;
  	if(k>=62500)
  	{
  		cout << "-1" << endl;
  		continue;
  	}
  	for(int i=0;i<n;i++)
  	{
  		std::vector<int > v;
  		v.pb(i);
  		solve(v,k-i*i,1);
  	}
  	if(flag == 0)
  		cout << "-1" << endl;
  	flag = 0;
  }
}
