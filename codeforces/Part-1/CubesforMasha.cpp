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
set <int> v[4];
int n;
int arr[4][4];
int flag = 0;
void recur(int idx,set<int>s)
{
	if(flag==1)
				return;
	if(idx>2)
		return;
	else
	{
		for(int i=0;i<3;i++)
		{
			if(arr[idx][i]==1&&s.find(i)==s.end())
			{
				if(idx == 2)
				{
					flag = 1;
					return;
				}
				s.insert(i);
				recur(idx+1,s);
				if(flag == 1)
					return;
				s.erase(i);
			}
			if(flag==1)
				return;
		}
	}
}
bool check(int num)
{
	//cout << num << endl;
	vector <int> x;
	while(num!=0)
	{
		x.pb(num%10);
		num/=10;
	}
	memset(arr,0,sizeof(arr));
    for(int i=0;i<x.size();i++)
    {
      for(int j=0;j<n;j++)
      {
      	if(v[j].find(x[i])!=v[j].end())
      		arr[j][i]=1;
      }
    }
    if(x.size()==1)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(arr[j][0]==1)
               return false;
    	}
    	return true;
    }
    if(x.size()==2)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(arr[j][0]==1)
    		{
    			for(int k=j+1;k!=j;k=(k+1)%n)
    			{
    				if(arr[k][1]==1)
                        return false;
    			}
    		}
    		if(arr[j][1]==1)
    		{
    			for(int k=j+1;k!=j;k=(k+1)%n)
    			{
    				if(arr[k][0]==1)
                        return false;
    			}
    		}

        }
        return true;
    }
    if(x.size()==3 &&n==3)
    {
      set <int> s;
      for(int i=0;i<3;i++)
      {
      	if(arr[0][i]==1)
      	{
      		s.insert(i);
      		recur(1,s);
      		if(flag == 1)
      	    {flag =0;
      	    		return false;
      	    	}
            s.erase(i);
      	}
      }
      flag = 0;
      return true;
    }
}
int main()
{
  sync;
  int a;
  cin >> n;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<6;j++)
  	{
  		cin >> a;
  		v[i].insert(a);
  	}
  }
  for(int i=1;i<999;i++)
  {
  	if(check(i))
  	{
  		cout <<i-1 << endl;
  		break;
  	}
  }

}
