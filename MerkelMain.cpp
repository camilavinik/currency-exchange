#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <iostream>
#include <vector>

MerkelMain::MerkelMain() {}

void MerkelMain::init() {
   int input;
   currentTime = orderBook.getEarliestTime();
   wallet.insertCurrency("BTC", 10);

   while(true) {
      printMenu();
      input = getUserOption();
      processUserOption(input);
   }
}

void MerkelMain::printMenu() {
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

   std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp() {
   std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl;
}

void MerkelMain::printMarketStats() {
   for (std::string const p : orderBook.getKnownProducts()) {
      std::cout << "Product: " << p << std::endl;
      std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
   
      std::cout << "Asks seen: " << entries.size() << std::endl;
      std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
      std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
   }
}

void MerkelMain::enterAsk() {
   std::cout << "Mark and offer - enter the amount: product,price,amount eg ETH/BTC,200,0.5" << std::endl;
   std::string input;
   std::getline(std::cin, input);

   std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
   if (tokens.size() != 3) {
      std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
   } else {
      try {   
         OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
         obe.username = "simuser";
         if (wallet.canFulfillOrder(obe)) {
            std::cout << "Wallet looks good." << std::endl;
            orderBook.insertOrder(obe);
         } else {
            std::cout << "Wallet has insufficient funds." << std::endl;
         }
      } catch(const std::exception& e) {
         std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
      }
   }

   std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid() {
   std::cout << "Mark and bid - enter the amount: product,price,amount eg ETH/BTC,200,0.5" << std::endl;
   std::string input;
   std::getline(std::cin, input);

   std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
   if (tokens.size() != 3) {
      std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
   } else {
      try {   
         OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
         obe.username = "simuser";
         if (wallet.canFulfillOrder(obe)) {
            std::cout << "Wallet looks good." << std::endl;
            orderBook.insertOrder(obe);
         } else {
            std::cout << "Wallet has insufficient funds." << std::endl;
         }
      } catch(const std::exception& e) {
         std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
      }
   }

   std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::printWallet() {
   std::cout << "Your wallet is empty" << std::endl;
   std::cout << wallet.toString() << std::endl;
}

void MerkelMain::goToNextTimeframe() {
   std::cout << "Going to next time frame" << std::endl;

   std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
   std::cout << "Sales: " << sales.size() << std::endl;
   for (OrderBookEntry& sale : sales) {
      std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;
      if (sale.username == "simuser") {
         // update wallet
         wallet.processSale(sale);
      }
   }
   
   currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption() {
   std::cout << "Type in 1-6" << std::endl;
   
   int userOption = 0;
   std::string line;
   std::getline(std::cin, line);

   try {
      userOption = std::stoi(line);
   } catch(const std::exception& e) {
      //
   }

   std::cout << "You chose: " << userOption << std::endl;
   return userOption;
}

void MerkelMain::processUserOption(int userOption) {
   if (userOption < 1 || userOption > 6) { // bad input
      std::cout << "Invalid choice. Choose 1-6 " << std::endl;
   } else if (userOption == 1) {
      printHelp();
   } else if (userOption == 2) {
      printMarketStats();
   } else if (userOption == 3) {
      enterAsk();
   } else if (userOption == 4) {
      enterBid();
   } else if (userOption == 5) {
      printWallet();
   } else if (userOption == 6) {
      goToNextTimeframe();
   }
}