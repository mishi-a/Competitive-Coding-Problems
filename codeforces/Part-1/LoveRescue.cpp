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

using namespace std;

int par[50];

vector<pii> v;
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}

void merge(int x,int y)
{
    if((x = root(x)) == (y = root(y)))
    {	  
             return ;
    }
	if(par[y] < par[x])
	{
		swap(x, y);
	}
	v.pb({x,y}); 	
	par[x] += par[y];
	par[y] = x;
}

int main()
{
  sync;
  int n;
  cin >> n;
  string s1,s2;
  cin >> s1 >> s2;
  for(int i=0;i<=50;i++)
  	par[i]=-1;
  for(int i=0;i<n;i++)
  {
  	merge(s1[i]-'a',s2[i]-'a');
  	//cout << i << endl;
  }
  cout << v.size() << endl;
  for(int i=0;i<v.size();i++)
  {
  	cout << (char)('a'+v[i].FI) <<" " << (char)('a'+v[i].SE) << endl; 
  }
}
