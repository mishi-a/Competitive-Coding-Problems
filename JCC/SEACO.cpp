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
const ll mod = 1e9+7;
vector <pair<ll,pair<ll,ll> > > q;
ll tot[100005];
ll bit[100005];
ll arr[100005];
ll len;
ll getsum(ll idx)
{
  idx++;
  ll res = 0;
  while(idx>0)
  {
    res+=bit[idx];
    res+=mod;
    res%=mod;
    idx-=(idx&(-idx));
  }
  return res%mod;
}

void update(ll idx,ll val)
{
  idx++;
  while(idx<=len)
  {
    bit[idx]+= (val+mod)%mod;
    bit[idx]%=mod;
    idx+=(idx&(-idx));
  }
}


int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
    ll n,m,a,b,c;
    cin >> n >> m;
    len = m+1;
    for(ll i=0;i<m;i++)
    {
       cin >> a >> b >> c;
       q.pb({a,{b,c}});
    }
    for(ll i=m-1;i>=0;i--)
    {
      if(q[i].FI==2)
      {
        ll l = q[i].SE.FI;
        ll r = q[i].SE.SE;
        l--;
        r--;
        ll ans = getsum(i);
        update(i,1);
        update(i+1,-1);
        tot[i]++;
        tot[i] = (tot[i]+mod)%mod;
        tot[i+1]--;
        tot[i+1] = (tot[i+1]+mod)%mod;
        tot[l]+=(ans+1);
        tot[l] = (tot[l]+mod)%mod;
        update(l,ans+1);
        update(r+1,-(ans+1));
        tot[r+1]-=(ans+1);
        tot[r+1] = (tot[r+1]+mod)%mod;       
      }
      else
      {
        tot[i]++;
        tot[i] = (tot[i]+mod)%mod;
        tot[i+1]--;
        tot[i+1] = (tot[i+1]+mod)%mod;
        update(i,1);
        update(i+1,-1);
      }
    }
    for(ll i=1;i<m;i++)
    {
      tot[i]+=tot[i-1];
      if(tot[i]>=mod)
        tot[i]%=mod;
    }
    for(ll i=0;i<m;i++)
    {
       if(q[i].FI == 1)
       {
         ll x = q[i].SE.FI;
         ll y = q[i].SE.SE;
         arr[x]+=tot[i];
         arr[x]=(arr[x]+mod)%mod;
         arr[y+1]-=tot[i];
         arr[y+1]=(arr[y+1]+mod)%mod;
       }
    }
    for(ll i=1;i<=n;i++)
    {
       arr[i]+=arr[i-1];
       if(arr[i]>=mod)
         arr[i]%=mod;
    }
    for(ll i=1;i<=n;i++)
      cout << arr[i] << " ";
    cout<< endl;
    q.clear();
    memset(tot,0,sizeof(tot));
    memset(bit,0,sizeof(bit));
    memset(arr,0,sizeof(arr));
  }
}

