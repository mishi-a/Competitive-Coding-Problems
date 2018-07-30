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
int arr[200005];
int freq[200005]={0};
bool pre[200005];
vector<int> v;
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> arr[i];
    freq[arr[i]]++;
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(freq[i]==0)
    {
      v.pb(i);
      cnt++;
    }
  }
  cout << cnt << endl;
  int p=0;
  int i=0;
  while(i<n&&p<v.size())
  {
    if(freq[arr[i]]>=1 )
    { 
      if(freq[arr[i]]==1 && pre[arr[i]]==false)
      {
        pre[arr[i]]=true;
        i++;
        continue;
      }
      if(pre[arr[i]]==true)
      {
        arr[i]=v[p];
        p++;
      }
      else if(v[p]>arr[i])
      {
        pre[arr[i]]=true;
        freq[arr[i]]--;
      }
      else
      {freq[arr[i]]=freq[arr[i]]-1;
      arr[i]=v[p];
      pre[v[p]]=true;
      p++;
      }
    }
    if(p>=cnt)
      break;
    i++;
  }
  for(int i=0;i<n;i++)
  {
   cout << arr[i] << " ";
  }
}

