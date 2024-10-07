#ifndef CABINET_H
#define CABINET_H

#include <string>


class Cabinet
{
private:
    double x, y, z;
    double width, depth, height;
    std::string material;  

public:
    Cabinet();
    Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos);
    Cabinet(const Cabinet& other);

    bool isIntersection(const Cabinet& other) const;
    bool distanceByMaterial(const Cabinet& other) const;
};  

#endif