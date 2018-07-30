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
vector <int> v2;
int arr[1020] = {0};
int arr1[1020] = {0};
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
  int cnt = 0;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v1.pb(a);
    if(a ==v[i])
    {
       arr[a] = 1;
    }
    else
      cnt++;
  }
  if(cnt == 1)
  {
    int ind;
    for(int i=1;i<=n;i++)
    {
      if(arr[i]!=1)
      {
        ind = i;
        break;
      }
    }
    for(int i=0;i<n;i++)
    {
      if(v[i] == v1[i])
        cout << v[i] << " ";
      else
        cout << ind << " ";
    }
  }
  else
  {
    vector <int> x;
    for(int i=1;i<=n;i++)
    {
      if(arr[i] == 0)
        x.pb(i);
    }
    int x1 = x[0];
    int x2 = x[1];
    int cnt = 0;
    int ind1,ind2;
    for(int i=0;i<n;i++)
    {
      if(v[i] == v1[i])
       v2.pb(v[i]);
      else  
      {
        if(cnt == 0)
        {
          v2.pb(x1);
          ind1 = i;
          cnt++;
        }
        else
        {
          v2.pb(x2);
          ind2 = i;
        }
      }
    }
    if((v2[ind1] == v1[ind1] && v2[ind1]!=v[ind1]) && (v2[ind2] == v[ind2] && v2[ind2]!=v1[ind2]))
    {
       for(int i=0;i<n;i++)
       {
         cout << v2[i] << " ";
       }
       return 0;
    
    }
    if((v2[ind2] == v1[ind2] && v2[ind2]!=v[ind2]) && (v2[ind1] == v[ind1] && v2[ind1]!=v1[ind1]))
    { 
        for(int i=0;i<n;i++)
       {
         cout << v2[i] << " ";
       }
       return 0;
    
    }
    int a = v2[ind2];
    v2[ind2] = v2[ind1];
    v2[ind1] = a;
     for(int i=0;i<n;i++)
       {
         cout << v2[i] << " ";
       }
       return 0;
    
  }
  
}

