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

int main()
{
  sync;
  int hh,mm,h,c,d,n;
  cin >> hh >> mm;
  cin >>h>>d>>c>>n;
  double p = c-0.2*c;
  if(hh>=20 && hh <=23)
  {
  	int tot = h/n + (h%n != 0);
  	cout << (double)tot*p << endl;
  }
  else
  {
  	int mina = (19-hh)*60+(60-mm);
  	int incH = h+mina*d;
  	int tot = incH/n + (incH%n!=0);
  	int tot1 = h/n+(h%n!=0);
  	double p1 = tot*p;
  	double p2 = tot1*c;
  	cout << fixed << setprecision(10) << min(p1,p2) << endl;
  }
}
