#include "../headers/Furniture.h"
#include <cmath>

// Реализация конструктора по умолчанию
Cabinet::Cabinet() : material(""), Furniture() {
    width = 0;
    depth = 0;
    height = 0;
    x = 0;
    y = 0;
    z = 0;
    state = "off";
}

Cabinet::Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos)
    : material(mat), Furniture() {
    width = w;
    depth = d;
    height = h;
    x = xPos;
    y = yPos;
    z = zPos;
    state = "off";
}

Cabinet::Cabinet(const Cabinet& other) 
    : Furniture(), material(other.material) {
    width = other.width;
    depth = other.depth;
    height = other.height;
    x = other.x;
    y = other.y;
    z = other.z;
    state = other.state;
}

bool Cabinet::isIntersection(const Furniture& other) const {
    return !(getX() + getWidth() <= other.getX() || getX() >= other.getX() + other.getWidth() ||
             getY() + getDepth() <= other.getY() || getY() >= other.getY() + other.getDepth() ||
             getZ() + getHeight() <= other.getZ() || getZ() >= other.getZ() + other.getHeight());
}

bool Cabinet::distanceByMaterial(const Cabinet& other) const {
    if (material != other.material) {
        double dist = std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
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