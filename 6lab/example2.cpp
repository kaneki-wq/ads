#include<bits/stdc++.h>
using namespace std;
struct st{
    string lastname;
    string firstname;
    double gpa;
};
bool cmp(st a,st b){
    if(a.gpa!=b.gpa) return a.gpa<b.gpa;
    if(a.lastname!=b.lastname) return a.lastname<b.lastname;
    return a.firstname<b.firstname;
}
void ms(vector<st>& a,int l,int r){
    if(l>=r) return;
    int mid=l+(r-l)/2;
    ms(a,l,mid);
    ms(a,mid+1,r);
    vector<st> temp;
    int i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(!cmp(a[j],a[i])) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i<=mid) temp.push_back(a[i++]);
    while(j<=r) temp.push_back(a[j++]);
    for(int k=l;k<=r;k++) a[k]=temp[k-l];
}
int main(){
    int n;
    cin>>n;
    vector<st> stu(n);
    map<string,double> grade={{"A+",4.0},{"A",3.75},{"B+",3.5},{"B",3.0},{"C+",2.5},{"C",2.0},{"D+",1.5},{"D",1.0},{"F",0.0}};
    for(int i=0;i<n;i++){
        int m;
        cin>>stu[i].lastname>>stu[i].firstname>>m;
        double sum=0;
        int credi=0;
        for(int j=0;j<m;j++){
            string mark;
            int cred;
            cin>>mark>>cred;
            sum+=grade[mark]*cred;
            credi+=cred;
        }
        stu[i].gpa=sum/credi;
    }
    cout<<fixed<<setprecision(3);
    ms(stu,0,n-1);
    for(st x:stu){
        cout<<x.lastname<<' '<<x.firstname<<' '<<x.gpa<<'\n';
    }
}