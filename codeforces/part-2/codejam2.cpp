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

int arr[100005];
int arr1[100005];
int arr2[100005];
int main()
{
  sync;
  int t;
  cin >> t;
  int p = 0;
  while(t--)
  {
  	p++;
  	int n;
  	int cnt=0,cnt1=0;
  	cin >> n;
  	for(int i=0;i<n;i++)
  	{
  		if(i%2 == 0)
  		{
  			cin >> arr[cnt];
  			cnt++;
  		}
  		else
  		{
  			cin >> arr1[cnt1];
  			cnt1++;
  		}
  	}
  	
  	sort(arr,arr+cnt);
  	sort(arr1,arr1+cnt1);

  	int i=0,j=0,k=0;
  	while(1)
  	{
  		if(i<cnt)
  		{
  			arr2[k]=arr[i];
  			k++;
  			i++;
  		}
  		else
  			break;
  		if(j<cnt1)
  		{
  			arr2[k] = arr1[j];
  			j++;
  			k++;
  		}
  	}

  	int idx = -1;
  	for(int i=0;i<n-1;i++)
  	{
  		if(arr2[i]>arr2[i+1])
  		{
  			idx = i;
  			break;
  		}
  	}
  	if(idx == -1)
  	{
  		cout << "case #"<<p << ": OK" << endl;
  	}
  	else
  	{
  		cout << "case #"<<p << ": " << idx << endl;
  	}
  }

}
