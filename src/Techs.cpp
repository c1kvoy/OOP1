#include "../headers/Techs.h"
#include "../headers/Furniture.h"

Techs::Techs() : Furniture() {
    width = 0;
    depth = 0;
    height = 0;
    x = 0;
    y = 0;
    z = 0;
    name = "none";
    state = "off";
}

Techs::Techs(std::string name_, double w, double d, double h, double xPos, double yPos, double zPos)
    : Furniture() {
    width = w;
    depth = d;
    height = h;
    x = xPos;
    y = yPos;
    z = zPos;
    name = name;
    state = "off";
}


Techs::Techs(const Techs& other) 
    : Furniture() {
    width = other.width;
    depth = other.depth;
    height = other.height;
    x = other.x;
    y = other.y;
    z = other.z;
    name = other.name;
    state = other.state;
}


void Techs::Switch() { 
    state = (state == "off") ? "on" : "off";
}

bool Techs::isLevitate() {
    return (z > 0);
}

std::string Techs::identify() const {
    return "Techs";
}