#include <iostream>

enum class OrderBookType{bid, ask};

class OrderBookEntry {
   public:
      double price;
      double amount;
      std::string timestamp;
      std::string product;
      OrderBookType orderType;
};

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

   OrderBookEntry order1;

   order1.price = 10000;
   order1.amount = 0.002;
   order1.timestamp = "2020/03/17 17:01:24.884492";
   order1.product = "BTC/USDT";
   order1.orderType = OrderBookType::bid;

   std::cout << "The price is " << order1.price << std::endl;

   return 0;
}