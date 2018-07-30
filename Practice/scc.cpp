#include <bits/stdc++.h>
using namespace std;
vector <int> v;
struct node
{
  int a;
  int b;
  int c;
};
int sz;
stack <node> s;
void heapify(int x)
{
    int l = 2*x;
    int r = 2*x+1;
    int mux = x;
    if(l<=sz && v[l]>v[x])
      mux = l;
    if(r<=sz && v[r] > v[mux])
      mux = r;
    if(mux!=x)
    {
        swap(v[mux],v[x]);
        heapify(mux);
    }
}
int main()
{
    //cout << "Hello World!" << endl;
    int t,a;
    cin >> t;
    int p = t;
    v.push_back(-1);
    while(p--)
    {
        cin >> a;
        v.push_back(a);
        if(v.size()<=3)
          cout << "-1" << endl;
        else
        {
          int node = v.size()-1;
          while(node!=1 && v[node/2] < v[node])
          {
             swap(v[node/2],v[node]);
             node = node/2;
          }
          vector <int> v1;
          int k=0;
          for(k=0;k<8&&k+2<v.size();k++)
            v1.push_back(v[k+2]);
          sort(v1.begin(),v1.end());
          cout << v[1] <<" " << v1[k-1] << " " << v1[k-2] << endl;
        }
    }
    
    return 0;
}

