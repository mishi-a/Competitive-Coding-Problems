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
ll arr[100005][27],arr1[100005];
map<string,int> mp;
vector<string>v,v1;
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
  	string s;
  	cin >> s;
  	v.pb(s);
  }
  int even = 0;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<v[i].size();j++)
  	{
  		arr[i][v[i][j]-'a']++;
  	}
  	int flag = 0;
  	string t = "";
  	for(int j=0;j<26;j++)
  	{
  		if(arr[i][j]%2 == 1)
  		{
  			flag = 1;
  			t += ('a'+j);
  		}
  	}
  	if(flag == 0)
  	{
  		even++;
  		arr1[i]=1;
  	}
  	else
  	{
  		arr1[i] = t.size()+1;
  	}
  	sort(t.begin(),t.end());
  	mp[t]++;
  	v1.pb(t);
  }
  ll ans = 0;
  /*cout << even << endl;
  cout << v1[0] << " " << v1[1] << " " << v1[2] << endl;
  cout << mp["cd"] << " " <<  endl;*/
  for(int i=0;i<n;i++)
  {
  	if(arr1[i] == 1)
  	{
  		ans += (even-1);
  		for(int i=0;i<26;i++)
  		{
  			string g(1,(char)('a'+i));
  			if(mp[g])
  				ans+=mp[g];
  		}
  	}
  	else if(arr1[i] == 2)
  	{
  		ans+=even;
  		ans+=(mp[v1[i]]-1);
  		string k = v1[i];
  		for(int i=0;i<26;i++)
  		{
  			string x = k+(char)('a'+i);
  			sort(x.begin(),x.end());
  			ans+=mp[x];
  		}
  	}
  	else
  	{
  		ans+=(mp[v1[i]]-1);
  		string k = v1[i];
  		for(int i=0;i<k.size();i++)
  		{
  			string p = k.substr(0,i)+k.substr(i+1,k.size()-(i+1));
  			sort(p.begin(),p.end());
  			//cout << "hi "<< p << "  " << ans << endl;
  			ans+=mp[p];
  		}
  		for(int i=0;i<26;i++)
  		{
  			string x = k+(char)('a'+i);
  			sort(x.begin(),x.end());
  			ans+=mp[x];
  		}
  	}
  	//cout << i << " " << ans << endl;
  }
  cout << ans/2 << endl;

}
