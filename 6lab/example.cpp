#include<bits/stdc++.h>
using namespace std;
void ms(vector<int>& a,int l,int r){
    if(l>=r) return;
    int mid=l+(r-l)/2;
    ms(a,l,mid);
    ms(a,mid+1,r);
    vector<int> temp;
    int i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i<=mid) temp.push_back(a[i++]);
    while(j<=r) temp.push_back(a[j++]);
    for(int k=l;k<=r;k++) a[k]=temp[k-l];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b[i]=x;
    }
    ms(a,0,n-1);
    ms(b,0,m-1);
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            cout<<a[i]<<' ';
            i++;
            j++;
        }
        else if(a[i]>b[j]) j++;
        else i++;
    }
}