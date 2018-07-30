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

int f[12];
string res = "";
void check(int num,int len)
{
  
  int x = num%10;
  int y = (num/10)%10;
  int z = (num/100);
  f[x]--,f[y]--,f[z]--;
  if(f[x] <0 || f[y]<0 || f[z]<0)
  {
    f[x]++,f[y]++,f[z]++;
    return;
  }
  int idx=10;
  for(int i=1;i<10;i++)
  {
    if(f[i]!=0)
    {
      idx = i;
      break;
    }
  }
  string k = "";
  int flag = 0;
  for(int i=idx;i<10;i++)
  {
    char t = (char)(i+48);
    
    if(flag == 0)
    {
      k = k+t;
      k = k+ string(f[0],'0');
      k = k+string(f[i]-1,t);
      flag = 1;
      continue;
    }
    k  += string(f[i],t);
  }
  //cout << k << endl;
  k += (char)(z+48);
  k += (char)(y+48);
  k += (char)(x+48);
  //cout << k << endl;
  if(k[0] == '0' || k.length()!=len)
  {
      f[x]++,f[y]++,f[z]++;
      return;
  }
  if(k<res)
    res = k;
  f[x]++,f[y]++,f[z]++;
  
}

int main()
{
  sync;
  string s;
  cin >> s;
  res = string(505,'9');
  string p = res;
  //    out << res << endl;
  for(int i=0;i<s.length();i++)
  {
    f[s[i]-'0']++;
  }
  if(s.length() == 1)
  {
    if(s[0]=='0' || s[0] == '8')
    {  res = s;
    cout << res  << endl;
    return 0;}
    cout << -1  << endl;
    return 0;
  }
  if(s.length()==2)
  {
    for(int i=16;i<99;i+=8)
    {
      int x = i%10;
      int y = i/10;  
      if(f[x]>0 && f[y]>0)
      {
        cout << i << endl;
        return 0;
      } 
    }
    cout << -1  << endl;
    return 0;
  }
  if(s.length()>=3)
  {
    for(int i=0;i<999;i+=8)
    { 
      check(i,s.length());
    }
  }
  if(p!= res)
   cout << res << endl;
  else
   cout << -1  << endl;
}

