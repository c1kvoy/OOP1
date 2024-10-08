#ifndef CABINET_H
#define CABINET_H

#include "Furniture.h" 

class Cabinet : public Furniture {
public:
    Cabinet();
    Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos);
    Cabinet(const Cabinet& other);

    virtual ~Cabinet() {};
};

#endif