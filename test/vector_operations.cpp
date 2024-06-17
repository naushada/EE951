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

TEST_F(VectorOperations, VectorInnerProductProperty) {
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
    Vector t = {
        {3},
        {2},
        {5},
        {8},
        {6},
        {0}
    };
    /// @brief vectorSpace is aset of vectors
    space()->r(first);
    space()->s(second);
    
    auto r_Plus_s = space()->r() + space()->s();
    /// <r,s> = s.T() * r;
    /// <<r+s>,t> ==> t.T() * <r+s>
    auto value = t.T() * (space()->r() + space()->s());
    //std::cout << " Value: " << value << std::endl;
    /// <r,t> + <s,t>
    auto res = ((t.T() * space()->r()) + (t.T() * space()->s()));
    //std::cout << "Res:" << res << std::endl;
    EXPECT_EQ(res, value);
    /// Homogeneous 
    /// <ar,s> = s.T()(ar)
}

TEST_F(VectorOperations, VectorNorm_1) {
    Vector first = {
        {1}, 
        {0}
    };

    /// @brief vectorSpace is a set of vectors
    space()->r(first);
    auto result = space()->r().N(1);
    //std::cout << "value of VectorNorm_1: " << result << std::endl;
    EXPECT_EQ(result, 1);
}

TEST_F(VectorOperations, VectorNorm_2) {
    Vector first = {
        {2}, 
        {0}
    };

    /// @brief vectorSpace is a set of vectors
    space()->r(first);
    auto result = space()->r().N(2);
    //std::cout << "value of VectorNorm_2: " << result << std::endl;
    EXPECT_EQ(result, 2);
}

TEST_F(VectorOperations, VectorNorm_3) {
    Vector first = {
        {3}, 
        {3},
        {3}
    };

    /// @brief vectorSpace is a set of vectors
    space()->r(first);
    auto result = space()->r().N(3);
    //std::cout << "value of VectorNorm_3: " << result << std::endl;
    ASSERT_DOUBLE_EQ(result, 3);
}

#endif /*__vector_operations_cpp__*/