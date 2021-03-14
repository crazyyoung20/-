#include<iostream>
#include<cstring>
#include<algorithm>

#define x first
#define y second

using namespace std;
using PII = pair<int,int>;

const int N = 1010;

int n;
PII p[N];
int cnt[5];

int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    
    for(int i=0;i<n;i++){
        bool st[8];
        memset(st,false,sizeof st);
        for(int j=0;j<n;j++){
            for(int k=0;k<8;k++){
                if(p[i].x+dx[k]==p[j].x&&p[i].y+dy[k]==p[j].y) st[k] = true;
            }
        }
        if(st[0]&&st[2]&&st[4]&&st[6]){
            cnt[st[1]+st[3]+st[5]+st[7]] ++;
        }
    }
    
    for(int i=0;i<=4;i++){
        cout<<cnt[i]<<endl;
    }
    
    return 0;
}
