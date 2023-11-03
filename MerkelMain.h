#pragma once
#include <vector>
#include "OrderBookEntry.h"

class MerkelMain {
    public:
        MerkelMain();
        /** Call this to start the simulation */
        void init();
    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void goToNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);

        std::vector<OrderBookEntry> orders;
};