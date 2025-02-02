#include <limits>
#include "Medium.hpp"

int Strom::read_current()
{
    return current_;
}

int Strom::read_voltage()
{
    return voltage_;
}

void Strom::set_current(int c)
{
    current_ = c;
}

void Strom::set_voltage(int v)
{
    voltage_ = v;
}
