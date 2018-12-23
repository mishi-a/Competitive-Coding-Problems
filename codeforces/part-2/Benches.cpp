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

const int MAX = 1e5;
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
  int n;
  cin >> n;
  int m;
  cin >> m;
  
  for(int i=0;i<n;i++)
  	cin >>  arr[i];
  sort(arr,arr+n);
  int mun= arr[n-1];
  int mux =mun+m;
  for(int i=0;i<n-1;i++)
  {
  	{
  		m = m-(mun-arr[i]);
  	}
  }
  int ans= mun;
  if(m>0)
  {
  	ans += (m/n)+(m%n==0?0:1);
  }
  cout <<  ans  <<" " <<  mux <<  endl;

}
