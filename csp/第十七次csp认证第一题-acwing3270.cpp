#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N, M;
int T, k, P=-1;
int cnt[1010];

int main(){
    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        cin>>cnt[i];
        int sum=0;
        for(int j=1;j<=M;j++){
            int x;
            cin>>x;
            sum-=x;
            cnt[i] += x;
        }
        if(P<sum) k=i,P=sum;
    }
    
    for(int i=0;i<N;i++){
        T+=cnt[i];
    }
    
    cout<<T<<" "<<k+1<<" "<<P<<endl;
    return 0;
}
