/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int arr[20][110];

int find(int h,int w,int dir)
{
  int a = 0,res;
  for(int i=0;i<=w;i++)
  { 
      
      if(arr[h][i] == 1 && dir == 0)
      {
        a = i;
      }
      else if(arr[h][i] == 1 && dir == 1)
      {
        a = i;
        break;
      }
  }
  if(h==0)
  {
    if(a == 0) return 0;
    else if(dir == 0)
      return a;
    else
      return w-a;
  }
  int sum = 0;
  for(int i = h-1;i>=0;i--)
    for(int j=0;j<=w;j++)
       sum +=arr[i][j];
  if(sum == 0)
  {
    if(a == 0) return 0;
    else if(dir == 0)
      return a;
    else
      return w-a;
  }
  if(dir == 0)
  {
    res = min(a+a+1+find(h-1,w,0),w+1+find(h-1,w,1));
  }
  else
  {
    res = min(w+1+find(h-1,w,0),a!=0 ? w-a+w-a+1+find(h-1,w,1) : 1 +find(h-1,w,1) );
  }
  return res;
}

int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<k+2;j++)
    {
      char a;
      cin >> a;
      arr[i][j] = a-'0';
    }
  }
  int res = find(n-1,k+1,0);
  cout << res << endl;
}

