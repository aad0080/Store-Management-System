//code for transaction struct here

#include "transaction.h"
#include <sstream>
std::string transaction::transaction_info()
{    
    std::ostringstream output;
    output << "Transaction #" << transaction_number << "\n";
    output << "Name: " << customer.person_info() << "\n";
    output << purchased_item.product_info();
    output << "Purchase Quantity: " << quantity << "\n";
    output << "Total: $" << purchased_item.price * quantity << "\n";
    return output.str();
}
