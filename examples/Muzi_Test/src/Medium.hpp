#pragma once

class Strom
{
public:
    Strom(int c, int v):current_(c), voltage_(v) {}
    ~Strom() {
        current_ = 0;
        voltage_ = 0;
    }

    void set_current(int c);
    void set_voltage(int v);
    int read_current();
    int read_voltage();
private:
    int current_;
    int voltage_;
};