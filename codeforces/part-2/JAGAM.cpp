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
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int n,z1,z2,v=0;
  	cin >> n >> z1 >> z2;
  	for(int i=0;i<n;i++)
  	{
  		cin >> arr[i];
  	}
	int flag = 0;
	int s = 0;
	for(int i=0;i<n;i++)
	{
		if(s+arr[i] == z1 || s+arr[i] == z2 || s-arr[i] == z1 || s-arr[i] == z2)
		{
			flag = 1;
			cout << 1 << endl;
			break;
		}
	}
	if(flag == 0)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(((s-arr[i]+arr[j] == z1 ||s-arr[i]+arr[j] == z2)
				||(s-arr[i]-arr[j] == z1 || s-arr[i]-arr[j] == z2))
				&&((s+arr[i]+arr[j] == z1 || s+arr[i]+arr[j] == z2)
				||(s+arr[i]-arr[j] == z1 || s+arr[i]-arr[j] == z2 )))
				{
					flag++;
					break;
				}
			}
		}
		if(flag == n)
			cout << 2 << endl;
		else	
			cout << 0 << endl;
	}
  }
}