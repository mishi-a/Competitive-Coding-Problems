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

int findLength(string s)
{
	int arr[s.size()];
	int mux = -1;
	arr[0] = 1;
	for(int i=1;i<s.size();i++)
	{
		if(s[i] != s[i-1])
			arr[i] = arr[i-1]+1;
		else
			arr[i] = 1;
		mux = max(arr[i],mux);
	}
	return mux;
}

int main()
{
  sync;
  string s;
  cin >> s;
  int ans = 1;
  while(s[0]!=s[s.size()-1])
  {
  	int idx = 0;
  	for(int i=1;i<s.size();i++)
  	{
  		if(s[i]!=s[i-1])
  			idx++;
  		else
  			break;
  	}
  	string s1 = s;
  	if(idx == s.size()-1)
  		break;
  	reverse(s.begin(),s.begin()+idx+1);
  	reverse(s.begin()+idx+1,s.end());
  	ans = max(ans,findLength(s));
  	if(s == s1)
  		break;
  }
  cout << max(ans,findLength(s)) << endl;

}
