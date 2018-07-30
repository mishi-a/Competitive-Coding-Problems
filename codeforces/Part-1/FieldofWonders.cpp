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
	if(par[y] < par[x])	// balancing the height of the trees
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/
		

using namespace std;

vector <string> v;
string s;
int used[27],freq[27],freq1[27];

int solve(int idx)
{
	char c = 'a'+idx;
	int cnt = 0;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j]==c)
			{
				cnt++;
				break;
			}
		}
	}
	if(cnt == v.size())
		return 1;
    else
    	return 0;
}

int main()
{
  sync;
  int n;
  //cout << "hi" << endl;
  cin >> n;
  cin >> s;
  for(int i=0;i<s.length();i++)
  {
  	if(s[i]=='*')
  		continue;
    used[s[i]-'a']=1;
    freq[s[i]-'a']++;
  }
  int m;
  cin >> m;
  for(int i=0;i<m;i++)
  {
    string t;
    int flag = 0;
    cin >> t;
    memset(freq1,0,sizeof(freq1));
    for(int j=0;j<t.length();j++)
    {
      if(s[j]!='*' && s[j]!=t[j])
      {
      	flag = 1;
      	break;
      }
      freq1[t[j]-'a']++;
      if(freq1[t[j]-'a']>freq[t[j]-'a'] && freq[t[j]-'a']!=0)
      {
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    	v.pb(t);
  }
  int ans = 0;
  for(int i=0;i<26;i++)
  {
  	if(used[i]==0)
  	{
      ans += solve(i);
  	}
  }
  cout << ans << endl;
  return 0;
}
