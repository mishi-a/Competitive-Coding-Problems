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
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/


using namespace std;
int arr[100005],freq[300];
int taken[300],available[300];
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++)
  {
  	cin >> arr[i];
  	freq[arr[i]]++;
  }
  for(int i=0;i<n;i++)
  {
    int mun = 257;
    int flag = 0;
  	for(int j =arr[i];j>=0 && j>=arr[i]-k+1;j--)
    {
      if(available[j] == 1)
      {
        for(int l=j;l>=0;l--)
        {
          if(taken[l]==1)
          {
            if(l+k-1>=arr[i])
            {
              flag = 1;
              cout << l << " ";
              for(int m = l;m<=arr[i];m++)
                available[m]=1;
            }
            break;
          }
        }
        break;
      }
      if(taken[j] == 1)
      {
        flag = 1;
        cout << j << " ";
        for(int l=j;l<=arr[i];l++)
          available[l]=1;
        break;
      }
      mun = j;
    }
    if(flag == 0)
    {
      cout << mun << " ";
      for(int j=mun;j<=arr[i];j++)
        available[j]=1;
      taken[mun] = 1;
    }

  }

}
