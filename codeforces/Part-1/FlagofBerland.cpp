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
int n,m;
char arr[105][105];

bool check(char ch, int flag)
{
  int tot;
  if(flag == 1)
  {
    tot = n/3;
    int idx=n+1;;
    for(int i=0;i<n;i++)
    {
      if(arr[i][0] == ch)
      {
        idx = i;break;}
    }
    int cnt = 0;
    for(int i=idx;i<idx+(tot)&&i<n;i++)
    {
      cnt++;
      for(int j=0;j<m;j++)
      {
      
        if(arr[i][j] !=ch)
          return false;
      }
    }
    if(cnt!=(tot))
      return false;
    else
      return true;
  }
  else
  {
    tot = m/3;
    int idx=m+1;
    for(int i=0;i<m;i++)
    {
      if(arr[0][i] == ch)
      {  idx = i;break;}
    }
    int cnt = 0;
    for(int i=idx;i<idx+(tot)&&i<m;i++)
    {
      cnt++;
      for(int j=0;j<n;j++)
      { 
        if(arr[j][i] !=ch)
          return false;
      }
    }
    if(cnt!=(tot))
      return false;
    else
      return true;
  }
}

int main()
{
  sync;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> arr[i][j];
    }
  }
  if(n%3!=0 && m%3!=0)
  {
    cout <<"NO" << endl;
    return 0;
  }
  if(n%3==0)
  {
    if(check('R',1) && check('B',1) && check('G',1))
    {
      cout << "YES" << endl; 
      return 0;
    }
  }
  if(m%3==0)
  {
    if(check('R',0) && check('B',0) && check('G',0))
    {
      cout << "YES" << endl; 
      return 0;
    }
  }
  cout << "NO" << endl;
}

