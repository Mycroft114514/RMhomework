//hw_03
#include<iostream>

int main(){
    int a[1005],summ=0,n;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        summ+=a[i];
        std::cout<<summ<<" ";
    }
    return 0;
}