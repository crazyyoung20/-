#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int T,D,E;
bool drop[1010];

int pre(int i, int n){
    if(i==0) return n-1;
    else return i-1;
}
int later(int i,int n){
    if(i==n-1) return 0;
    else return i+1;
}

int main(){
    cin>>N;
    
    for(int i=0;i<N;i++){
        int m;
        cin>>m;
        int sum;
        cin>>sum;
        for(int j=1;j<m;j++){
            int x;
            cin>>x;
            if(x>0){
                if(sum!=x)
                    sum=x,drop[i]=true;
            }
            else sum+=x;
        }
        T+=sum;
    }
    
    for(int i=0;i<N;i++){
        if(drop[i]) D++;
        if(drop[i]&&drop[pre(i,N)]&&drop[later(i,N)]) E++;
    }
    cout<<T<<" "<<D<<" "<<E<<endl;
    return 0;
}
