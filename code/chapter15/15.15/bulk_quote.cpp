#include "bulk_quote.h"

void Bulk_quote::debug() const {
    Quote::debug();
    cout << "quantity: " << quantity << " "
         << "discount: " << discount << endl;
}