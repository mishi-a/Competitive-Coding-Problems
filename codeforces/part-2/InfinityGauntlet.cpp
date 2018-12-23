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

int main()
{
  sync;
  int n;
  cin >> n;
  cout << 6-n << endl;
  set<string> s;
  for(int i=0;i<n;i++)
  {
  	string s1;
  	cin >> s1;
  	s.insert(s1);
  }
  map<string,string> m;
  m.insert({"Power","purple"});
  m.insert({"Time","green"});
  m.insert({"Space","blue"});
  m.insert({"Soul","orange"});
  m.insert({"Reality","red"});
  m.insert({"Mind","yellow"});

  map<string,string> :: iterator itr = m.begin();
  while(itr!=m.end())
  {
  	if(s.find(itr->second)==s.end())
  		cout << itr->FI << endl;
  	itr++;
  }
}
