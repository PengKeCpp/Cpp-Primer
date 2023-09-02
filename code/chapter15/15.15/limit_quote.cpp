#include "limit_quote.h"

double Limit_Quote::net_price(size_t cnt) const {
    if (cnt <= quantity) {
        return cnt * price * (1 - discount);
    }
    return (cnt - quantity) * price + quantity * price * (1 - discount);
}

void Limit_Quote::debug() const {
    Quote::debug();
    cout << "quantity: " << quantity << " "
         << "discount: " << discount << endl;
}