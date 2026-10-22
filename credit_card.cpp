#include "credit_card.h"
#include <sstream> //treat a string object like an iostream
#include <iomanip> //input/output manipulator for setting floating-point precision
//no <iostream> because no need to print when building a string

bool credit_card::make_purchase(double purchase_amount) {
    if (purchase_amount <= 0) {
        return false;   // negative purchase amount
    }
    if (current_balance + purchase_amount > limit) {
        return false;   // over the credit limit
    }
    current_balance += purchase_amount;
    return true;
}

bool credit_card::make_payment(double payment_amount) {
    if (payment_amount <= 0) {
        return false;   // negative payment amount
    }
    if (payment_amount > current_balance) {
        return false;   // paying more than is owed
    }
    current_balance -= payment_amount;
    return true;
}

std::string credit_card::credit_card_info() {
    std::ostringstream to_string;
    to_string << std::fixed << std::setprecision(2);
    to_string << "Card Number: " << cc_number << "\n" << "Credit Limit: $" << limit << "\n" << "Current Balance: $" << current_balance;
    return to_string.str();
}