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
    for (OrderBookEntry& e : orders) {
        if (e.orderType == type && e.product == product && e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
};

std::string OrderBook::getEarliestTime() {
    std::string earliestTime = orders[0].timestamp;

    return earliestTime;
}

std::string OrderBook::getNextTime(std::string timestamp) {
    std::string next_timestamp = "";

    for (OrderBookEntry& e : orders) {
        if (e.timestamp > timestamp) {
            next_timestamp = e.timestamp;
            break;
        }
    }

    if (next_timestamp == "") {
        next_timestamp = orders[0].timestamp;
    }

    return next_timestamp;
}


double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders) {
    double max = orders[0].price;
    for (OrderBookEntry& e : orders) {
        if (e.price > max) max = e.price;
    }

    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders) {
    double min = orders[0].price;
    for (OrderBookEntry& e : orders) {
        if (e.price < min) min = e.price;
    }

    return min;
}