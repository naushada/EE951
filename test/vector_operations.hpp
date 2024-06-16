#ifndef __vector_operations_hpp__
#define __vector_operations_hpp__

#include <gtest/gtest.h>
#include "vectors.hpp"


class VectorOperations : public ::testing::Test
{
    public:
        VectorOperations();
        virtual ~VectorOperations() override = default;
        
        virtual void SetUp() override;
        virtual void TearDown() override;
        virtual void TestBody() override;

    private:

};










#endif /*__vector_operations_hpp__*/