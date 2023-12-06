#include "OrderBook.h"
#include "CSVReader.h"
#include <map>

OrderBook::OrderBook(std::string filename) {
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> products;

    std::map<std::string, bool> productMap;

    for (OrderBookEntry& e : orders) {
        productMap[e.product] = true;
    }

    // flatten the map to a vector of strings
    for (auto const& e : productMap) {
        products.push_back(e.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp) {
    std::vector<OrderBookEntry> orders_sub;
    return orders_sub;
};
