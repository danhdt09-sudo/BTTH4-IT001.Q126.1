#ifndef C_DATE_H
#define C_DATE_H

#include <iostream>
#include <cmath>

class c_date {
private:
    int ngay;
    int thang;
    int nam;

    bool kiem_tra_nam_nhuan(int n) const;
    int lay_so_ngay_trong_thang(int t, int n) const;
    void chuan_hoa();
    long long tinh_khoang_cach_tu_moc() const;

public:
    c_date(int ng = 1, int th = 1, int n = 1);

    c_date operator+(int so_ngay) const;
    c_date operator-(int so_ngay) const;

    c_date& operator++();
    c_date operator++(int);

    c_date& operator--();
    c_date operator--(int);

    int operator-(const c_date& khac) const;

    friend std::istream& operator>>(std::istream& is, c_date& d);
    friend std::ostream& operator<<(std::ostream& os, const c_date& d);
};

#endif
