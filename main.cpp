#include <iostream>
#include <string>
#include <cassert>

class Cabinet{
private:
    double x, y, z;
    double width, depth, height;
    std::string material; 

public:
    Cabinet(): material(""), width(0), depth(0), height(0), x(0), y(0), z(0) {}
    Cabinet(std::string mat, double w, double d, double h, double xPos, double yPos, double zPos): 
    material(mat), width(w), depth(d), height(h), x(xPos), y(yPos), z(zPos) {}   
    
    Cabinet(const Cabinet& other): 
    material(other.material), width(other.width), depth(other.depth), height(other.height),
          x(other.x), y(other.y), z(other.z) {}
    
    bool isIntersection(const Cabinet& other) const {
    return !(x + width <= other.x || x >= other.x + other.width ||
             y + depth <= other.y || y >= other.y + other.depth ||
             z + height <= other.z || z >= other.z + other.height);  
    }

    bool distanceByMaterial(const Cabinet& other) const { 
        if (material != other.material) {
            double dist = std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
            return  dist < 2 ? false : true ;
        }
        return true;
    }
};


void Tests() {
    Cabinet defaultCab;
    assert(defaultCab.isIntersection(Cabinet()) == false);

    Cabinet cab1("wood", 100, 50, 200, 0, 0, 0);
    assert(cab1.isIntersection(Cabinet("wood", 100, 50, 200, 200, 200, 200)) == false);

    Cabinet cab2(cab1);
    assert(cab1.isIntersection(cab2) == true);

    Cabinet cab3("metal", 100, 50, 200, 50, 0, 0);
    assert(cab1.isIntersection(cab3) == true);

    assert(cab1.distanceByMaterial(cab3) == true);
    Cabinet cab4("metal", 100, 50, 200, 1, 0, 0);
    assert(cab1.distanceByMaterial(cab4) == false);

    std::cout << "Все тесты пройдены успешно!" << std::endl;
}

int main() {
    Tests();
    return 0;
}
