/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

const int MAX = 1e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
int arr[MAX],ans[MAX],idx[MAX];
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> arr[i],idx[arr[i]] = i;
  ans[n] = 2;
  for(int i=n-1;i>=1;i--)
  {
    int in = idx[i];
    //cerr << i << " " << in << endl;
    int j = in - i,flag = 0;
    while(j>=0)
    {
      if(ans[arr[j]]  == 2 && arr[j]>i)
      {
        flag = 1;
        break;
      }
      j-=i; 
    }
    j = in+i;
    while(flag == 0 && j<n )
    {
      if(ans[arr[j]]  == 2 && arr[j]>i)
      {
        flag = 1;
        break;
      }
      j+=i;
    }
    if(flag == 0)
    {
      ans[i] = 2;
    }
    else
      ans[i] = 1;
  }
  for(int i=0;i<n;i++)
  {
    if(ans[arr[i]] == 1)
      cout << "A";
    else
      cout<<"B";
  }
}