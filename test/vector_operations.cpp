#ifndef __vector_operations_cpp__
#define __vector_operations_cpp__

#include "vector_operations.hpp"


VectorOperations::VectorOperations() {

}
        
void VectorOperations::SetUp() {
    m_space = std::make_shared<VectorSpace>();

}

void VectorOperations::TearDown() {

}

void VectorOperations::TestBody() {

}




TEST_F(VectorOperations, VectorMultiplication_M1x3) {
    Vector first = {
        {1}, 
        {-1},
        {2}
    };
    Vector second = {
        {2}, 
        {0},
        {1}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    auto result = space()->r().T() * space()->s();
    EXPECT_EQ(result, 4);
}



#endif /*__vector_operations_cpp__*/