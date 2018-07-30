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
int** arr;
int** dp;
int mux = 0,c,d;
map <pii , int > mp;

int rstart,cstart;

int solve(int rend,int cend)
{
  int tot;
 
  if(rstart > rend || cstart > cend)
    return 0;
  if(rstart == rend && cstart == cend)
  {
    if(1 > mux)
    {
      mux = 1;
      c = rend;
      d = rstart;
    }
    return 1; 
  }
   if(mp.find({rend,cend})!=mp.end())
    return mp[{rend,cend}]; 
  set<int> s;
  int cnt = 0;
  for(int i = rstart;i<=rend;i++)
  {
    for(int j = cstart;j<=cend;j++)
    {
      if(s.find(arr[i][j])!=s.end())
        s.erase(s.find(arr[i][j]));
      else
        s.insert(arr[i][j]);
      if(arr[i][j] != 0)
        cnt++;
    }
  }
  if(((rend-rstart+1)*(cend-cstart+1))&1)
  {
    int tot1 = -1,tot2 = -1 ,tot3 = -1;
    if(s.size() == 1 && cnt > 1)
      tot = (rend-rstart+1)*(cend-cstart+1);
    else
    {
      (mux < (rend-rstart+1)*(cend-cstart) || mux < (rend-rstart)*(cend-cstart+1)) ? tot1 = solve(rend,cend-1) : tot1 = -1  ;
      if(tot1 < (rend-rstart)*(cend-cstart+1) && mux < (rend-rstart)*(cend-cstart+1)&&tot1!=-1)
      {
        tot2 = solve(rend-1,cend);
        if(tot1 < (rend-rstart)*(cend-cstart) && tot2 < (rend-rstart)*(cend-cstart) && mux < (rend-rstart)*(cend-cstart)  )
        {
          tot3 = solve(rend-1,cend-1);
        }
      }
     tot = max(max(tot1,tot2),tot3);
    }
  }
  else
  {
    int tot1 = -1,tot2 = -1 ,tot3 = -1;
    if(s.size() == 0 && cnt > 1)
      tot = (rend-rstart+1)*(cend-cstart+1);
    else
    {
      (mux < (rend-rstart+1)*(cend-cstart) || mux < (rend-rstart)*(cend-cstart+1)) ? tot1 = solve(rend,cend-1) : tot1 = -1  ;
      if(tot1 < (rend-rstart)*(cend-cstart+1) && mux < (rend-rstart)*(cend-cstart+1) && tot1!=-1)
      {
        tot2 = solve(rend-1,cend);
        if(tot1 < (rend-rstart)*(cend-cstart) && tot2 < (rend-rstart)*(cend-cstart) && mux < (rend-rstart)*(cend-cstart+1))
        {
          tot3 = solve(rend-1,cend-1);
        }
      }
     tot = max(max(tot1,tot2),tot3);
    
    }
      
  }
  if(mux < tot)
  {
    mux = tot;
    c = rend;
    d = cend;
  }
  mp[{rend,cend}] = tot;
  return tot;
}

int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  arr = (int**)malloc(sizeof(int*)*n);
  for(int i=0;i<n;i++)
  {
    arr[i] = (int*)malloc(sizeof(int)*m);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> arr[i][j];
    }
  }
  int ans = -1;
  int a,b,x,y;
  for(int i=0;i<n;i++)
  {
    if(ans > (n-i)*(m))
        break;
    for(int j=0;j<n;j++)
    {
      rstart = i;
      cstart = j;
      int res = solve(n-1,m-1);
      if(ans < res)
      {
        a=i;
        b=j;
        x=c;
        y = d;
        ans = res;
      }
      mux = 0;
      mp.clear();
      if(ans > (n-rstart)*(m-cstart))
        break;
      
    }
  }
  cout << ans  << endl;
  cout << a << " " << b << " " << x << " " << y << endl;
}

