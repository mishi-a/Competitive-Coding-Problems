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

int arr[135];

int main()
{
  sync;
  ll n,k;
  cin >> n >> k;
  ll cnt = 0;
  for(ll i=0;i<62;i++)
  {
    if(n&(1LL<<i))
    {
    	arr[64+i]++;
    	cnt++;
    }
  }
  if(cnt>k)
  {
  	cout << "No" << endl;
    return 0;
  }
  while(cnt!=k)
  {
    for(ll i =130;i>=0;i--)
    {
      if(arr[i]>0)
      {
        arr[i]--;
        arr[i-1]+=2;
        break;
      }
    }
    cnt++;
  }
  cout << "Yes" << endl;
  for(ll i=130;i>=0;i--)
  {
    while(arr[i]!=0)
    {
      cout << i-64 << " ";
      arr[i]--;
    }
  }
  cout << endl;
}
