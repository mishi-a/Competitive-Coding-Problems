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

const int MAX = 2e5+7;
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
bool check(string s)
{
	//cerr << s << endl;
	int arr[27]={0};
	for(int i=0;i<s.size();i++)
		arr[s[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		if(arr[i] > s.size()/2)
			return false;
	}
	return true;
}
int main()
{
  sync;
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i=0;i<n-1;i++)
  {
  	if(s[i]!=s[i+1])
  	{
  		cout << "YES" << endl;
  		cout << s[i] << s[i+1] << endl;
  		return 0;
  	}
  }
  cout  << "NO" << endl;
}
