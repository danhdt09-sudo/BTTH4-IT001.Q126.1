#ifndef DA_THUC_H
#define DA_THUC_H

#include <iostream>

class da_thuc {
private:
    int bac;
    double* he_so;

public:
    da_thuc();
    da_thuc(int b);
    ~da_thuc();

    da_thuc(const da_thuc& khac);
    da_thuc& operator=(const da_thuc& khac);

    double tinh_gia_tri(double x) const;

    friend std::istream& operator>>(std::istream& is, da_thuc& dt);
    friend std::ostream& operator<<(std::ostream& os, const da_thuc& dt);
};

#endif
