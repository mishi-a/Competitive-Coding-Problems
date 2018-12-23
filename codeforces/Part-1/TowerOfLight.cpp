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
#define pdd pair<double, double>

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
vector<pii> v;

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D) 
{ 
	// cerr << A.FI << " " << A.SE <<  endl;
	// cerr << B.FI << " " << B.SE <<  endl;
	// cerr << C.FI << " " << C.SE <<  endl;
	// cerr << D.FI << " " << D.SE <<  endl;
    // Line AB represented as a1x + b1y = c1 
    double a1 = B.second - A.second; 
    double b1 = A.first - B.first; 
    double c1 = a1*(A.first) + b1*(A.second); 
  
    // Line CD represented as a2x + b2y = c2 
    double a2 = D.second - C.second; 
    double b2 = C.first - D.first; 
    double c2 = a2*(C.first)+ b2*(C.second); 
  
    double determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0) 
    { 
        // The lines are parallel. This is simplified 
        // by returning a pair of FLT_MAX 
        return make_pair(FLT_MAX, FLT_MAX); 
    } 
    else
    { 
        double x = (b2*c1 - b1*c2)/determinant; 
        double y = (a1*c2 - a2*c1)/determinant; 
        return make_pair(x, y); 
    } 
} 

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int num;
  	cin >> num;
  	for(int i=0;i<num;i++)
  	{
  		int p,h;
  		cin >> p >> h;
  		p+=100005;
  		v.pb({p-h,p+h});
  	}
  	sort(v.begin(),v.end());
  	double area = pow((v[0].SE-v[0].FI)/2.0,2);
  	int cur = 0;
  	for(unsigned i=1;i<v.size();i++)
  	{
  		while(i<v.size() && v[i].SE<=v[cur].SE)
  			i++;
  		if(i == v.size())
  			break;
  		//cerr << i << endl;
  		if(v[i].FI < v[cur].SE)
  		{
  			double h = (v[i].SE-v[i].FI)/2.0;
  			double h1 = (v[cur].SE-v[cur].FI)/2.0;
  			pdd intH = lineLineIntersection({v[i].FI,0},{v[i].FI+h,h},
  				{v[cur].SE,0},{v[cur].FI+h1,h1});
  			//cerr << intH.FI << " " << intH.SE  << " " << area << endl;
  			area -= ((v[cur].SE-v[i].FI)*intH.SE)/2.0;

  		}
  		area += pow((v[i].SE-v[i].FI)/2.0,2);
  		cur = i;
  	}
  	//cout << fixed << setprecision(2);
  	cout << area << endl;
  	v.clear();
  }
}
