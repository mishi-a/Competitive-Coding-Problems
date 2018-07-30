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
int ended;
map <pair<string,int> , int > mp;
bool check(string expr)
{
    stack<char> s;
    //cout << expr << endl;
    char a, b, c;
    //Traversing the Expression
    for(int i=0;i<expr.length();i++)
    {
        if(expr[i]=='{')
        {
           //Push the element in the stack
           s.push(expr[i]);
        }
        else
         {
             if(s.empty())
                return false;
             //Store the top element in b
             b=s.top();
             s.pop();
         }
    }
    //Check Empty Stack
    if(s.empty())
      return true;
    else
      return false;
   
}

int solve(int start,string s)
{
  int res;
  if(mp.find({s,start})!=mp.end())
    return mp[{s,start}];
  if(check(s))
  {
    return 0;
  }
  if(start > ended)
  {
    return 100000000;
  }
  else
  {
    string p = s;
    if(p[start] == '{')
       p[start] = '}';
    else
       p[start] = '{';
    //cout << p << " - " <<  endl;
    res = min(1+solve(start+1,p),solve(start+1,s));
  }
  mp[{s,start}] = res;
  return res;
}

int main()
{
  sync;
  while(1)
  {
    string s;
    cin >> s;
    if(s[0] == '-')
      break;
    ended = s.length()-1;
    int res  = solve(0,s);
    cout << res << endl;
    mp.clear();
  }
}

