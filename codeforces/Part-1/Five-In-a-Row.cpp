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
char arr[15][15];
bool check(int r,int c)
{
  int tot = 1;
  int x = c;
  c--;
  while(c>=0)
  {
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
    c--;
  }
  c=x;
  c++;
  while(c<=9)
  {
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
    c++;
  }
   if(tot>=5)
     return true;
   tot = 1;
  int y=r;
  c = x;
  r--;
  while(r>=0)
  {
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
     r--; 
  }
  r=y;
  r++;
  while(r<=9)
  {
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
    r++;
  }
  if(tot>=5)
     return true;
   tot = 1;
  c = x;
  r = y;
  c--;
  r--;
  while(c>=0&&r>=0)
  { 
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
    c--;
    r--;
  }
  c = x;
  r = y;
  c++;
  r++;
  while(c<=9&&r<=9)
  {
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
    c++;
    r++;
  }
  if(tot>=5)
     return true;
   tot = 1;
  c = x;
  r = y;
  c++;
  r--;
  while(r>=0&&c<=9)
  {
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
    c++;
    r--;
  }
  c = x;
  r = y;
  c--;
  r++;
  while(r<=9&&c>=0)
  {
    if(arr[r][c] == 'X')
      tot++;
    else
      break;
    c--;
    r++;
  }
  if(tot>=5)
     return true;
  else
     return false;
  
}
int main()
{
  sync;
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      cin >> arr[i][j];
    }
  }
  bool res = false;
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      if(arr[i][j]=='.')
      {
        res = check(i,j);
        if(res == true)
        {
          cout << "YES" << endl;
          return 0;
        }
       }
    }
  }
  cout << "NO" << endl;
}

