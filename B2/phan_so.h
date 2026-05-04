#ifndef PHAN_SO_H
#define PHAN_SO_H

#include <iostream>
#include <cmath>

class phan_so {
private:
    int tu_so;
    int mau_so;
    void rut_gon();

public:
    phan_so(int tu = 0, int mau = 1);

    phan_so operator+(const phan_so& khac) const;
    phan_so operator-(const phan_so& khac) const;
    phan_so operator*(const phan_so& khac) const;
    phan_so operator/(const phan_so& khac) const;

    bool operator==(const phan_so& khac) const;
    bool operator>(const phan_so& khac) const;
    bool operator<(const phan_so& khac) const;

    friend std::istream& operator>>(std::istream& is, phan_so& ps);
    friend std::ostream& operator<<(std::ostream& os, const phan_so& ps);
};

#endif
