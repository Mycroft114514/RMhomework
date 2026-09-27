//hw_06
#include<iostream>

struct stu{
    int m;
    int a;
    int b;
    int c;
    int summ;
};
int main(){
    int n;
    stu score[305];
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>score[i].a>>score[i].b>>score[i].c;
        score[i].summ=score[i].a+score[i].b+score[i].c;
        score[i].m=i;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(score[i].summ<score[j].summ) std::swap(score[i],score[j]);
            else{
                if(score[i].summ==score[j].summ&&score[i].a<score[j].a) std::swap(score[i],score[j]);
                else{
                    if(score[i].a==score[j].a&&score[i].m>score[j].m) std::swap(score[i],score[j]);
                }
            }
        }
    }
    for(int i=1;i<=5;i++){
        std::cout<<score[i].m<<" "<<score[i].summ<<std::endl;
    }
    return 0;
}