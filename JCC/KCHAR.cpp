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

int main()
{
  //sync;
  string s = "";
  while(s.length() <= 100000)
  {
    string t = s;
    reverse(t.begin(),t.end());
    for(ll i=0;i<t.length();i++)
    {
     if(t[i] == 'c')
      t[i] = 'a';
     else
      t[i] = 'c';
    }
    //cout << t << endl;
    s = s+"a"+t;
    //cout << s << endl;
  }
  //cout << s.length() << endl;
  ll t;
  cin >> t;
  while(t--)
  {
    ll k;
    cin >> k;
    if(k<=100000)
      cout << s[k-1] << endl;
    else
    {
      ll flag = 0;
      ll inv = 0;
      //cout << len << endl;
      char ans;
      while(flag!=1)
      {
        ll x = ceil(log2(k+1));
        //cout << x << endl;
        ll len = pow(2,x);
        len--;
        //cout << len << endl;
        if(k == (len+1)/2)
        {
          ans = 'a';
          flag = 1;
          break;
        }
        if(k<= 100000)
        {
          ans = s[k-1];
          flag = 1;
          break;
        }
        else if(k<(len+1)/2)
          continue;
        else
        {
          inv++;
          k =  len+1-k;  
          //len = (len-1)/2;
        }
      }
      //cout << inv << endl;
      if(inv%2 == 0)
      {
        //cout  << "hi1" << endl;
        cout << ans << endl;
      }
      else
      {//cout  << "hi" << endl;
        if(ans == 'c')
          cout << "a" << endl;
        else
          cout << "c" << endl;
      }
    }
    
  }
}

