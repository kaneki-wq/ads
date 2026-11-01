#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--)
    {
        int N;
        cin>>N;
        queue<char> q;
        int cnt[26]= {};
        for(int i=0;i<N;i++){
            char c;
            cin>>c;
            cnt[c-'a']++;
            q.push(c);
            while(!q.empty() && cnt[q.front()-'a']>1){
                q.pop();
            }
            if(q.empty()){
                cout<<-1<<' ';
            }
            else{
                cout<<q.front()<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}