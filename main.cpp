#include <iostream>
#include <vector>
#include "OrderBookEntry.cpp"

void printMenu() {
   // 1 print help
   std::cout << "1: Print help" << std::endl;

   // 2 print exchange stats
   std::cout << "2: Print exchange stats " << std::endl;

   // 3 make an offer
   std::cout << "3: Make an offer " << std::endl;

   // 4 make a bid
   std::cout << "4: Make a bid " << std::endl;

   // 5 print wallets
   std::cout << "5: Print wallet " << std::endl;

   // 6 continue
   std::cout << "6: Continue " << std::endl;

   std::cout << "----------------------- " << std::endl;
}

void printHelp() {
   std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl;
}

void printMarketStats() {
   std::cout << "Market looks good" << std::endl;
}

void enterOffer() {
   std::cout << "Mark and offer - enter the amount" << std::endl;
}

void enterBid() {
   std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet() {
   std::cout << "Your wallet is empty" << std::endl;
}

void goToNextTimeframe() {
   std::cout << "Going to next time frame" << std::endl;
}

int getUserOption() {
   std::cout << "Type in 1-6" << std::endl;
   
   int userOption;
   std::cin >> userOption;
   std::cout << "You chose: " << userOption << std::endl;

   return userOption;
}

void processUserOption(int userOption) {
   if (userOption < 1 || userOption > 6) { // bad input
      std::cout << "Invalid choice. Choose 1-6 " << std::endl;
   } else if (userOption == 1) {
      printHelp();
   } else if (userOption == 2) {
      printMarketStats();
   } else if (userOption == 3) {
      enterOffer();
   } else if (userOption == 4) {
      enterBid();
   } else if (userOption == 5) {
      printWallet();
   } else if (userOption == 6) {
      goToNextTimeframe();
   }
}

int main() {
   // printMenu();
   // int userOption = getUserOption();

   // processUserOption(userOption);

   std::vector<OrderBookEntry> orders;
   orders.push_back(OrderBookEntry{
      1000, 
      0.002, 
      "2020/03/17 17:01:24.884492", 
      "BTC/USDT", 
      OrderBookType::bid
   });

   orders.push_back(OrderBookEntry{
      2000, 
      0.002, 
      "2020/03/17 17:01:24.884492", 
      "BTC/USDT", 
      OrderBookType::bid
   });

   for (OrderBookEntry& order: orders) {
      std::cout << "The price is " << order.price << std::endl;
   }

   return 0;
}