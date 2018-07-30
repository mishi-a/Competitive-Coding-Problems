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
string s;
bool check(int num)
{
	//cout << num << endl;
	int arr[26]={0};
	for(int i=0;i<num;i++)
		arr[s[i]-'a']++;
	int arr1[26]={0};
	for(int i=0;i<26;i++)
		if(arr[i]==0)
           arr1[i]=1;
    for(int i=1;i<=s.length()-num;i++)
    {
    	arr[s[i-1]-'a']--;
        arr[s[i+num-1]-'a']++;
        if(arr[s[i-1]-'a']==0)
        	arr1[s[i-1]-'a']=1;
    }
    for(int i=0;i<26;i++)
    	if(arr1[i]==0)
    		return true;
    return false;
}

int dbs()
{
	int low = 1,high = s.length();
	int ans = high;
	while(low <= high)
	{
      int mid = (high+low)/2;
      if(check(mid))
      {
      	//cout << mid << endl;
      	ans = min(ans,mid);
      	high = mid-1;
      }
      else
      {
      	low = mid+1;
      }
	}
	return ans;
}

int main()
{
  sync;
  cin >> s;
  cout << dbs() << endl;
}
