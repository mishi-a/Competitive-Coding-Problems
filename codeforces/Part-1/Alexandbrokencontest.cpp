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
std::vector<string> v = {"Danil","Olya","Slava","Ann","Nikita"};

int solve(string s,string t)
{
	int cnt = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==t[0])
		{
			int p = 1;
			for(int j=1;j<t.length();j++)
			{
              if(t[j]!=s[i+j])
              	break;
              p++;
			}
			if(p == t.length())
				cnt++;
		}
	}
    return cnt;
}

int main()
{
  sync;
  string s;
  cin >> s;
  
  int cnt = 0;
  for(int i=0;i<v.size();i++)
  {
    cnt = cnt + solve(s,v[i]);
    //cout << cnt << endl;
  }
  cnt != 1 ? cout << "NO" : cout << "YES" << endl;
}
