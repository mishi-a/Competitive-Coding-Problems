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
int freqa[5005],freqb[5005];

int main()
{
  sync;
  string s;
  cin >> s;
  for(int i=0;i<s.length();i++)
  {
  	if(s[i]=='a')
  		freqa[i]=1;
  	else
  		freqb[i]=1;
  }
  for(int i=1;i<s.length();i++)
  	freqa[i]+=freqa[i-1],freqb[i]+=freqb[i-1];
  int ans = -1;
  ans = max(freqa[s.length()-1],freqb[s.length()-1]);
  //cout << ans << endl; 
  if(s.length()>2){
  for(int i=0;i<s.length()-2;i++)
  {
  	for(int j=i+1;j<s.length()-1;j++)
  	{
       ans = max(ans,(freqa[i]+(freqb[j]-freqb[i])+freqa[s.length()-1]-freqa[j]));
       //cout << i << " " << j << " " << ans << endl;
  	}
  }}
   //cout << ans << endl;

  if(s.length()>1){
  for(int i=0;i<s.length();i++)
  {
  	ans = max(ans,freqa[i]+freqb[s.length()-1]-freqb[i]);
  	ans = max(ans,freqb[i]+freqa[s.length()-1]-freqa[i]);
  } }
  cout << ans << endl;
}
