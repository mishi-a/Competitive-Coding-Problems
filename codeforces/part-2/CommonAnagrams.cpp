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
string s,s1;
set <string> se,se1;
int check(string p)
{
  for(int i=0;i<=s1.size()-p.size();i++)
  {
      string x = s1.substr(i,p.size());
      sort(x.begin(),x.end());
      if(p == x) 
      {
        se.insert(p);return 1; 
      }  
  }
  se1.insert(p);
  return 0;
}
int main()
{
  sync;
  int t;
  cin >> t;
  int cnt = 0;
  while(t--)
  {
    cnt++;
  	int n;
  	cin >> n;
  	cin >> s >> s1;
  	int ans = 0;
  	for(int i=0;i<n;i++)
  	{
  		for(int j=i;j<n;j++)
  		{
        string p = s.substr(i,j-i+1);
        sort(p.begin(),p.end());
        if(se.find(p)!=se.end()){
          ans++;
          continue;
        }
        if(se1.find(p)!=se1.end())
          continue;
        ans += check(p);
      }
  	}
    cout << "Case #" << cnt <<": ";
    cout << ans << endl;
    se.clear();
    se1.clear();
  }
}
