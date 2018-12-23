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
  int n1;
  cin >> n1;
  vector<int> v,v1,v2;
  int ans = 0,cnt = 0;
  for(int i=0;i<n1;i++)
  {
  	string s;
  	int n;
  	cin >> s >> n;
  	if(s == "11")
  		ans+=n,cnt++;
  	else if(s == "10")
  		v.pb(n);
  	else if(s == "01")
  		v1.pb(n);
  	else
  		v2.pb(n);
  }
  //cout << ans << endl;
  sort(v1.begin(),v1.end(),greater<int>());
  sort(v2.begin(),v2.end(),greater<int>());
  sort(v.begin(),v.end(),greater<int>());
  for(int i=0;i<min(v1.size(),v.size());i++)
  {
  	ans+=(v1[i]+v[i]);
  }
  //cout << ans << endl;
  int t1 =min(v1.size(),v.size());
  for(int i=min(v1.size(),v.size());i<v.size();i++)v2.pb(v[i]);
  for(int i=min(v1.size(),v.size());i<v1.size();i++)v2.pb(v1[i]); 
  int k = v2.size();
  sort(v2.begin(),v2.end(),greater<int>());

  for(int i=0;i<min(cnt,k);i++) ans+=v2[i];
  cout << ans << endl;
}
