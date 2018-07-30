#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int main()
{
  srand(time(NULL));
  cout << "1000" <<  endl;
  int t = 1000;
  while(t--)
  {
    int x = 2 + rand()%96;
    int y = 2 + rand()%96;
    int z = 2 + rand()%96;
    int a =   rand()%50;
    int b =  rand()%50;
    int c =  rand()%1000;  
    cout << x << " " << y << " " << z << " " << a << " " << b << " " << c <<endl;
  }
  
}

