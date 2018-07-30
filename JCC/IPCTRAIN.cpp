/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <long long,long long>
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
struct comp {
    bool operator() (const pair<ll,pii > &a, const pair<ll,pii > &b) {
        return a.second.second < b.second.second;
    }
};
vector <pair<ll,pii > > v;
priority_queue <pair<ll,pii > , vector<pair<ll,pii > > ,comp > q;
 
bool acompare (pair<ll,pii > a , pair<ll,pii > b)
{
   if(a.FI < b.FI)
     return true;
   else if (a.FI == b.FI && a.SE.SE > b.SE.SE)
     return true;
   else
     return false;
} 
 
void solve()
{
  ll n,d1;
  cin >> n >> d1;
  for(ll i=0;i<n;i++)
  {
    ll d,t,s;
    cin >> d >> t >> s;
    v.pb({d,{t,s}});
  }
  sort(v.begin(),v.end(),acompare);
  ll ans = 0;
  ll day = v[0].FI;
  ll ind = 0;
  //cout << "HI" << endl;
  for(ll i=1;i<=d1;i++)
  {
    for(ll j =ind;j<n;j++)
    {
      if(v[j].FI == i)
      {
        q.push(v[j]);
        ind = j + 1;
      }
      else
      {
        ind = j;
        break;
      }
    }
    if(!q.empty())
    {
      pair<ll,pii > t = q.top();
      q.pop();
      //cout << t.FI << " " << t.SE.FI << " " << t.SE.SE << endl;
      if(t.SE.FI!=1)
        q.push({t.FI,{t.SE.FI-1,t.SE.SE}});
     }
  }
  //cout << "HI" << endl;
  while(!q.empty())
  {
    pair<ll,pii > t = q.top();
    q.pop();
    //    cout << t.FI << " " << t.SE.FI << " " << t.SE.SE << endl;
    ans = ans + t.SE.FI * t.SE.SE;
  }
  cout << ans << endl;
}
 
int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
    solve();
    v.clear();
    q = priority_queue <pair<ll,pii > , vector<pair<ll,pii > > ,comp >();
  }
}
