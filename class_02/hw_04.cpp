//hw_04
#include<iostream>

int main(){
    double a[10],summ=0,maxx=-1,minn=15;
    double ans;
    for(int i=1;i<=5;i++){
        std::cin>>a[i];
        summ+=a[i];
        maxx=std::max(maxx,a[i]);
        minn=std::min(minn,a[i]);
    }
    ans=(summ-maxx-minn)/3;
    printf("%.2lf",ans);
    return 0;
}