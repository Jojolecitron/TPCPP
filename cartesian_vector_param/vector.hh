#pragma once

#include <ostream>

#include "config.h"

#include <initializer_list>

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector(){
        for(int i=0; i<NDIM; i++){
            v_[i] = 0;
        }
    }
    Vector(value k){
        for(int i=0; i<NDIM; i++){
            v_[i] = k;
        }
    };
    Vector(value *p){
        for(int i=0; i<NDIM; i++){
            v_[i] = p[i];
        }
    };
    Vector(std::initializer_list<value> l){
        auto* p =std::data(l);
        for(int i=0; i<NDIM; i++){
            v_[i] = p[i];
        }
    }
    // possibly more

// Public Member functions here

    value operator[](int pos) const{
        return v_[pos];
    }; 

    value& operator[](int pos){
        return v_[pos];
    }; 

    Vector& operator+(const Vector rhs);

    Vector& operator*(const Vector rhs);

    Vector& operator*(const value k);

    Vector& operator+(const value k);

    Vector& operator-(const Vector rhs);
    
    void operator+=(const Vector& rhs){
        *this = *this + rhs;
    };
    void operator-=(const value k){
        *this = *this + k;
    };
    void operator-=(const Vector& rhs){
        *this = *this - rhs;
    }
    void operator*=(const Vector& rhs){
        *this = *this * rhs;
    };
    void operator*=(const value k){
        *this = *this * k;
    };


    
private:
// Private Member functions here
// Member variables are ALWAYS private, and they go here
    value v_[NDIM];
};
// Nonmember function operators go here
Vector& add_vec(const Vector rhs, const Vector r){
    value p[NDIM];
    auto v = Vector{};
    for(int i = 0; i<NDIM; i++){
        v[i] = r[i] + rhs[i];
    }
    return v;
}

Vector& mul_vec(const Vector rhs, const Vector r){
    value p[NDIM];
    auto v = Vector{};
    for(int i = 0; i<NDIM; i++){
        v[i] = r[i] * rhs[i];
    }
    return v;
}


std::ostream& operator<<(std::ostream& os, Vector& v){
    for(int i=0; i<NDIM; i++){
        os << "i" << v[i] << "\n";
    }
    return os;
}

Vector& Vector::operator+(const Vector rhs){
    return add_vec(*this, rhs);
};

Vector& Vector::operator+(const value rhs){
    return *this + Vector(rhs);
};

Vector& Vector::operator*(const Vector rhs){
    return *mul_vec(*this, rhs);
};

Vector& Vector::operator*(const value rhs){
    return *this * Vector(rhs);
};

Vector& Vector::operator-(const Vector rhs){
    return *this - rhs;
};