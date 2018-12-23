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

int empty[MAX],leftEmp[MAX];
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int lidx = -1;
	empty[n-1] = (s[n-1]=='.');
	if(s[n-1]=='#')lidx = n-1;
	for(int i=s.size()-2;i>=0;i--)
	{
		if(s[i+1] == '.')
			empty[i] = empty[i+1]+(s[i]=='.');
		else
			empty[i] = (s[i]=='.');
		if(lidx == -1 && s[i] == '#')
			lidx = i;
	}
	for(int i=0;i<n;i++)
	{
		if(i == 0)
			leftEmp[i] = (s[i]=='.');
		else
		{
			if(s[i-1] == '.')
				leftEmp[i] = leftEmp[i-1]+(s[i]=='.');
			else
				leftEmp[i] = (s[i]=='.');
		}
	}	
	// cerr << s << endl;
	// for(int i=0;i<s.size();i++)
	// 	cerr << leftEmp[i] << " " << empty[i] << endl;
	int ans = 0,shift = 0,tshift=0;
	for(int i=0;i<n;)
	{
		//cerr << i << endl;
		int cnt = 0;
		int j=i;
		while(s[j] == s[j+1] && s[j] == '#')
			cnt++,j++;
		// if(i == 8)
		// 	cerr << cnt << endl;
		if(cnt > 0 && i!=0)
		{
			//cerr << j << endl;
			if(empty[j]>cnt)
			{
				ans+=((shift+cnt)*(shift+cnt+1))/2;
				//cerr << "hi " << j << " " << shift << " " << ans << " " << empty[j] << endl;
			}
			else
			{
				shift += cnt+1-empty[j];
				empty[lidx]-=shift;
				if(empty[lidx] <= 0)
				{
					cout << -1 << endl;
					return;
				}
				ans+=((shift+cnt)*(shift+cnt+1))/2;
			}
		}
		i = j+1;
	}
	//cerr << ans << endl;
	int j=0;
	for(int i=0;i<1;i++)
	{
		while(s[j] == s[j+1] && s[j] == '#')
			j++;
	}
	j++;
	for(int i=j;i<s.size()-1;i++)
	{
		if(leftEmp[i]==0)
			leftEmp[i]=1;
		//else
		//	leftEmp[i]-=1;
	}
	/*cerr << "hi";*/
	
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '#')
		{
			if(s[i-1] == '#' && i!=0)
			{
				leftEmp[i]+=sum;
			}
			else
			{
				sum+=leftEmp[i];
				leftEmp[i]=sum;	
			}
			
		}
	}
	// for(int i=0;i<s.size();i++)
	// 	cerr << leftEmp[i] << " " << empty[i] << endl;
	for(int i=0;i<n;i++)
		if(s[i] == '#')
			ans+=leftEmp[i];
	if(lidx == n-1 && ans!=0)
	{
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
	memset(empty,0,sizeof(empty));
	memset(leftEmp,0,sizeof(leftEmp));

}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	solve();
  }
}
