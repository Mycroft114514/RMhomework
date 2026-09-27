//hw_05
#include<iostream>

int main(){
    int i=1,a[105];
    for(;;){
        std::cin>>a[i];
        if(a[i]==0) break;
        else i++;
    }
    for(int j=i-1;j>=1;j--){
        std::cout<<a[j]<<" ";
    }
    return 0;
}