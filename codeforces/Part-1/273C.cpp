#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,n) for(int i=0;i<n;++i)
const int N = 1e5;
//int freq[N];
typedef long long ll;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    ll arr[3],ans=0;
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    if(arr[2]>2*(arr[0]+arr[1]))
        arr[2]=2*(arr[0]+arr[1]);
    cout<<(ll)(arr[0]+arr[1]+arr[2])/3;
}
