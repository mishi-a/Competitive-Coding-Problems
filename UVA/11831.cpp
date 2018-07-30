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

char arr[105][105];

int main()
{
  sync;
  int n,m,s;
  while(1)
  {
    cin >> n >> m >> s;
    if(n==0 && m==0 && s==0)
      break;
    int init,a,b;
    
    for(int i=0;i<n;i++)
    { 
      for(int j=0;j<m;j++)
      {
        cin >> arr[i][j];
        if(arr[i][j]=='N')
        {
          a=i,b=j,init=0;
        }
        else if(arr[i][j]=='S')
        {
          a=i,b=j,init=2;
        }
        else if(arr[i][j]=='L')
        {
           a=i,b=j,init=1;   
        }
        else if(arr[i][j]=='O')
        {
           a=i,b=j,init=3;       
        }
      }
    }
    char c;
    int cnt=0;
    for(int i=0;i<s;i++)
    {
      cin >> c;
      if(c=='F')
      {
        if(init==0)
        {
          if(a-1>=0 && arr[a-1][b]!='#')
          {
            if(arr[a-1][b]=='*')
              cnt++,arr[a-1][b]='.';
            a--;
          }
        }
        else if(init ==1)
        {
          if(b+1<m && arr[a][b+1]!='#')
          {
            if(arr[a][b+1]=='*')
              cnt++,arr[a][b+1]='.';
            b++;
          }
        }
        else if(init == 2)
        {
          if(a+1<n && arr[a+1][b]!='#')
          {
            if(arr[a+1][b]=='*')
              cnt++,arr[a+1][b]='.';
            a++;
          }
        }
        else
        {
          if(b-1>=0 && arr[a][b-1]!='#')
          {
            if(arr[a][b-1]=='*')
              cnt++,arr[a][b-1]='.';
            b--;
          }
        }
      }
      else if(c=='D')
      {
        init = (init+1)%4;
      }
      else
      {
        init = (init-1);
        if(init<0)
          init = 3;
      }
    }
    cout << cnt << endl;
  }
}

