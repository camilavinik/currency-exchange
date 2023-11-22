#include <iostream>
#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain() {}

void MerkelMain::init() {
   loadOrderBook();
   int input;

   while(true) {
      printMenu();
      input = getUserOption();
      processUserOption(input);
   }
}

void MerkelMain::loadOrderBook() {
   orders = CSVReader::readCSV("20200317.csv");
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
}

void MerkelMain::printHelp() {
   std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl;
}

void MerkelMain::printMarketStats() {
   std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
   unsigned int bids = 0;
   unsigned int asks = 0;

   for (OrderBookEntry& e : orders) {
      if (e.orderType == OrderBookType::ask) {
         asks ++;
      } else if (e.orderType == OrderBookType::bid) {
         bids ++;
      }
   }

   std::cout << "OrderBook asks: " << asks << std::endl;
   std::cout << "OrderBook bids: " << bids << std::endl;
}

void MerkelMain::enterOffer() {
   std::cout << "Mark and offer - enter the amount" << std::endl;
}

void MerkelMain::enterBid() {
   std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet() {
   std::cout << "Your wallet is empty" << std::endl;
}

void MerkelMain::goToNextTimeframe() {
   std::cout << "Going to next time frame" << std::endl;
}

int MerkelMain::getUserOption() {
   std::cout << "Type in 1-6" << std::endl;
   
   int userOption;
   std::cin >> userOption;
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
      enterOffer();
   } else if (userOption == 4) {
      enterBid();
   } else if (userOption == 5) {
      printWallet();
   } else if (userOption == 6) {
      goToNextTimeframe();
   }
}