#include<bits/stdc++.h>
using namespace std;
struct Date{
    int d,m,y;
};
bool cmp(Date x,Date y){
    if(x.y!=y.y) return x.y<y.y;
    if(x.m!=y.m) return x.m<y.m;
    return x.d<y.d;
}
void ms(vector<Date>& a,int l,int r){
    if(l>=r) return;
    int mid=l+(r-l)/2;
    ms(a,l,mid);
    ms(a,mid+1,r);
    vector<Date> temp;
    int i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(cmp(a[i],a[j])) temp.push_back(a[i++]);
        else if(cmp(a[j],a[i])) temp.push_back(a[j++]);
        else temp.push_back(a[i++]);
    }
    while(i<=mid) temp.push_back(a[i++]);
    while(j<=r) temp.push_back(a[j++]);
    for(int k=l;k<=r;k++) a[k]=temp[k-l];
}
int main(){
    int n;
    cin>>n;
    vector<Date> a(n);
    for(int i=0;i<n;i++){
        char c;
        cin>>a[i].d>>c>>a[i].m>>c>>a[i].y;
    }
    ms(a,0,n-1);
    for(Date x:a){
        cout<<setfill('0')<<setw(2)<<x.d<<'-'<<setw(2)<<x.m<<'-'<<setw(4)<<x.y<<'\n';
    }
}