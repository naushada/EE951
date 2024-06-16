#ifndef __vectors_hpp__
#define __vectors_hpp__

#include <vector>
#include <iostream>


/// @brief https://www.statlect.com/matrix-algebra/inner-product
class Vector : public std::vector<std::vector<std::int32_t>> {
    public:
        using vector::vector;
        virtual ~Vector() = default;

        Vector T();
        std::int32_t operator* (const Vector& rhs) const;
        Vector operator+ (const Vector& rhs) const;
        Vector operator* (const std::int32_t& scalar);
        friend Vector operator* (const std::int32_t& scalar, const Vector& v1);
        void print() const;

};

class VectorSpace {
    public:
        VectorSpace(Vector aa, Vector bb) {
            m_r = aa;
            m_s = bb;
        }
        VectorSpace() = default;
        ~VectorSpace() = default;

        Vector r() const {
            return(m_r);
        }

        Vector s() const {
            return(m_s);
        }

        void r(Vector v) {
            m_r = v;
        }
        void s(Vector v) {
            m_s = v;
        }

    private:
        Vector m_r;
        Vector m_s;
};

#endif /*__vectors_hpp__*/