#include "../headers/KitchenPlan.h"
#include "../headers/Furniture.h"


KitchenPlan::KitchenPlan() : width(0), depth(0) {}

KitchenPlan::KitchenPlan(std::vector<Furniture*> vecfur, double width_, double depth_)
    : furni(vecfur), width(width_), depth(depth_) {}

KitchenPlan::KitchenPlan(const KitchenPlan& other)
    : furni(other.furni), width(other.width), depth(other.depth) {}

bool KitchenPlan::isNormal() const {
    for (int i = 0; i < furni.size() - 1; i++) {
        
        if(furni[i]->isLevitate()){
            return false;
        }
        for (int j = i + 1; j < furni.size(); j++) {
            if (furni[i]->isIntersection(*furni[j]) || !furni[i]->distanceByMaterial(*furni[j])) {
                return false;
            }
        }
    }
    return true; 
}