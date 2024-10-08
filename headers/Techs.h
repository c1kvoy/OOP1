#ifndef TECHS_H
#define TECHS_H

#include "Furniture.h" 
#include <string>


class Techs : public Furniture {
private:
    std::string state, name;
public:
    Techs();
    Techs(std::string name_, double w, double d, double h, double xPos, double yPos, double zPos);
    Techs(const Techs& other);
    virtual ~Techs() {};


    virtual std::string identify() const override;
    void Switch();
    bool isLevitate();

     std::string getState() const {return state;}
};


#endif