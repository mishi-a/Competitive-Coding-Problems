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

ll arr[5][MAX+5],n;
string s;
bool check(int mid,int x,int y)
{
  int startx = 0,starty=0;
  if(mid>n) return false;
  for(int i=mid;i<n;i++)
  {
      if(s[i] == 'R')
        startx+=1;
      else if(s[i] == 'L')
        startx-=1;
      else if(s[i] == 'U')
        starty+=1;
      else
        starty-=1;
  }
  //cerr << startx << " " << starty << endl;
  //cerr << abs(x-startx)+abs(y-starty) << " " << mid << endl;

  if(abs(x-startx)+abs(y-starty) <= mid && (abs(x-startx)+abs(y-starty))%2==mid%2 )
    return true;
  //cerr << "hi";
  for(int i=1;i<=n-mid;i++)
  {
      if(s[i-1] == 'R')
        startx+=1;
      else if(s[i-1] == 'L')
        startx-=1;
      else if(s[i-1] == 'U')
        starty+=1;
      else if(s[i-1] == 'D')
        starty-=1;

      if(s[i+mid-1] == 'R')
        startx-=1;
      else if(s[i+mid-1] == 'L')
        startx+=1;
      else if(s[i+mid-1] == 'U')
        starty-=1;
      else if(s[i+mid-1] == 'D')
        starty+=1;
      //cerr << startx << " " << starty << endl;
      if(abs(x-startx)+abs(y-starty) <= mid && (abs(x-startx)+abs(y-starty))%2==mid%2 )
        return true;
  }
  return false;
}

int main()
{
  sync;
  cin >> n;

  cin >> s;
  ll x,y;
  cin >> x >> y;
  {
  	ll x1=0,y1=0;
  	for(int i=0;i<n;i++)
  	{
  		if(s[i] == 'R')
  			x1+=1;
  		else if(s[i] == 'L')
  			x1-=1;
  		else if(s[i] == 'U')
  			y1+=1;
  		else
  			y1-=1;
  	}
  	if(x1 == x && y1 == y)
  		cout << 0 << endl;
  	else
  	{
  		//cerr <<x1 << " " << y1 << endl;
  		ll l = 1,r=n;
  		ll ans = -1;
  		while(l<=r)
  		{
  			int mid = (l+r)/2;
  			//cerr << mid << endl;
  			if(check(mid,x,y))
  			{
  				ans = mid;
  				r = mid-1;
  			}
  			else
  			{
  				l = mid+1;
  			}
  			//break;
  		}
  		cout << ans << endl;
  	}
  }
}
