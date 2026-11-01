    #include<bits/stdc++.h>
    using namespace std;
    void first(int len){
        queue<char> letters;
        int cnt[26]={};
        char letter;
        for(int i=0;i<len;++i){
            cin>>letter;
            letters.push(letter);
            cnt[letter-'a']++;
            while(!letters.empty() && cnt[letters.front()-'a']>1) letters.pop();
            if(letters.empty()) cout<<-1<<' ';
            else cout<<letters.front()<<' ';
        }
        cout<<'\n';
    }
    int main(){
        int n,len;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>len;
            first(len);
        }
        return 0;
    }