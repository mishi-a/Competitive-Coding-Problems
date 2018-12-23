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
map<int,int> mp;
int main()
{
  sync;
  int t;
  cin >> t;
  int mun = INT_MAX,mux=INT_MAX;
  while(t--)
  {
  	char ch;
  	int n;
  	cin >> ch >> n;
  	if(ch == 'L')
  	{
  		if(mun ==INT_MAX)
  		{
  			mun=0,mux=0;
  			mp[n] = mun;
  		}
  		else
  		{
  			mun--;
  			mp[n]=mun;
  		}

  	}
  	else if(ch == 'R')
  	{
  		if(mun ==INT_MAX)
  		{
  			mun=0,mux=0;
  			mp[n] = mun;
  		}
  		else
  		{
  			mux++;
  			mp[n]=mux;
  		}
  	}
  	else
  	{
  		cout << min(abs(mp[n]-mun),abs(mux-mp[n]))<<endl;
  	}

  }
}
