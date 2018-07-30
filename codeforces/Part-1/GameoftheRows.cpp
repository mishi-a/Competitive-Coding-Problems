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

vector <int> v;

int main()
{
  sync;
  int n,k,a;
  cin >> n >> k;
  for(int i=0;i<k;i++)
  {
    cin >> a;
    v.pb(a);
  }
  for(int i=0;i<k;i++)
  {
    if(v[i]>=8)
    {
      n = n-(v[i]/8);
      v[i] = v[i]%8;
    }
  }
  //cout << n << endl;
  int cnt = 0;
  for(int i=0;i<k;i++)
  {
    if(v[i]>=4)
    {
      v[i] =v[i]%4;
      cnt++;
    }
    if(cnt%2==0 && cnt!=0)
      n--;
  }
  //cout << n << endl;
  if(cnt%2==1)
  {
    int flag = 0;
    for(int i=0;i<k;i++)
    {
      if(v[i] == 3)
      {
        v[i] = 0;
        n--;
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      int flag1 = 0;
      for(int i=0;i<k;i++)
      {
        if(v[i]==2)
        {
          flag1 = 1;
          n--;
          v[i] = 0;
          break;
        }
      }
      if(flag1==0)
      {
        int t = 0;
        for(int i=0;i<k;i++)
        {
          if(v[i] == 1)
          {
            v[i] = 0;
            t++;
          }
          if(t%2==0 && t!=0)
          {
            break;
          } 
        }
        n--;
      }
      else
      {
        for(int i=0;i<k;i++)
        {
          if(v[i]==1)
          {
            v[i] = 0;
            break;
          }
        }
      }
    }
  }
  int cnt1 = 0;
  for(int i=0;i<k;i++)
  {
    if(v[i]==3)
    {
      v[i] = 0;
      cnt1++;
    }
    if(cnt1%2==0 && cnt1!=0)
    {
     n--;
    }
  }
  if(cnt1%2==1)
  {
    int x = 0;
    for(int i=0;i<k;i++)
    {
      if(v[i]==2)
      {
       v[i]=0;
       x++;
      }
      if(x == 2)
      {
        n--;
        break;  
      }
    }
    if(x == 0)
    {
      int t=0;
      for(int i=0;i<k;i++)
      {
        if(v[i]==1)
        {
          v[i] = 0;
          t++;
        }
        if(t%2==0)
          break;
      }
      n--;
    }
    else if(x == 1)
    {
      for(int i=0;i<k;i++)
      {
        if(v[i]==1)
        {
          v[i]=0;
          break;
        }
      }
      n--;
    }
    
  }
  //cout << n << endl;
  cout << n << endl;
  int x = 0,y=0;
  for(int i=0;i<k;i++)
  {
    if(v[i]==2)
      x++;
    if(v[i]==1)
      y++;
  }
  int z = x/3;
  if(y>=z)
  {
    n-=z;
    y-=z;
    int p = x%3;
    if(p==2)
    {
      if(y>=2)
      {
        n--;
        y-=2;
      }
      else
      {
        n--;
        y = 0;
      }
    }
    else if(p==1)
    {
      if(y>=3)
      {
        y-=3;
        n--;
      }
      else
      {
        n--;
        y = 0;
      }
    }
    if(y>0)
    {
      int k = y/4;
      n-=k;
      if(y%4!=0)
       n--;
    }
  }
  else
  {
    n-=z;
    int p = x%3;
    if(p!=0)
      n--;
  }
  if(n<0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  
}

