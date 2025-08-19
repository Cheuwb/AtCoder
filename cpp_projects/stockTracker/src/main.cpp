#include "../include/stock_tracker.h"


int main() {
    StockTracker tracker;
    tracker.loadTransactions();  // Load existing data

    while (true) {
        std::cout << "\nStock Tracker Menu:\n"
                  << "1. Add BUY Transaction\n"
                  << "2. Add SELL Transaction\n"
                  << "3. View History\n"
                  << "4. Exit\n"
                  << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 4) break;

        StockTransaction t;
        std::cout << "Enter Stock Symbol: ";
        std::cin >> t.symbol;
        t.transactionType = (choice == 1) ? "BUY" : "SELL";

        std::cout << "Quantity: ";
        std::cin >> t.quantity;
        std::cout << "Price per Share: $";
        std::cin >> t.price;

        tracker.addTransaction(t);

        if (t.transactionType == "SELL") {
            double pnl = tracker.calculateProfitLoss(t);
            std::cout << "Profit/Loss: $" << pnl << std::endl;
        }
    }

    return 0;
}