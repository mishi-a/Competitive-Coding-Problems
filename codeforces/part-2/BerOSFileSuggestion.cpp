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
map<string,int> mp;
map<string,string> mp1;
void pop(string s)
{
	set<string> se;
	for(int i=0;i<s.size();i++)
	{
		for(int j=i;j<s.size();j++)
		{
			if(se.find(s.substr(i,j-i+1))!=se.end()) continue;
			se.insert(s.substr(i,j-i+1));
			mp[s.substr(i,j-i+1)]++;
			mp1[s.substr(i,j-i+1)] = s;
		}
	}
}
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
  	string s;
  	cin >> s;
  	pop(s);
  }
  int q;
  cin >> q;
  while(q--)
  {
  	string k;
  	cin >> k;
  	if(mp[k] == 0)
  	{
  		cout << 0 << " -" << endl;
  		continue;
  	}
  	cout << mp[k] <<" " <<mp1[k] << endl; 
  }
  
}
