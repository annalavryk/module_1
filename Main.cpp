#include "Product1.h"

int main() {
    vector<Product> products;

    if (!Product::readFromJson("data.json", products)) {
        cout << "Read error\n";
        return 1;
    }

    
    cout << "From JSON:\n";
    Product::printAll(products);

    Product::filterZeroQuantity(products);

    
    cout << "After filtering (quantity != 0):\n";
    Product::printAll(products);

    if (!Product::writeToCSV("result.csv", products)) {
        cout << "Write error\n";
        return 1;
    }

    cout << "Success!\n";
    return 0;
}