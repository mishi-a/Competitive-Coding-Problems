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
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
ll arr[30][15];
vector <ll> v;
set <string> se;
int main()
{
  sync;
  ll t;
  cin >> t;
  ll tc = 1;
  while(t--)
  {
    //cout << "Case #" << tc << ": ";
    ll n,l;
    cin >> n >> l;
    for(ll i=0;i<n;i++)
    {
      string s;
      cin >> s;
      se.insert(s);
      for(ll j=0;j<s.length();j++)
      {
        arr[s[j]-'A'][j]++;
      }
    }
    for(ll i=0;i<l;i++)
    {
      ll cnt = 0;
      for(ll j=0;j<26;j++)
      {
        if(arr[j][i]>0)
          cnt++;
      }
      v.pb(cnt);
      cout << cnt << " ";
    }
    cout << endl;
    ll flag = 0;
    string s = "";
    for(ll j=0;j<l-1;j++)
    {
      for(ll i=0;i<26;i++)
      {
        ll val = 1;
        if(arr[i][j]!=0)
        {
          for(ll k=0;k<l;k++)
          {
            if(k == j)continue;
            val = val*v[k];
          }
          cout << j << " " << val << " " << arr[i][j] << " " << i << endl;
          if(val!=arr[i][j])
          {
            flag = 1;
            cout << (char)('A'+i);
            s = s + (char)('A'+i);
            break;
          }
        }
      }
      if(j == 0 && flag == 0)
      {
        break;
      }
    }
    if(flag == 0)
      cout << "-" << endl;
    else
    {
      for(ll i=0;i<26;i++)
      {
        string p;
        if(arr[i][l-1]>0)
        {
          p = s;
          p = p + (char)('A'+i);
          if(se.find(p)==se.end())
          {
            cout << (char)('A'+i);
            break;
          } 
        }
      }
      cout << endl;
    }
    v.clear();
    memset(arr,0,sizeof(arr));
    se.clear();
    tc++;
  }
}