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
vector <int> v1;
vector <int> ind;
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  int k;
  cin >> k;
  for(int i=0;i<k;i++)
  {
    int a;
    cin >> a;
    v1.pb(a);
  }
  int sum = 0;
  int x = 0;
  int p;
  int flag = 0;
  for(int i=0;i<n;i++)
  {
    if(sum == 0)
      p = v[i];
    sum = sum+v[i];
    if(v[i]!=p)
      flag = 1;
    if(v1[x] == sum)
    {
      if(v[i] == sum)
        flag = 1;
      if(flag == 1)
      {
        ind.pb(i);
        sum = 0;
        flag = 0;
        x++;
      }
      else
       break;
    }
  }
  if((x != k && flag == 0) || ind.size()!=k)
    cout << "NO" << endl;
  else
  {
    int start = 0;
    int tot = 0;
    cout << "YES" << endl;
    for(int i=0;i<k;i++)
    {
      int mux = -1;
      int loc = -1;
      for(int j=start;j<=ind[i];j++)
      {
        if(v[j]>mux)
        {
          mux = v[j];
          loc = j;
        }
      }
      int j;
      if(j == start)
      {
        while(v[j] >= mux && j <=ind[i])
        {
          loc = j;
          j++;
        }
      }
      int cnt = 0;
      while(i==0 ?loc > i : loc-ind[i-1]+i-1 > i)
      {
        cout << (i==0 ?loc+1 : loc+1 -ind[i-1]+i-1) << " L" <<endl;
        loc--;
        cnt++;
      }
      int cnt1 = 0;
      while(i==0 ? cnt < ind[i] : cnt < ind[i]-ind[i-1]-1)
      {
        cout << i+1 << " R" << endl;
        cnt++;
        cnt1++;
      }
      start = ind[i]+1;
      
    }
  }
}

