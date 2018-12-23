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

const int MAX = 1e5;
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

int val[8];

int main()
{
  sync;
  int n;
  cin >>n;
  for(int i=0;i<8;i++)
  	val[i]=1e7;
  for(int i=0;i<n;i++)
  {
  	int c;
  	string vit;
  	cin>>c>>vit;
  	sort(vit.begin(),vit.end());
  	if(vit.size()==1)
  		val[vit[0]-'A']=min(c,val[vit[0]-'A']);
  	else if(vit  == "AB")
  		val[3] = min(c,val[3]);
  	else if(vit  == "BC")
  		val[4] = min(c,val[4]);
  	else if(vit  == "AC")
  		val[5] = min(c,val[5]);
  	else
  		val[6]=min(c,val[6]);
  } 
  int ans =val[0]+val[1]+val[2];
  ans = min(val[0]+val[4],ans);
  ans= min(ans,val[6]);
  ans = min(ans,min(val[3]+val[2],min(val[3]+val[4],val[3]+val[5])));
  ans = min(ans,val[4]+val[5]);
  ans = min(ans,val[5]+val[1]);
  if(ans >= 1e7)
  {
  	cout << "-1" << endl;
  	return 0;
  }
  cout<<ans<<endl;
}
