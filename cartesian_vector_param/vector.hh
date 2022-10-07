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

    Vector operator+(const Vector rhs);

    value operator*(const Vector rhs);

    Vector operator*(const value k);

    Vector operator+(const value k);

    Vector operator-(const Vector rhs);
    
    Vector& operator-=(const value k);

    Vector& operator-=(const Vector rhs);

    Vector& operator+=(const Vector rhs);

    Vector& operator*=(const value k);


    
private:
// Private Member functions here
// Member variables are ALWAYS private, and they go here
    value v_[NDIM];
};
// Nonmember function operators go here
Vector add_vec(const Vector rhs, const Vector r){
    auto v = Vector{};
    for(int i = 0; i<NDIM; i++){
        v[i] = r[i] + rhs[i];
    }
    return v;
}

Vector sous_vec(const Vector rhs, const Vector r){
    auto v = Vector{};
    for(int i = 0; i<NDIM; i++){
        v[i] = rhs[i] - r[i];
    }
    return v;
}


value mul_vec(const Vector rhs, const Vector r){
    auto s{0};
    for(int i = 0; i<NDIM; i++){
        s += (r[i] * rhs[i]);
    }
    return s;
}

Vector mul_val(const Vector rhs, const value k){
    auto v = Vector{};
    for(int i = 0; i<NDIM; i++){
        v[i] = rhs[i] * k;
    }
    return v;
}

std::ostream& operator<<(std::ostream& os, Vector v){
    os << '{';
    os << v[0];
    for(int i=1; i<NDIM; i++){
        os << "," << v[i];
    }
    os << '}';
    return os;
}

Vector Vector::operator+(const Vector rhs){
    return add_vec(*this, rhs);
};

Vector Vector::operator+(const value rhs){
    return *this + Vector(rhs);
};

value Vector::operator*(const Vector rhs){
    return mul_vec(*this, rhs);
};

Vector Vector::operator*(const value rhs){
    return mul_val(*this, rhs);
};

Vector Vector::operator-(const Vector rhs){
    return sous_vec(*this, rhs);
};

void add_vec_p(Vector& rhs, const Vector r){
    rhs = rhs + r;
} 

void mul_vec_p(Vector& rhs, const Vector r){
    rhs = rhs * r;
} 



Vector& Vector::operator+=(const Vector rhs){
    *this = *this + rhs;
    return *this;
};

Vector& Vector::operator-=(const value k){
    *this = *this - Vector(k);
    return *this;
};

Vector& Vector::operator-=(const Vector rhs){
    *this = *this - rhs;
    return *this;
}

Vector& Vector::operator*=(const value k){
    *this = *this * k;
    return *this;
};