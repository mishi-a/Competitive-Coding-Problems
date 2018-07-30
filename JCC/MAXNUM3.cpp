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
vector <string> v;
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	string s;
  	cin >> s;
  	if((s[s.length()-1]-'0')%2==1)
  	{
  	  int sum=0;
      for(int i=0;i<s.length()-1;i++)
      	sum+=(s[i]-'0');
      if(sum%3==0&&(s[s.length()-2]-'0')%2==0)
      	cout << s.substr(0,s.length()-1) << endl;
      else
      	cout << "-1" << endl;
  	}
  	else
  	{
      int sum=0;
      for(int i=0;i<s.length();i++)
      	sum+=(s[i]-'0');
      string mux = "a",x;
      int cnt = 0;
      for(int i=0;i<s.length();i++)
      {
      	if((sum-(s[i]-'0'))%3==0)
      	{
      	  if(i==s.length()-1)
      	  {
      	  	if((s[s.length()-2]-'0')%2!=0)
      	  		continue;
      	  }
      	  if(i!=0)
           x = (s.substr(0,i)+s.substr(i+1));
          else
           x = (s.substr(i+1));
          if(cnt == 0)
          	mux = x;
          else
          {
          	if(x>mux)
          		mux = x;
          }
          cnt++;
      	}
      }
      //sort(v.begin(),v.end());
      if(mux!="a")
      cout << mux << endl;
      else
      	cout << "-1" << endl;
      v.clear();
  	}
  }
}
