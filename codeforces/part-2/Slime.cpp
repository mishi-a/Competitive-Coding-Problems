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

const int MAX = 5e5+7;
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
ll arr[MAX];
int main()
{
  sync;
  ll n;
  cin >> n;
  ll pos=0,neg=0,sum=0;
  ll mux=LLONG_MAX;
  for(int i=0;i<n;i++)
  {
  	cin >> arr[i];
  	sum+=abs(arr[i]);
  	if(arr[i]>0)
  		pos++;
  	else if(arr[i]<0)
  		neg++;
  	else
  		pos++,neg++;
  	mux = min(mux,abs(arr[i]));
  }
  if(n == 1)
  {
  	cout << arr[0] << endl;
  	return 0;
  }
  if(pos == n)
  {
  	cout << sum - 2*mux << endl;
  }
  else if(neg == n)
  {
  	cout << sum-2*mux << endl;
  }
  else
  {
  	cout << sum << endl;
  }
}
