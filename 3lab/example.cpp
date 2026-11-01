#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<long long> pref(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1]=pref[i]+a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int pow;
        cin>>pow;
        int cnt=upper_bound(a.begin(),a.end(),pow)-a.begin();
        cout<<cnt<<' '<<pref[cnt]<<'\n';
    }
    return 0;
}