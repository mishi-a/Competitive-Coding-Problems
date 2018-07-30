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
int arr[15],arr1[15];
int main()
{
  sync;
  string s;
  while(cin>>s)
  {
  	int a=0;
    for(int i=0;i<s.length();i+=2)
       arr[a++]=(s[i]-'0');
    a = 0;
    for(int i=1;i<s.length();i+=2)
       arr1[a++]=(s[i]-'0');
    int cnta=0,cntb=0,flag=0;
    for(int i=0;i<5;i++)
    {
      cnta+=arr[i];
      if(cnta>cntb+(5-i))
      {
      	cout << "TEAM-A " << i+1+i << endl;
      	flag = 1;
      	break;
      }
      if(cntb>cnta+(5-i-1))
      {
      	cout << "TEAM-B " << i+1+i << endl;
      	flag = 1;
      	break;
      }
      cntb +=arr1[i];
      if(cntb>cnta+(5-i-1))
      {
      	cout << "TEAM-B " << i+1+i+1 << endl;
      	flag = 1;
      	break;
      }
      if(cnta>cntb+(5-i-1))
      {
      	cout << "TEAM-A " << i+1+i+1 << endl;
      	flag = 1;
      	break;
      }
    }
    if(flag==0)
    {
    	for(int i=5;i<=9;i++)
    	{
    		if(arr1[i]>arr[i])
    		{
    			cout << "TEAM-B " << 10+2*(i-4) << endl;flag=1;
    			break;
    		}
    		if(arr[i]>arr1[i])	
    		{
    			cout << "TEAM-A " << 10+2*(i-4) << endl;flag=1;
    			break;
    		}
    	}
    }
    if(flag==0)
    	cout << "TIE" << endl;
  }
 	  	  	