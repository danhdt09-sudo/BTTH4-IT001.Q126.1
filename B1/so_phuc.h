#ifndef SO_PHUC_H
#define SO_PHUC_H

#include <iostream>

class so_phuc {
private:
    double phan_thuc;
    double phan_ao;

public:
    so_phuc(double thuc = 0.0, double ao = 0.0);

    so_phuc operator+(const so_phuc& khac) const;
    so_phuc operator-(const so_phuc& khac) const;
    so_phuc operator*(const so_phuc& khac) const;
    so_phuc operator/(const so_phuc& khac) const;

    bool operator==(const so_phuc& khac) const;
    bool operator!=(const so_phuc& khac) const;

    friend std::istream& operator>>(std::istream& is, so_phuc& sp);
    friend std::ostream& operator<<(std::ostream& os, const so_phuc& sp);
};

#endif
