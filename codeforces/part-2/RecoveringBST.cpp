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

int arr[705];
bool check(int idx,int start,int end)
{
	//cout << idx << " " << start << " " << end << endl;
	int l,r;
	int flag = 0,flag1=0;
	for(int i=start;i<idx;i++)
	{
		if(__gcd(arr[idx],arr[i]) > 1)
		{
			if(check(i,start,idx-1))
			{
				flag = 1;	
			}
			
		}
	}
	for(int i=idx+1;i<=end;i++)
	{
		if(__gcd(arr[idx],arr[i]) > 1)
		{
			if(check(i,idx+1,end))
			{
				flag1 = 1;	
			}
			
		}
	}
	//cout << idx << " " << start << " " << end << " " << flag << " " << flag1 << endl;
	if(end-start == 0)
		return true;
	else if(idx==0&& flag1==0)
		return false;
	else if(idx==end&& flag==0)
		return false;
	else if((idx == 0 || idx == end ) && (flag1 == 1 || flag == 1 ) )
		return true;
	else if (flag == 1 && flag1 == 1)
		return true;
	else
		return false;
}
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
  	cin >> arr[i];
  }
  for(int i=0;i<n;i++)
  {
  	if(check(i,0,n-1))
  	{
  		cout << "Yes" << endl;
  		return 0;
  	}
  	//break;
  }
  cout << "No" << endl;
}
