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
vector <vector<int> > v(26);
int arr[26] = {0};
map <char,int> mp;
int main()
{
  sync;
  int n;
  cin >> n;
  while(n--)
  {
    string a,b;
    cin >> a >> b;
    int cnt = 0;
    for(int i=0;i<a.length();i++)
    {
      v[a[i]-'a'].pb(i);
      if(arr[a[i]-'a'] == 0)
      {
        arr[a[i]-'a'] = 1;
        cnt++;
      }  
    }
    int ans = -1;
    int tot = 0;
    for(int i=0;i<26;i++)
    {
      char x;
      int flag = 0;
      for(int j=0;j<v[i].size();j++)
      {
        if(flag == 0)
        {
          x = b[v[i][j]];
          if(i+'a' != x)
            tot++;
          flag = 1;
        }
        else
        {
          if(b[v[i][j]]!=x)
          {
           //cout << "hi" << endl;
            ans = 0;
            break;
          }
        }  
      }
      if(v[i].size()>=1)
      {
              if(mp.find(b[v[i][0]])!=mp.end())
              {
                           // cout << "hi1" << b[v[i][0]]<<i << endl;
                ans = 0;
              }
              else
                mp[b[v[i][0]]] = 1;
      }
      if(ans == 0)
        break;
      
    }
    //cout << ans << endl;
    if(ans == -1)
    {
      //cout << "HI" << endl;
      if(cnt == 26&&tot > 0)
        ans = 0;
      else
        ans = 1;
    }
    ans == 0 ? cout << "NO" : cout << "YES" ;
    cout << endl;
    for(int i=0;i<26;i++)
      v[i].clear();
    memset(arr,0,sizeof(arr));
    mp.clear();
  }
}

