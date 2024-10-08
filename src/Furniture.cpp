#include "../headers/Furniture.h"
#include "../headers/Cabinet.h"

bool Furniture::isIntersection(const Furniture& other) const {
    return !(getX() + getWidth() <= other.getX() || getX() >= other.getX() + other.getWidth() ||
             getY() + getDepth() <= other.getY() || getY() >= other.getY() + other.getDepth() ||
             getZ() + getHeight() <= other.getZ() || getZ() >= other.getZ() + other.getHeight());
} 



