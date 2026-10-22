#include "person.h"

Person::Person(string name, string number, address address, credit_card cc)
{
    name_ = name;
    phone_ = number;
    person_address_ = address;
    person_credit_card_ = cc;
}

Person::Person()
{
    name_ = "";
    phone_ = "";
    person_address_.address_line1 = "";
    person_address_.address_line2 = "";
    person_address_.city = "";
    person_address_.state = "";
    person_address_.zip = "";
    person_credit_card_.cc_number = 0;
    person_credit_card_.current_balance = 0.00;
    person_credit_card_.limit = 0.00;
}

void Person::name(string name)
{
    name_ = name;
}

string Person::name()
{
    return name_;
}

void Person::phone(string number)
{
    phone_ = number;
}

string Person::phone()
{
    return phone_;
}

void Person::person_address(address address)
{
    person_address_ = address;
}

address Person::person_address()
{
    return person_address_;
}

void Person::person_credit_card(credit_card cc)
{
    person_credit_card_ = cc;
}

credit_card Person::person_credit_card()
{
    return person_credit_card_;
}

string Person::person_info()
{
    return name_ + "\n" + phone_ + "\n" + person_address_.address_info() + "\n" + person_credit_card_.credit_card_info();
}
