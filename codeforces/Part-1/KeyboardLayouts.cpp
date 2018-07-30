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
char a1[27],b1[27];
int main()
{
  sync;
  string a,b,c;
  cin >> a >> b >> c;
  for(int i=0;i<a.length();i++)
  {
    if(a[i]<'a')
      a[i]+=32;
    a1[a[i]-'a'] = a[i];
    b1[a[i]-'a'] = b[i];
  }
  for(int i=0;i<c.length();i++)
  {
    int flag = 0;
    if(c[i] >= '0' && c[i] <= '9')
    {
      cout << c[i] ;
      continue;
    } 
    if(c[i]<'a')
    {
      c[i]+=32;
      flag = 1;
    }
    
    flag == 0 ? cout << b1[c[i]-'a']  : cout << char(b1[c[i]-'a']-32) ;
  }
}

