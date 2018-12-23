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

int main()
{
  sync;
  int w,h,k;
  cin >> w >> h >> k;
  int ans = 0;
  for(int i=0;i<k;i++)
  {
  	
  	if(w<=0 || h<=0)
  		break;
  	if(w == 1)
  	{
  		ans+=h;
  		continue;
  	}
  	if(h == 1)
  	{
  		ans+=w;
  		continue;
  	}
  	ans += w+2*(h-1)+(w-2);
  	w = w-4;
  	h = h-4;
  }
  cout << ans << endl;
}
