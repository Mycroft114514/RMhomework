//hw_07
#include<iostream>

int main(){
    int x=0,y=0;
    char a;
    while(std::cin>>a){
        if(a=='U') y++;
        if(a=='D') y--;
        if(a=='L') x--;
        if(a=='R') x++;
    }
    if(x==0&&y==0) std::cout<<"true";
    else std::cout<<"false";
    return 0;
}