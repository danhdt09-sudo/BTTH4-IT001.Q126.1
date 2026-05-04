#ifndef C_VECTOR_H
#define C_VECTOR_H

#include <iostream>

class c_vector {
private:
    int so_chieu;
    double* toa_do;

public:
    c_vector();
    c_vector(int n);
    ~c_vector();

    c_vector(const c_vector& khac);
    c_vector& operator=(const c_vector& khac);

    c_vector operator+(const c_vector& khac) const;
    c_vector operator*(double he_so_nhan) const;

    friend std::istream& operator>>(std::istream& is, c_vector& v);
    friend std::ostream& operator<<(std::ostream& os, const c_vector& v);

    int lay_so_chieu() const { return so_chieu; }
    double& operator[](int i) { return toa_do[i]; }
    const double& operator[](int i) const { return toa_do[i]; }
};

#endif
