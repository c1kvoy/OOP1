#include "../headers/Furniture.h"
#include "../headers/Cabinet.h"


bool Furniture::isIntersection(const Furniture& other) const {
    return !(getX() + getWidth() <= other.getX() || getX() >= other.getX() + other.getWidth() ||
             getY() + getDepth() <= other.getY() || getY() >= other.getY() + other.getDepth() ||
             getZ() + getHeight() <= other.getZ() || getZ() >= other.getZ() + other.getHeight());
}

bool Furniture::distanceByMaterial(const Furniture& other) const {
    if (material != other.getMaterial()) {
        double dist = std::sqrt(std::pow(x - other.getX(), 2) + std::pow(y - other.getY(), 2));
        return dist >= 2;
    }
    return true;
}


void Furniture::furnitureSwitch() { 
    state = (state == "off") ? "on" : "off";
}

bool Furniture::isLevitate() {
    return (z > 0);
}
