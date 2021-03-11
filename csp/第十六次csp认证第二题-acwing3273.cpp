#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    for(int c=0;c<n;c++){
        string s;
        cin>>s;
        
        stack<int> stk;
        for(int i=0;i<7;i++){
            if(s[i]>='0'&&s[i]<='9') stk.push(s[i]-'0');
            else if(s[i]=='+');
            else if(s[i]=='-') stk.push(-(s[++i]-'0'));
            else if(s[i]=='x'){
                int t=stk.top();
                stk.pop();
                stk.push(t*(s[++i]-'0'));
            }
            else{
                int t=stk.top();
                stk.pop();
                stk.push(t/(s[++i]-'0'));
            }
        }
        int ans=0;
        while(stk.size()){
            ans+=stk.top();
            stk.pop();
        }
        cout<<(ans==24?"Yes":"No")<<endl;
    }
    return 0;
}
