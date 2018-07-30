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

int P[1000005];

int main()
{
  sync;
  int n,a,b;
  cin >> n >> a >> b;
  int idx=-1;
  for(int i=0;i<=n;i++)
  {
  	if(i%a==0 && (n-i)%b==0)
  	{
  		idx = i;
  		break;
  	}
  }
  //cout << idx << endl;
  if(idx == -1)
  {
  	cout << idx << endl;
  }
  else
  {
  	int val = idx/a;
  	int start = 1;
  	while(val--)
  	{
  		int x = start;
  		for(int i=1;i<a;i++)
  			P[start]=start+1,start++;
  		P[start] = x;
  		start++;
  	}
  	val = (n-idx)/b;
  	while(val--)
  	{
  		int x = start;
  		for(int i=1;i<b;i++)
  			P[start]=start+1,start++;
  		P[start] = x;
  		start++;
  	}
    for(int i=1;i<=n;i++)
    	cout << P[i] << " ";
  }


}
