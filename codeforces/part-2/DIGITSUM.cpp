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
int arr[10][100005];
int recursum(int num)
{
  if(num/10 == 0)
    return num;
  else
  {
    int sum = 0;
    while(num!=0)
    {
     sum +=num%10;
     num/=10;
    }
    return(recursum(sum));
  }
}

void pre()
{
  for(int i=1;i<100001;i++)
  {
    int val = recursum(i);
    //cout << val << endl;
    arr[val][i]=1;
  }
}
int main()
{
  sync;
  pre();
  for(int i=1;i<=9;i++)
  {
    for(int j=1;j<100001;j++)
      arr[i][j]+=arr[i][j-1];
  }
  int t;
  cin >> t;
  while(t--)
  {
    int m,n,x;
    cin >> m >> n >> x;
    cout << arr[x][n]-arr[x][m-1] << endl;
  }
}
