#ifndef __vectors_cpp__
#define __vectors_cpp__

#include "vectors.hpp"

long double Vector::N(std::uint32_t order) {
    if(this->empty()) {
        std::cout << " Norm of Empty Vector" << std::endl;
        return(0);
    }

    std::uint32_t norm = 0;
    auto rows = this->size();
    for(auto row = 0; row < rows; ++row) {
        for(auto ent: this->at(row)) {
            norm += std::pow(ent, 2);
        }
    }

    //std::cout << " The value of |v| is " << norm << std::endl;
    if(norm) {
        return(std::pow(norm, 1.0/order));
    }

    return(norm);
}

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
    //std::cout << " lhs_cols: " << lhs_cols << " lhs_rows: " << lhs_rows << " rhs_cols: " << rhs_cols << " rhs_rows: " << rhs_rows << std::endl;

    if(rhs.empty() || (lhs_cols != rhs_cols) && (lhs_rows != rhs_rows)) {
        /// @brief Addition not possible
        std::cout << " Vector Addition is not possible" << std::endl;
        return(v);
    }
            
    std::vector<std::int32_t> _tt;

    for(auto lhs_row = 0; lhs_row < lhs_rows; ++lhs_row) {
        for(auto lhs_col = 0; lhs_col < lhs_cols; ++lhs_col) {
            _tt.push_back(this->at(lhs_row).at(lhs_col) + rhs.at(lhs_row).at(lhs_col));
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
    //v.push_back(_tt);
    return(v);
}

void Vector::print() const {
    const auto& _rows = this->size();

    if(this->empty()) {
        /// @brief Empty Vector
        return;
    }

    std::cout << "[";
    for(auto row = 0; row < _rows; ++row) {
        const auto cols = this->at(row).size();
        if(cols > 1) {
            std::cout << " [";
        }
        for(auto col = 0; col < cols; ++col) {
            if(col < cols -1)
                std::cout << " " << this->at(row).at(col) << " ";
            else 
                std::cout << " " << this->at(row).at(col);
        }
        if(cols > 1) {
            std::cout << "]";
        }
    }
    std::cout << "]\n";
}



#endif /*__vectors_cpp__*/