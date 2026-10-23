#include "store.h"

Store::Store()
{
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}

void Store::num_customers(int c_num) //setter
{
    if (c_num >= 0 && c_num <= 100)
    {
        num_customers_ = c_num;
    }
}
int Store::num_customers() //getter
{}

void Store::num_products(int p_num)
{}

int Store::num_products()
{}

void Store::num_transactions(int t_num)
{}

int Store::num_transactions()
{}

bool Store::add_customer(Person customer)
{}

bool Store::update_customer(int index, Person customer)
{}

Person Store::get_customer(int index)
{}

bool Store::add_product(product item)
{}

product Store::get_product(int index)
{}

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
{}
