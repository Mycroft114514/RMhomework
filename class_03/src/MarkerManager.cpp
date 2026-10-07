#include<iostream>
#include <vector>
#include <algorithm>
#include "MarkerManager.hpp"

/*int MarkerManager::high_pri1(const std::vector<Marker>& marker,int threshold) const{
    int n=0;
    for(int i=0;i<marker.size();i++){
        if(marker[i].priority>=threshold) n++;
    }
    return n;
}*/
int MarkerManager::high_pri(int threshold) const{
    int n=0;
    for(int i=0;i<mark2.size();i++){
        if(mark2[i].priority>=threshold) n++;
    }
    return n;
}
bool MarkerManager::add(const Marker& marker){
    if(marker.id<=0||marker.priority<0||marker.priority>100) return 0;
    if(contains(marker.id)==1) return 0;
    mark2.push_back({marker.id,marker.x_mm,marker.y_mm,marker.priority});
    return 1;
}
bool MarkerManager::contains(int id) const{
    for(int i=0;i<mark2.size();i++){
        if(mark2[i].id==id) return 1; 
    }
    return 0;
}
void MarkerManager::show() const{
    for(int i=0;i<mark2.size();i++){
        std::cout<<mark2[i].id<<" "<<mark2[i].x_mm<<" "<<mark2[i].y_mm<<" "<<mark2[i].priority<<std::endl;
    }
}
void MarkerManager::change(int id,int new_pri){
    int k=0;
    if(new_pri<0||new_pri>100) std::cout<<"修改失败"<<std::endl;
    else{
        for(int i=0;i<mark2.size();i++){
            if(mark2[i].id==id){
                k=1;
                mark2[i].priority=new_pri;
                std::cout<<"修改成功"<<std::endl;
                break;
            }
        }
        if(k==0) std::cout<<"修改失败"<<std::endl;
    }
}
void MarkerManager::mark_sort(){
    std::sort(mark2.begin(), mark2.end(), [](const Marker& left, const Marker& right) {
        if (left.priority!= right.priority) {
            return left.priority > right.priority;
        }
        return left.id < right.id;
    });
}
void MarkerManager::check(int id) const{
    int k=0;
    for(int i=0;i<mark2.size();i++){
        if(mark2[i].id==id){
            std::cout<<mark2[i].id<<" "<<mark2[i].x_mm<<" "<<mark2[i].y_mm<<" "<<mark2[i].priority<<std::endl;
            k=1;
            break;
        }
    }
    if(k==0) std::cout<<"编号不存在"<<std::endl;
}