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

int main()
{
  sync;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x=0,y=0;
  int flag = 0,ans=0;
  s[0]=='R'?x++:y++;
  if(x<y)
  	flag = 1;
  else
  	flag = 0;
  for(int i=1;i<s.length();i++)
  {
  	if(s[i]=='R')
  	{
  		x++;
  	}
  	else
  		y++;
  	//	cout << x << " " << y << endl;
    if(y>x&&flag == 0)
    	flag=1,ans++;
    if(x>y&&flag==1)
    	flag=0,ans++;
  }
  cout << ans << endl;
}
