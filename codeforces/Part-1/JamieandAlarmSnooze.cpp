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

int arr[2360];

bool check(int n)
{
	while(n!=0)
	{
		if(n%10==7)
			return true;
		n/=10;
	}
	return false;
}

int main()
{
  sync;
  int x;
  cin >> x;
  int h,m;
  cin >> h >> m;
  int nnum = h*100+m;
  int cnt=0;
  while(arr[nnum]!=1)
  {
  	arr[nnum]=1;
  	if(check(nnum))
  	{
  		break;
  	}
  	if(nnum%100<x)
  	{
      int p = nnum%100;
      int q = nnum/100;
      p = 59;
      int z = x-(nnum%100+1);
      q==0?q=23:q--;
      nnum = q*100+(p-z);
  	}
  	else
  		nnum-=x;
  	// cout << nnum << endl;
  	
  	cnt++;
  }
  cout << cnt << endl;
}
