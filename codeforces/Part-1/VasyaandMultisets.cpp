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

int arr[105],freq[105];
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
  	cin >> arr[i];
  	freq[arr[i]]++;
  }
  int num=0;
  for(int i=0;i<=100;i++)
  	if(freq[i]==1)
  		num++;
  if(num == 0)
  {
  	cout << "YES" << endl;
  	for(int i=0;i<n;i++)
  		cout << "A";
  }
  else if(num%2 == 0)
  {
  	cout << "YES" << endl;
  	int cnt=0;
  	for(int i=0;i<n;i++)
  	{
  		if(freq[arr[i]] == 1 && cnt!=num/2)
  		{
  			cout << "B" ;
  			cnt++;
  		}
  		else
  			cout << "A";
  	}
  }
  else
  {
  	int idx = -1;
  	for(int i=0;i<n;i++)
  	{
  		if(freq[arr[i]] > 2)
  		{
  			idx = i;
  			break;
  		}
  	}
  	if(idx == -1)
  		cout << "NO";
  	else
  	{
  		cout << "YES" << endl;
  		int cnt=0;
	  	for(int i=0;i<n;i++)
	  	{
	  		if(freq[arr[i]] == 1 && cnt!=num/2)
	  		{
	  			cout << "B" ;
	  			cnt++;
	  		}
	  		else if(i == idx)
	  			cout << "B";
	  		else
	  			cout << "A";
	  	}
  	}
  }

}
