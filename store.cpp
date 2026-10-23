#include "store.h"
#include <stdexcept>

Store::Store()
{
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}

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
{
    if (num_transactions_ >= 100)
    {
        return false;
    }

    transactions_[num_transactions_] = ntransaction;
    num_transactions_++;

    return true;
}

transaction Store::get_transaction(int index)
{
    if (index < 0 || index >= num_transactions_)
    {
        throw std::out_of_range("Invalid transaction index");
    }

    return transactions_[index];
}
bool Store::make_purchase(Person customer, product item, int amount)
{
    int index = find_customer(customer);

    if (index == -1 || amount <= 0 ||
        item.price <= 0 || num_transactions_ >= 100)
    {
        return false;
    }

    // Use the customer's latest information from the store.
    Person updated_customer = customers_[index];
    credit_card card = updated_customer.person_credit_card();

    double total = item.price * amount;

    if (!card.make_purchase(total))
    {
        return false;
    }

    // Save the updated card in the customer object.
    updated_customer.person_credit_card(card);

    transaction new_transaction;
    new_transaction.transaction_number = num_transactions_ + 1;
    new_transaction.customer = updated_customer;
    new_transaction.purchased_item = item;
    new_transaction.quantity = amount;

    if (!add_transaction(new_transaction))
    {
        return false;
    }

    update_customer(index, updated_customer);

    return true;
}

string Store::product_info()
{
    string output;

    for (int i = 0; i < num_products_; i++)
    {
        output += products_[i].product_info() + "\n";
    }

    return output;
}

string Store::transaction_info()
{
    string output;

    for (int i = 0; i < num_transactions_; i++)
    {
        output += transactions_[i].transaction_info() + "\n";
    }

    return output;
}

string Store::customer_info()
{
    string output;

    for (int i = 0; i < num_customers_; i++)
    {
        output += customers_[i].person_info() + "\n\n";
    }

    return output
}

string Store::store_info()
{
    return "Customers:\n" + customer_info()
         + "\nProducts:\n" + product_info()
         + "\nAll Transactions:\n" + transaction_info();
}

string Store::purchase_history(Person customer)
{
    string output;

    for (int i = 0; i < num_transactions_; i++)
    {
        if (transactions_[i].customer.person_credit_card().cc_number ==
            customer.person_credit_card().cc_number)
        {
            output += transactions_[i].transaction_info() + "\n";
        }
    }

    return output;
}

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
