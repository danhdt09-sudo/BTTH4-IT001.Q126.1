#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <iostream>
#include "c_vector.h"

class c_matrix {
private:
    int so_dong;
    int so_cot;
    double** du_lieu;

    void cap_phat(int dong, int cot);
    void thu_hoi();

public:
    c_matrix();
    c_matrix(int dong, int cot);
    ~c_matrix();

    c_matrix(const c_matrix& khac);
    c_matrix& operator=(const c_matrix& khac);

    c_matrix operator+(const c_matrix& khac) const;
    c_matrix operator*(const c_matrix& khac) const;
    c_vector operator*(const c_vector& v) const;

    friend std::istream& operator>>(std::istream& is, c_matrix& m);
    friend std::ostream& operator<<(std::ostream& os, const c_matrix& m);
};

#endif
