#pragma once
#ifndef STOCK_TRACKER_H
#define STOCK_TRACKER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

struct StockTransaction {
    std::string symbol; // ticker
    std::string transactionType; // buy or sell
    int quantity;
    double price;
    std::string date;
};

class StockTracker {
private:
    std::vector<StockTransaction> transcations;
    const std::string dataFile = "transaction.txt";
    
public:
    void addTransaction(const StockTransaction& transaction);
    double calculateProfitLoss(const StockTransaction& sell);
    void saveToFile(const StockTransaction& transaction);
    void loadTransactions();
    void printHistory();
};

#endif