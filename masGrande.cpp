#include <cstdio>
#include <algorithm>

using namespace std;

struct masGrande{
    int primero,W,S;
    
    masGrande(){
    }
    
    masGrande(int _primero, int _W, int _S){
        primero=_primero;
        W=_W;
        S=_S;
    }
    
    bool operator < (masGrande X) const{
        if(W!=X.W) return W<X.W;
        return S>X.S;
    }
};

int main(){
    int n=0,W,S;
    masGrande a[1000];
    
    while(scanf("%d %d",&W,&S)==2) a[n]=masGrande(++n,W,S);
    sort(a,a+n);
    
    int pri[n],next[n],res=0,start;
    
    for(int i=n-1;i>=0;i--){
        pri[i]=1;
        next[i]=-1;
        
        for(int j=i+1;j<n;j++){
            if(a[i].W<a[j].W && a[i].S>a[j].S && 1+pri[j]>pri[i]){
                pri[i]=1+pri[j];
                next[i]=j;
            }
        }
        
        if(pri[i]>res){
            res=pri[i];
            start=i;
        }
    }
    
    printf("%d\n",res);
    for(int i=start;i!=-1;i=next[i]) printf("%d\n",a[i].primero);
    
    return 0;
}