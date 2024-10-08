#include "../headers/Cabinet.h"
#include "../headers/Furniture.h"


Cabinet::Cabinet() : Furniture() {
    width = 0;
    depth = 0;
    height = 0;
    x = 0;
    y = 0;
    z = 0;
    state = "off";
    material = "none";
}

Cabinet::Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos)
    : Furniture() {
    width = w;
    depth = d;
    height = h;
    x = xPos;
    y = yPos;
    z = zPos;
    state = "off";
    material = mat;
}

Cabinet::Cabinet(const Cabinet& other) 
    : Furniture() {
    width = other.width;
    depth = other.depth;
    height = other.height;
    x = other.x;
    y = other.y;
    z = other.z;
    state = other.state;
    material = other.material;
}