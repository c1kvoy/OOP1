#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "../headers/Furniture.h"

int main() {
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
    assert(cab1.getState() == "off");
    cab1.furnitureSwitch();
    assert(cab1.getState() == "on");
    assert(cab1.isLevitate() == false);
    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}