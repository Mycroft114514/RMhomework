#pragma once
#include<iostream>
#include <vector>
struct Marker{
    int id;
    int x_mm;
    int y_mm;
    int priority;
};
class MarkerManager{
    private:
        std::vector<Marker> mark2;
    public:
        bool add(const Marker& marker);
        bool contains(int id) const;
        //int high_pri1(const std::vector<Marker>& marker,int threshold) const;
        int high_pri(int threshold) const;
        void show() const;
        void change(int id,int new_pri);
        void mark_sort();
        void check(int id) const;
};