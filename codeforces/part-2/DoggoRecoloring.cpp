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

int arr[30];
int main()
{
  sync;
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i=0;i<n;i++)
  {
  	arr[s[i]-'a']++;
  }
  if(n == 1)
  {
  	cout << "Yes" << endl;
  	return 0;
  }
  for(int i=0;i<26;i++)
  {
  	if(arr[i]>=2)
  	{
  		cout << "Yes" << endl;
  		return 0;
  	}
  }
  cout << "No" << endl;

}
