//code for transaction struct here

#include "transaction.h"
#include <sstream>

std::string transaction::transaction_info()
{    
std::ostringstream output;
    output << "Transaction #: " << transaction_number << "\n";
    output << "Customer: " << customer.person_info() << "\n";
    output << "Product: " << purchased_item.product_info();
    output << "Quantity: " << quantity << "\n";
    return output.str();
}
