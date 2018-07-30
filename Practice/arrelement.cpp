#include <bits/stdc++.h>
using namespace std;
vector <int > v;
int arr[1000000];
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n1,n2,n;
	    cin >> n1>>n2>>n;
	    v.push_back(1);
	    //arr[(int)fabs(n1-n2)]=1;
	    while(v.size()!=n){
	    for(int j=0;j<v.size()-1;j++)
	    {
	       int x = fabs(n1*v[v.size()-1]-n2*v[j]);
	       int y = fabs(n1*v[j]-n2*v[v.size()-1]);
	       arr[x] = 1;
	       arr[y] =1;
	      // cout << x << " " << y << endl;
	    }
	    for(int i=v[v.size()-1]+1;;i++)
	    {
	        if(arr[i] == 0)
	        {
	            v.push_back(i);
	            break;
	        }
	      }
	    }
	    for(int i=0;i<n;i++)
	      cout << v[i] << " ";
	    cout << endl;
	    //cout << v.size() << endl;
	    memset(arr,0,sizeof(arr));
	    
	    v.clear();
	}
	return 0;
}
