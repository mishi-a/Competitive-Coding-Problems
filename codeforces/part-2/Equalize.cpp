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

int main()
{
  sync;
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  int ans = 0;
  for(int i=0;i<b.size();i++)
  {
  	if(b[i]!=a[i])
  	{

  		if(i+1 < b.size() && b[i] == a[i+1] && a[i] == b[i+1])
  		{
  			//cout <<"hi" << i << endl;
  			ans++;
  			i++;
  		}
  		else
  		{
  			//cout << i << endl;
  			ans++;
  		}
  	}
  }
  cout << ans << endl;
}
