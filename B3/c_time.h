#ifndef C_TIME_H
#define C_TIME_H

#include <iostream>
#include <iomanip>

class c_time {
private:
    int gio;
    int phut;
    int giay;
    void chuan_hoa();

public:
    c_time(int g = 0, int p = 0, int gy = 0);

    c_time operator+(int giay_them) const;
    c_time operator-(int giay_bot) const;

    c_time& operator++();
    c_time operator++(int);

    c_time& operator--();
    c_time operator--(int);

    friend std::istream& operator>>(std::istream& is, c_time& t);
    friend std::ostream& operator<<(std::ostream& os, const c_time& t);
};

#endif
