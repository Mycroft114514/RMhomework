#include<iostream>
#include <vector>
#include "MarkerManager.hpp"

int main(){
    std::vector<Marker> mark;
    mark.push_back({1,100,200,80});
    mark.push_back({2,200,-50,95});
    mark.push_back({3,0,0,60});
    MarkerManager m;
    Marker* p=&mark[0];
    Marker& r=mark[0];
    std::cout<<"预先录入成员："<<std::endl;
    for(const Marker& i : mark){
        std::cout<<i.id<<" "<<i.x_mm<<" "<<i.y_mm<<" "<<i.priority<<std::endl;
    }
    //std::cout<<"优先级不低于80记录数："<<m.high_pri1(mark,80)<<std::endl;
    std::cout<<"指针读取编号："<<p->id<<std::endl;
    std::cout<<"引用读取编号："<<r.id<<std::endl;

    for(int i=0;i<3;i++){
        if(m.add(mark[i])==1){
            std::cout<<"id:"<<mark[i].id<<" 添加成功"<<std::endl;
        }
        else std::cout<<"添加失败"<<std::endl;
    }
    std::cout<<"优先级不低于80记录数："<<m.high_pri(80)<<std::endl;
    for(;;){
        int n;
        std::cout<<"菜单：\n1 查看全部标记\n2 添加标记\n3 按编号查询\n4 按阈值统计\n5 按编号修改优先级\n6 按优先级排序\n0 退出\n";
        std::cin>>n;
        if(n==0) break;
        switch (n) {
            case 1:{
                m.show();
                break;
            }   
            case 2:{
                std::cout<<"输入编号、坐标和优先级：";
                int iid,xx,yy,ppri;
                std::cin>>iid>>xx>>yy>>ppri;
                if(m.add({iid,xx,yy,ppri})==1){
                    std::cout<<"id:"<<iid<<" 添加成功"<<std::endl;
                }
                else std::cout<<"添加失败"<<std::endl;
                break;
            }   
            case 3:{
                int iid;
                std::cout<<"输入要查询的编号：";
                std::cin>>iid;
                m.check(iid);
                break;
            }       
            case 4:{
                int ppri;
                std::cout<<"输入阈值：";
                std::cin>>ppri;
                std::cout<<"优先级不低于"<<ppri<<"记录数："<<m.high_pri(ppri)<<std::endl;
                break;
            }
            case 5:{
                int iid,ppri;
                std::cout<<"输入编号、优先级：";
                std::cin>>iid>>ppri;
                m.change(iid,ppri);
                break;
            }   
            case 6:{
                m.mark_sort();
                std::cout<<"排序完成"<<std::endl;
                break;
            }
            default:{
                std::cout << "无效选项"<<std::endl;
                break; 
            }
        }
    }
    return 0;
}