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
int arr1[26];
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  for(int i=0;i<n;i++)
  {
  	arr1[s[i]-'A']++;
  }
  int mun = INT_MAX;
  for(int i=0;i<k;i++)
  {
  	mun = min(mun,arr1[i]);
  }
  if(mun == 0)
  {
  	cout << 0 << endl;
  	return 0;
  }
  else
  {
  	cout << k*mun << endl;
  }
}
