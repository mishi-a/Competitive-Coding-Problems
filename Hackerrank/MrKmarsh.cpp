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

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
vector <vector<char > >v(505,vector<char>(505));
vector <vector <int> > rsum(505);
vector <vector <int> > csum (505);; 
map <pair<pii,pii >,int > mp;
int solve(int li,int lj,int ri,int rj)
{
  int ans,flag = 0,flag1 = 0;
  if(li<0 || lj < 0 || ri<0 || rj <0)
    return 0;
  if(li == ri || lj == rj)
    return 0;
  if((lj==0 ? rsum[li][rj] : rsum[li][rj]-rsum[li][lj-1]) == 0 && (lj==0 ? rsum[ri][rj] : rsum[ri][rj]-rsum[ri][lj-1]) == 0)
    flag = 1;
  //cout << "flag " << flag << endl;
  if((li==0 ? csum[lj][ri] : csum[lj][ri]-csum[lj][li-1]) == 0 && (li==0 ? csum[rj][ri] : csum[rj][ri]-csum[rj][li-1]) == 0)
    flag1 = 1;
  if(flag == flag1 && flag == 1)
    return 2*((ri-li)+(rj-lj));
  if(mp.find({{li,lj},{ri,rj}})!=mp.end())
    return mp[{{li,lj},{ri,rj}}];
  else
  {
    ans = max(max(solve(li,lj,ri-1,rj),solve(li,lj,ri-1,rj-1)),solve(li,lj,ri,rj-1));
  }
  return (mp[{{li,lj},{ri,rj}}]=ans);

}

int main()
{
  sync;
  int m,n;
  cin >> m >> n;
  for(int i=0;i<m;i++)
  {
    int cnt = 0;
    for(int j=0;j<n;j++)
    {
      cin >> v[i][j];
      if(v[i][j]=='x')
        cnt++;
      //cout << cnt << endl;
      rsum[i].pb(cnt);
      //cout << rsum[i][j] << endl;
    }
  }
  for(int j=0;j<n;j++)
  {
    int cnt = 0;
    for(int i=0;i<m;i++)
    {
      if(v[i][j] == 'x')
        cnt++;
      csum[j].pb(cnt);
    }
  }
  //for(int i=0;i<m;i++)
    //cout << rsum[i] << " ";
  //cout << endl;
  int ans=0;
  for(int i=0;i<m;i++)
  {
    if(ans > 2*(m-i+n-i))
      continue;
    if(ans > 2*(m-i+n) && m-i>0)
      break;
    for(int j=0;j<n;j++)
    {
      ans = max(ans,solve(i,j,m-1,n-1));
      //cout << ans << endl;
    }
  }
  if(ans == 0)
    cout << "impossible" << endl;
  else
   cout << ans << endl;
}

