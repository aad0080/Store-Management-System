#include "store.h"

void Store::num_customers(int c_num)
{
    if (c_num >= 0 && c_num <= 100)
    {
        num_customers_ = c_num;
    }
}

int Store::num_customers()
{
    return num_customers_;
}

void Store::num_products(int p_num)
{
    if (p_num >= 0 && p_num <= 100)
    {
        num_products_ = p_num;
    }
}

int Store::num_products()
{
    return num_products_;
}

void Store::num_transactions(int t_num)
{
    if (t_num >= 0 && t_num <= 100)
    {
        num_transactions_ = t_num;
    }
}

int Store::num_transactions()
{
    return num_transactions_;
}

bool Store::add_customer(Person customer)
{
    if (num_customers_ >= 100)
    {
        return false;
    }

    customers_[num_customers_] = customer;
    num_customers_++;

    return true;
}

bool Store::update_customer(int index, Person customer)
{
    if (index < 0 || index >= num_customers_)
    {
        return false;
    }

    if (customers_[index].person_credit_card().cc_number !=
        customer.person_credit_card().cc_number)
    {
        return false;
    }

    customers_[index] = customer;
    return true;
}
Person Store::get_customer(int index)
{
    if (index < 0 || index >= num_customers_)
    {
        throw std::out_of_range("Invalid customer index");
    }

    return customers_[index];
}

bool Store::add_product(product item)
bool Store::add_product(product item)
{
    if (num_products_ >= 100)
    {
        return false;
    }

    products_[num_products_] = item;
    num_products_++;

    return true;
}

product Store::get_product(int index)
{
    if (index < 0 || index >= num_products_)
    {
        throw std::out_of_range("Invalid product index");
    }

    return products_[index];
}

bool Store::add_transaction(transaction ntransaction)
{}

transaction Store::get_transaction(int index)
{}

bool Store::make_purchase(Person customer, product item, int index)
{}

string Store::product_info()
{}

string Store::transaction_info()
{}

string Store::customer_info()
{}

string Store::store_info()
{}

string Store::purchase_history(Person customer)
{}

int Store::find_customer(Person customer)
{
    for (int i = 0; i < num_customers_; i++)
    {
        if (customers_[i].person_credit_card().cc_number ==
            customer.person_credit_card().cc_number)
        {
            return i;
        }
    }
    return -1;
}
