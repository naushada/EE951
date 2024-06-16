#ifndef __vectors_cpp__
#define __vectors_cpp__

#include "vectors.hpp"

Vector Vector::T() {
    Vector _mm;
    if(this->empty()) {
        /// @brief Transpose on Empty Matrix is notpossible
        return(_mm);
    }

    std::vector<std::int32_t> _tt;
    const auto& _cols = this->at(0).size();
    const auto& _rows = this->size();

    for(auto col = 0; col < _cols; ++col) {
        for(auto row = 0; row < _rows; ++row) {
            _tt.push_back(this->at(row).at(col));
        }
        _mm.push_back(_tt);
        _tt.clear();
    }
       
    return(_mm);
}

std::int32_t Vector::operator* (const Vector& rhs) const {
    auto lhs_cols = this->at(0).size();
    auto lhs_rows = this->size();
    auto rhs_cols = rhs.at(0).size();
    auto rhs_rows = rhs.size();

    if(this->empty() || rhs.empty() || (lhs_rows != rhs_cols && lhs_cols != rhs_rows)) {
        /// @brief Matrix Multiplication not possible
        std::cout << " Matrix multiplication is not possible" << std::endl;
        return(-1);
    }

    std::int32_t product = 0;
    for(auto lhs_row = 0; lhs_row < lhs_rows; ++lhs_row) {
        for(auto lhs_col = 0; lhs_col < lhs_cols; ++lhs_col) {
            product += this->at(lhs_row).at(lhs_col) * rhs.at(lhs_col).at(lhs_row);        
        }
    }
    return(product);
}

Vector Vector::operator+ (const Vector& rhs) const {
    auto lhs_cols = this->at(0).size();
    auto lhs_rows = this->size();
    auto rhs_cols = rhs.at(0).size();
    auto rhs_rows = rhs.size();
    Vector v;
    std::cout << " lhs_cols: " << lhs_cols << " lhs_rows: " << lhs_rows << " rhs_cols: " << rhs_cols << " rhs_rows: " << rhs_rows << std::endl;

    if(rhs.empty() || (lhs_cols != rhs_rows) && (lhs_rows != rhs_cols)) {
        /// @brief Addition not possible
        std::cout << " Vector Addition is not possible" << std::endl;
        return(v);
    }
            
    std::vector<std::int32_t> _tt;

    for(auto lhs_row = 0, rhs_col = 0; (lhs_row < lhs_rows && rhs_col < rhs_cols); ++lhs_row, ++rhs_col) {
        for(auto lhs_col = 0, rhs_row = 0; (lhs_col < lhs_cols && rhs_row < rhs_rows); ++lhs_col, ++rhs_row) {
            _tt.push_back(this->at(lhs_row).at(lhs_col) + rhs.at(rhs_row).at(rhs_col));
        }
        v.push_back(_tt);
        _tt.clear();
    }
    return(v);
}

Vector Vector::operator* (const std::int32_t& scalar) {
    return(scalar * *this);
}

Vector operator* (const std::int32_t& scalar, const Vector& v1) {
    auto lhs_cols = v1.at(0).size();
    auto lhs_rows = v1.size();
    Vector v;
    if(v1.empty()) {
        /// @brief scalar operation not possible on empty vector
        return(v);
    }

    std::vector<std::int32_t> _tt;
    for(auto lhs_row = 0; lhs_row < lhs_rows; ++lhs_row) {
        for(auto lhs_col = 0; lhs_col < lhs_cols; ++lhs_col) {
            _tt.push_back(v1.at(lhs_row).at(lhs_col) * scalar);
        }
        v.push_back(_tt);
        _tt.clear();
    }
    return(v);
}

void Vector::print() const {
    const auto& _rows = this->size();

    if(this->empty()) {
        /// @brief Empty Vector
        return;
    }

    std::cout << "{\n";
    for(auto row = 0; row < _rows; ++row) {
        std::cout << "{";
        const auto cols = this->at(row).size();
        for(auto col = 0; col < cols; ++col) {
            if(col < cols -1)
                std::cout << " " << this->at(row).at(col) << " ";
            else 
                std::cout << " " << this->at(row).at(col);
        }
        std::cout << "}\n";
    }
    std::cout << "}\n";
}



#endif /*__vectors_cpp__*/