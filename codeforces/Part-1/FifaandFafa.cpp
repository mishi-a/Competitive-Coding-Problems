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

int main() {
    sync;
    double r, x1, y1, x2, y2, x, y;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if(d >= r)
    {
        return cout << setprecision(8) << fixed << x1 << " " << y1 << " " << r, 0;
    }
    double k = d + r, m;
    if(x2 == x1) {
        x = x2;
        if(y2 > y1)
            y = y2 - k / 2;
        else
            y = y2 + k / 2;
    }
    else {
        m = abs((y2 - y1) / (x2 - x1));
        double z = 1 / sqrtl(1 + m * m);
        if(x2 > x1) x = x2 - k * z / 2;
        else        x = x2 + k * z / 2;
        if(y2 > y1) y = y2 - k * m * z / 2;
        else        y = y2 + k * m * z / 2;
    }
    cout << fixed << setprecision(10) << x << " " << y << " " << k / 2;
}
