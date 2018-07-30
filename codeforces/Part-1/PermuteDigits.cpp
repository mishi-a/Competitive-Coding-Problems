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
int freq[11],n;
vector <int>v,v1,ans;
int glob=0;
void solve(int idx,int sig)
{
  if(idx>=n&&glob==0)
  {
  	for(int i=0;i<ans.size();i++)
  		cout << ans[i];
  	cout << endl;
  	glob=1;
  	return ;
  }
  int val = v1[idx];
  if(sig==0)
  {
     for(int i=val;i>=0;i--)
     {
     	if(glob==1)
     		return ;
	  	if(freq[i]>0)
	  	{
	  		ans.pb(i);
	  		freq[i]--;
	  		if(i==val)
	  		    solve(idx+1,0);
	  	    else
	  	    	solve(idx+1,1);
	  		freq[i]++;
	  		ans.pop_back();
	  	}
    }
  }
  else
  {
  	for(int i=9;i>=0;i--)
  	{
  		if(glob==1)
     		return ;
  		if(freq[i]>0)
  		{
  			ans.pb(i);
  			freq[i]--;
  			solve(idx+1,1);
  			freq[i]++;
  			ans.pop_back();
  		}
  	}
  }
  
}
int main()
{
  sync;
  ll a,b;
  cin >> a >> b;
  while(a!=0)
  {
  	freq[a%10]++;
  	v.pb(a%10);
  	a=a/10;
  }
  while(b!=0)
  {
  	v1.pb(b%10),b/=10;
  }
  reverse(v1.begin(),v1.end());
  n = v.size();
  if(n<v1.size())
  {
  	sort(v.begin(),v.end(),greater<int>());
  	for(int i=0;i<v.size();i++)
  		cout << v[i];
  	cout << endl;
  }
  else
  solve(0,0);;
}
