#ifndef FURNITURE_H
#define FURNITURE_H

#include <vector>
#include <string>

class Furniture {
protected:
    double x, y, z;
    double width, depth, height;
public:
    virtual ~Furniture() {};
    
    virtual bool isIntersection(const Furniture& other) const;
    virtual std::string identify() const = 0;


    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    double getWidth() const { return width; }
    double getDepth() const { return depth; }
    double getHeight() const { return height; }
};

#endif
