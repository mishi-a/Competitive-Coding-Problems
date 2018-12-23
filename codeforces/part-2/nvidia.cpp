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
//C++ Implementation of FUNCTION
 unsigned int FindFunctionDefn( const char* strFunctionName, const char* strSourceCode )
 {
 	string a(strFunctionName),b(strSourceCode);
 	int start = 0,end = 0,lnumber=1;
 	for(int i=0;i<=b.size()-a.size();i++)
 	{
 		if(a == b.substr(i,a.size()))
 			return lnumber;
 		string c = b.substr(i,2);
 		//cerr << c << endl;
 		if(c == "\\n")
 		{
 			//cerr << "hi";
 			lnumber++;
 		}
 	}
 	return -1;  //IF No solution
 }
int main()
{
  sync;
  //FOR TEST
  char strFunctionName[] = "func2";
  char strSourceCode[] = "int func1(){ return 0; }\\n int func2(){ return 1; }\\n"; 
  cout << FindFunctionDefn( strFunctionName, strSourceCode ) << endl;
}
