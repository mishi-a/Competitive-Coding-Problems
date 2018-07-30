#include <bits/stdc++.h>

using namespace std;

vector <pair<double,double>> v;

int main() {
    int n;
    cin >> n;
    double a,b;
    double mux =20;
    int idx;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        v.push_back({a,b});
        double res = b/a;
        if(res<mux)
        {
            mux = res;
            idx = i;
        }
        
    }
    cout << idx+1 << endl;
    return 0;
}
