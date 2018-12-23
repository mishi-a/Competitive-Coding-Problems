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
double arr[10005][30];
int prob[30][2];
map<pii,int> mp;
bool acompare(pair<double,pair<double,int>>& a,pair<double,pair<double,int>>& b)
{
	if(a.FI-b.FI>1e-7)
		return true;
	if(b.FI-a.FI>1e-7)
		return false;
	if(abs(a.FI-b.FI)<=1e-7)
	{
		if(a.SE.FI-b.SE.FI>1e-7)
			return true;
		if(b.SE.FI-a.SE.FI>1e-7)
			return false;
		if(abs(b.SE.FI-a.SE.FI)<=1e-7)
		{
			if(a.SE.SE>b.SE.SE)
				return false;
			else
				return true;
		}

	}
}
int main()
{
  sync;
  int p;
  cin >> p;
  for(int i=0;i<p;i++)
  {
  	char id;
  	int ps,t;
  	cin >> id >> ps >> t;
  	prob[id-'A'][0]=ps;
  	prob[id-'A'][1]=t;
  }
  int u,su;
  cin >> u >> su;
  for(int i=0;i<su;i++)
  {
  	int user;
  	cin >> user;
  	char id;
  	cin >> id;
  	int cnt=0;
  	int sid;
  	cin >> sid;
  	//cerr << sid << prob[id-'A'][1] << endl;
  	for(int j=0;j<prob[id-'A'][1];j++)
  	{
  		string s;
  		cin >> s;
  		//cout << s << endl;
  		if(s == "A")
  			cnt++;
  	}
  	if(cnt == prob[id-'A'][1])
  	{
  		arr[user][id-'A'] = prob[id-'A'][0];
  	}
  	else
  	{
  		arr[user][id-'A'] = max(arr[user][id-'A'],(prob[id-'A'][0]/(1.0*prob[id-'A'][1]))*cnt*1.0);	
  	}
  }
  vector<pair<double,pair<double,int>>> v;
  for(int i=0;i<=u;i++)
  {
  	double FullScore = 0,partScore=0;
  	for(int j=0;j<p;j++)
  	{
  		if(abs(arr[i][j]-prob[j][0])<=1e-7)
  			FullScore += arr[i][j];
  		else
  			partScore += arr[i][j]; 
  	}
  	v.pb({FullScore,{partScore,i}});
  }
  sort(v.begin(),v.end(),acompare);
  int print = 0;
  //cout << fixed << setprecision(2);
  for(unsigned i=0;i<v.size();)
  {
    if (v[i].SE.FI <1e-7 && v[i].FI < 1e-7)
      break;
  	cout << print+1 << " " << v[i].SE.SE << " " << v[i].FI << " " << v[i].SE.FI << endl;
  	unsigned j=i+1;
  	int rank = print+1;
  	print++;
  	while(j<v.size() && abs(v[j].FI-v[i].FI)<=1e-7 && abs(v[j].SE.FI-v[i].SE.FI)<=1e-7 )
  	{
  		cout << rank << " " << v[j].SE.SE << " " << v[j].FI << " " << v[j].SE.FI << endl;
  		j++;
  		print++;
  	}
  	i = j;
  }
}
