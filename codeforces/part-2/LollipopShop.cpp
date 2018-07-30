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
vector<int> v,v1;
int arr[500];
int freq[500];
int main()
{
  //sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
      int tot,a;
      cin >> tot;
      for(int i=0;i<tot;i++)
      {
        cin >> a;
        v.pb(a);
      }
      int flag = 0;
      for(int i=0;i<v.size();i++)
      {
        if(arr[v[i]]==0)
        {
          v1.pb(v[i]);
        }
      }
      if(v1.size()==0)
      {
        cout << "-1" << endl;
      }
      else
      {
        int val = INT_MAX;
        int idx = -1;
        for(int i=0;i<v1.size();i++)
        { 
          if(freq[v1[i]]<val)
          {
              val =freq[v1[i]];
              idx = v1[i];
          }
        }
        arr[idx]=1;
        cout << idx << endl;
      }
      for(int i=0;i<v.size();i++)
        freq[v[i]]++;      
      v1.clear();
      v.clear();
      fflush(stdout);
    }
      memset(arr,0,sizeof(arr));
      memset(freq,0,sizeof(arr));

  }
  

}
