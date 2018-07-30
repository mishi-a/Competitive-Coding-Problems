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

int arr[300005];

int main()
{
  sync;
  int n,a;
  cin >> n;
  int t=n;
  int tot=0;
  cout << "1 ";
  for(int i=0;i<t;i++)
  {
  	cin >> a;
  	arr[a]=1;
  	int idx = n,cnt=0;
  	while(idx>0&&arr[idx]==1)
  	{
      cnt++;
      tot++;
      idx--;
  	}
  	n-=cnt;
    cout << i+1-tot+1 << " ";
  }
}
