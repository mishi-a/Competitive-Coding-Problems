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

ll s[105],d[105],c[105],ans[105];
set<pii> se;
int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++)
  {
  	cin >> s[i] >> d[i] >> c[i];
  	se.insert({s[i],i});
  	ans[d[i]] = m+1;
  }
  for(int i=1;i<=n;i++)
  {
  	if(se.size()==0)
  		break;
  	if(ans[i]!=0)
  		continue;
  	set<pii>::iterator itr = se.begin();
  	int lDay = itr->FI;
  	if(i<lDay)
  		ans[i]=0;
  	else
  	{
  		int xam = 105;
  		set<pii> :: iterator idx=se.end();
  		while(itr!=se.end())
  		{
  			if(itr->FI>i)
  				break;
  			else
  			{
  				if(i<d[itr->SE] && d[itr->SE]<xam)
  				{
  					xam = d[itr->SE];
  					idx = itr;
  				}	
  			}
  			itr++;
  		}
  		if(idx==se.end())
  			continue;
  		ans[i]=idx->SE;
  		c[idx->SE]--;
  		if(c[idx->SE]==0)
  		  se.erase(idx);
  	}
  }
  if(!se.empty())
  {
  	cout << "-1" << endl;
  	return 0;
  }
  for(int i=1;i<=n;i++)
  	cout << ans[i] << " ";
}
