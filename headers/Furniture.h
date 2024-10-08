#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>

class Furniture {
protected:
    double x, y, z;
    double width, depth, height;
    std::string state;

public:
    virtual bool isIntersection(const Furniture& other) const = 0;
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
};

class Cabinet : public Furniture {
private:
    std::string material;

public:
    Cabinet();
    Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos);
    Cabinet(const Cabinet& other);

    bool isIntersection(const Furniture& other) const override;
    bool distanceByMaterial(const Cabinet& other) const;


    virtual ~Cabinet() {};
};

#endif
