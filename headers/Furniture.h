#ifndef FURNITURE_H
#define FURNITURE_H

#include <vector>
#include <string>

class Furniture {
protected:
    double x, y, z;
    double width, depth, height;
    std::string state, material;

public:
    virtual bool isIntersection(const Furniture& other) const ;
    virtual bool distanceByMaterial(const Furniture& other) const ;
    virtual void furnitureSwitch();
    virtual bool isLevitate();
    
    virtual ~Furniture() {};
  

    std::string getState() const {return state;}
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    double getWidth() const { return width; }
    double getDepth() const { return depth; }
    double getHeight() const { return height; }
    std::string getMaterial() const { return material; }
};

#endif
