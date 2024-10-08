#include "../headers/KitchenPlan.h"
#include "../headers/Furniture.h"
#include "../headers/Techs.h"
#include "../headers/Cabinet.h"


KitchenPlan::KitchenPlan() : width(0), depth(0) {}

KitchenPlan::KitchenPlan(std::vector<Furniture*> vecfur, double width_, double depth_)
    : furni(vecfur), width(width_), depth(depth_) {}

KitchenPlan::KitchenPlan(const KitchenPlan& other)
    : furni(other.furni), width(other.width), depth(other.depth) {}

bool KitchenPlan::isNormal() const {
    for (size_t i = 0; i < furni.size(); i++) {
        if (furni[i]->identify() == "Techs") {
            if (auto techsItem = dynamic_cast<Techs*>(furni[i])) {
                if (techsItem->isLevitate()) {
                    return false;
                }
            }
        }
        for (size_t j = i + 1; j < furni.size(); j++) {
            if (furni[i]->identify() == "Cabinet" && furni[i]->identify() == "Cabinet"){
                if (furni[i]->isIntersection(*furni[j])){
                    return false;
                }
            }
            auto Item1 = dynamic_cast<Cabinet*>(furni[i]);
            auto Item2 = dynamic_cast<Cabinet*>(furni[j]);
            if (!Item1->distanceByMaterial(*Item2)){
                return false;
            }
        } 
    }
    return true; 
}