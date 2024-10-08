#ifndef KITCHENPLAN_H
#define KITCHENPLAN_H

#include <vector>
#include "Furniture.h"

class KitchenPlan{
private:
    std::vector<Furniture*> furni;
    double width, depth;

public:
    KitchenPlan();
    KitchenPlan(std::vector<Furniture*> vecfur, double width_, double depth_);
    KitchenPlan(const KitchenPlan& other);
    bool isNormal() const;
};

#endif