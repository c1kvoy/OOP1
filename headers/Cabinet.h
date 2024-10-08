#ifndef CABINET_H
#define CABINET_H

#include "Furniture.h" 

class Cabinet : public Furniture {
private:
    std::string material;
public:
    Cabinet();
    Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos);
    Cabinet(const Cabinet& other);
    virtual ~Cabinet() {};

    virtual bool distanceByMaterial(const Cabinet& other) const ;

    virtual std::string identify() const override;

    std::string getMaterial() const { return material; }
};

#endif