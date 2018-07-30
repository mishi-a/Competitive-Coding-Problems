/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>

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

vector <int> v;
vector <int> v1;
vector <int> v2;
void solve()
{
  int n,q;
  cin >> n >> q;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  while(q--)
  {
    int x,y,z,w;
    cin >> x >> y >> z >> w;
    copy(v.begin()+x-1,v.begin()+y, back_inserter(v1));
    copy(v.begin()+z-1,v.begin()+w, back_inserter(v2));
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int cnt = 0;
    for(int i=0;i<=y-x;i++)
    {
      if(v1[i]!=v2[i])
        cnt++;
      if(cnt == 2)
        break;
      
    }
    if(cnt == 2)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
    v1.clear();
    v2.clear();
  }  
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    v.clear();
  }
}

