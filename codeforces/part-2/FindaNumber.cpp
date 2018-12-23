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

struct state
{
	string st;
	int rem;
	int sum;
	state(string _st,int _rem,int _sum)
	{
		st = _st;
		rem = _rem;
		sum = _sum;
	}
};

int main()
{
  sync;
  int d,s;
  cin >> d >> s;
  queue <state> q;
  q.push(state("",0,0));
  while(!q.empty())
  {
  	state st = q.front();
  	q.pop();
  	if(st.sum>s)
  	{
  		cout << -1 << endl;
  		return 0;
  	}
  	if(st.rem == 0 && st.sum == s)
  	{
  		cout << st.st << endl;
  		return 0;
  	}
  	for(int i=0;i<10;i++)
  	{
  		string a = st.st + (char)(i+'0');
  		int r = ((st.rem*10)+i)%d;
  		int t = st.sum + i;
  		q.push(state(a,r,t));
  	}
  } 
}
