#include "address.h"

string address::address_info()
{
    return address_line1 + "\n" + address_line2 + "\n" + city + ", " + state + " " + zip;
}