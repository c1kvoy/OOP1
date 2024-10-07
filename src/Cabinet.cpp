#include "../headers/Cabinet.h"

Cabinet::Cabinet() : material(""), width(0), depth(0), height(0), x(0), y(0), z(0) {}

Cabinet::Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos)
    : material(mat), width(w), depth(d), height(h), x(xPos), y(yPos), z(zPos) {}

Cabinet::Cabinet(const Cabinet& other)
    : material(other.material), width(other.width), depth(other.depth), height(other.height),
      x(other.x), y(other.y), z(other.z) {}

bool Cabinet::isIntersection(const Cabinet& other) const {
    return !(x + width <= other.x || x >= other.x + other.width ||
             y + depth <= other.y || y >= other.y + other.depth ||
             z + height <= other.z || z >= other.z + other.height);
}

bool Cabinet::distanceByMaterial(const Cabinet& other) const {
    if (material != other.material) {
        double dist = std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
        return dist >= 2;
    }
    return true;
}
