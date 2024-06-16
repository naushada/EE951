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

TEST_F(VectorOperations, VectorMultiplication_M1x4) {
    Vector first = {
        {1}, 
        {-1},
        {2},
        {4}
    };
    Vector second = {
        {2}, 
        {0},
        {1},
        {5}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    auto result = space()->r().T() * space()->s();
    EXPECT_EQ(result, 24);
}

TEST_F(VectorOperations, VectorMultiplication_M1x5) {
    Vector first = {
        {1}, 
        {-1},
        {2},
        {4},
        {3}
    };
    Vector second = {
        {2}, 
        {0},
        {1},
        {5},
        {3}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    auto result = space()->r().T() * space()->s();
    EXPECT_EQ(result, 33);
}

TEST_F(VectorOperations, VectorMultiplication_M1x6) {
    Vector first = {
        {1}, 
        {-1},
        {2},
        {4},
        {3},
        {2}
    };
    Vector second = {
        {2}, 
        {0},
        {1},
        {5},
        {3},
        {2}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    auto result = space()->r().T() * space()->s();
    EXPECT_EQ(result, 37);
}

TEST_F(VectorOperations, VectorMultiplication_M3x1) {
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
    auto result = space()->r() * space()->s().T();
    EXPECT_EQ(result, 4);
}

TEST_F(VectorOperations, VectorMultiplication_M4x1) {
    Vector first = {
        {1}, 
        {-1},
        {2},
        {4}
    };
    Vector second = {
        {2}, 
        {0},
        {1},
        {5}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    auto result = space()->r() * space()->s().T();
    EXPECT_EQ(result, 24);
}

TEST_F(VectorOperations, VectorMultiplication_M5x1) {
    Vector first = {
        {1}, 
        {-1},
        {2},
        {4},
        {3}
    };
    Vector second = {
        {2}, 
        {0},
        {1},
        {5},
        {3}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    auto result = space()->r() * space()->s().T();
    EXPECT_EQ(result, 33);
}

TEST_F(VectorOperations, VectorMultiplication_M6x1) {
    Vector first = {
        {1}, 
        {-1},
        {2},
        {4},
        {3},
        {2}
    };
    Vector second = {
        {2}, 
        {0},
        {1},
        {5},
        {3},
        {2}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    auto result = space()->r() * space()->s().T();
    EXPECT_EQ(result, 37);
}

#endif /*__vector_operations_cpp__*/