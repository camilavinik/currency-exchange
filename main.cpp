#include <iostream>
#include <vector>
#include "OrderBookEntry.cpp"
#include "MerkelMain.cpp"

int main() {
   MerkelMain app{};
   app.init();

   // std::vector<OrderBookEntry> orders;
   // orders.push_back(OrderBookEntry{
   //    1000, 
   //    0.002, 
   //    "2020/03/17 17:01:24.884492", 
   //    "BTC/USDT", 
   //    OrderBookType::bid
   // });

   // orders.push_back(OrderBookEntry{
   //    2000, 
   //    0.002, 
   //    "2020/03/17 17:01:24.884492", 
   //    "BTC/USDT", 
   //    OrderBookType::bid
   // });

   // for (OrderBookEntry& order: orders) {
   //    std::cout << "The price is " << order.price << std::endl;
   // }
}