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

int main()
{
  sync;
  int n;
  cin >> n;
  while(n--)
  {int cnt=0,cnt1=0,cnt2=0;
  	bool U=false,l=false,d=false;
  	string s;
  	cin >> s;
  	for(int i=0;i<s.length();i++)
  	{
  		if(s[i]>='a' && s[i] <= 'z')
  			l = true,cnt++;
  		else if(s[i]>='A' && s[i] <='Z')
  			U = true,cnt1++;
  		else
  			d = true,cnt2++;
  	}
  	//cout << cnt << " " << cnt1 << " " << cnt2 << endl;
  	if(l == true && U == true && d == true)
  		cout << s << endl;
  	else if(l == false && U == false && d == true)
  		cout << "aA"+s.substr(2,s.length()-2) << endl;
  	else if(l == false && U == true && d == false)
  		cout << "a1"+s.substr(2,s.length()-2) << endl;
  	if(l == false && U == true && d == true)
  	{
  		int flag = 0;
  		if(cnt1>1)
  		{
  			for(int i=0;i<s.length();i++)
  			{
  				if(!flag && s[i]>='A' && s[i]<='Z')
  					cout << "a",flag=1;
  				else
  					cout << s[i];
  			}
  		}
  		else
  		{
  			for(int i=0;i<s.length();i++)
  			{
  				if(!flag && s[i]>='0' && s[i]<='9')
  					cout << "a",flag=1;
  				else
  					cout << s[i];
  			}
  		}
  		cout << endl;
  	}
  	if(l == true && U == false && d == false)
  		cout << "A1"+s.substr(2,s.length()-2) << endl;
  	if(l == true && U == false && d == true)
  	{
  		int flag = 0;
  		if(cnt>1)
  		{
  			for(int i=0;i<s.length();i++)
  			{
  				if(!flag && s[i]>='a' && s[i]<='z')
  					cout << "A",flag=1;
  				else
  					cout << s[i];
  			}
  		}
  		else
  		{
  			for(int i=0;i<s.length();i++)
  			{
  				if(!flag && s[i]>='0' && s[i]<='9')
  					cout << "A",flag=1;
  				else
  					cout << s[i];
  			}
  		}
  		cout << endl;
  	}
  	if(l == true && U == true && d == false)
  	{
  		int flag = 0;
  		if(cnt1>1)
  		{
  			for(int i=0;i<s.length();i++)
  			{
  				if(!flag && s[i]>='A' && s[i]<='Z')
  					cout << "1",flag=1;
  				else
  					cout << s[i];
  			}
  		}
  		else
  		{
  			for(int i=0;i<s.length();i++)
  			{
  				if(!flag && s[i]>='a' && s[i]<='z')
  					cout << "1",flag=1;
  				else
  					cout << s[i];
  			}
  		}
  		cout << endl;
  	}
  }
}
