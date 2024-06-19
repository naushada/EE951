#ifndef __vectors_main__
#define __vectors_main__

#include "vectors.hpp"

int main() {
    Vector r = {
        {1}, 
        {-1},
        {2}
    };

    Vector s = {
        {2}, 
        {0},
        {1}
    };

    VectorSpace space(r, s);

    auto value = space.s().T() * space.r();

    value = space.r().T()*space.r();
    std::cout << "value:" << value << std::endl;
    (space.r()*4).print();
    (8 * space.r()).print();
    space.r().T().print();
    space.s().print();
    (space.r().T() + space.s()).print();
}

#endif /*__vectors_main__*/