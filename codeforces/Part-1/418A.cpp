/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
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
using namespace std;
vector <int> v;
vector <int> v1;
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  int cnt = 0,cnt1 = 0;
  int ind;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
    if(a==0) cnt++;
    if(a==0)
      ind = i;
  }
  for(int i=0;i<k;i++)
  {
    int a;
    cin >> a;
    v1.pb(a);
    if(a == 0)
    {
      cnt1++;
    }
    
  }
  if(v1.size() > 1 && cnt > 1)
  {
     cout << "YES" << endl;
     return 0;
  }
  if(cnt == 1)
  {
    if(ind==0)
    {
      int a = v[1];
      for(int i=0;i<v1.size();i++)
      {
        if( v1[i] > a)
        {
          cout << "YES" << endl;
          return 0;
        }
      }
      for(int i=2;i<n;i++)
      {
        if(v[i] < v[i-1])
        {
           cout << "YES" << endl;
          return 0;
        }
      }
      cout << "NO" << endl;
      return 0;
    }
    else if(ind==n-1)
    {
       int a = v[n-2];
       for(int i=0;i<v1.size();i++)
       {
         if(v1[i] < a)
         {
           cout << "YES" << endl;
           return 0;
         }
       }
       for(int i=1;i<n-1;i++)
       {
          if(v[i] < v[i-1])
          {
            cout << "YES" << endl;
            return 0;
          }
       }
       cout << "NO" << endl;
       return 0;
    }
    else
    {
      int a = v[ind-1];
      int b = v[ind+1];
       for(int i=0;i<v1.size();i++)
       {
         if(v1[i] < a || v1[i] > b)
         {
           cout << "YES" << endl;
           return 0;
         }
       }
       for(int i=1;i<ind;i++)
       {
          if(v[i] < v[i-1])
          {
            cout << "YES" << endl;
            return 0;
          }
       }
       for(int i = ind+2;i<n;i++)
       {
           if(v[i] < v[i-1])
          {
            cout << "YES" << endl;
            return 0;
          }
       }
       cout << "NO" << endl;
       return 0;
      
    }
  }
  for(int i=1;i<n;i++)
  {
    if(v[i] < v[i-1])
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

