#include "../include/stock_tracker.h"

class StockTracker {
    private:
        std::vector<StockTransaction> transactions;
        const std::string dataFile = "transactions.txt";

    public:
        // add a new transaction line to the text file, looking to port it as a csv?
        void addTransaction(const StockTransaction& transaction) {
            transactions.push_back(transaction);
            saveToFile(transaction);
        }

        // Calculate profit/loss for selling a transaction
        double calculateProfitLoss(const StockTransaction& sell) {
            double totalCost = 0.0;
            int remainingQty = sell.quantity;

            // find matching buy transaction (FIFO)
            for (auto& buy : transactions) {
                if (buy.symbol == sell.symbol && buy.transactionType == "BUY" && buy.quantity > 0) {
                    int usedQty = std::min(remainingQty, buy.quantity);
                    totalCost += usedQty * buy.price;
                    remainingQty -= usedQty;
                    buy.quantity -= usedQty;

                    if (remainingQty == 0) break;
                }
            }

            if (remainingQty > 0) {
                std::cerr << "Warning: Not enough BUY transactions for " << sell.symbol << std::endl;
            }

            double sellValue = sell.quantity * sell.price;
            return sellValue - totalCost;
        }

        // Save transaction to csv
        void saveToFile(const StockTransaction& transaction) {
            std::ofstream outFile(dataFile, std::ios::app);
            if (outFile.is_open()) {
                outFile << transaction.symbol << ","
                        << transaction.transactionType << ","
                        << transaction.quantity << ","
                        << transaction.price << "\n";
                outFile.close();
            }
        }

        void loadTransaction() {
    std::ifstream inFile(dataFile);
    if (!inFile) {
        std::cerr << "Warning: Could not open transaction file\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        StockTransaction temp;
        size_t pos = 0;
        
        // Parse symbol
        pos = line.find(',');
        if (pos == std::string::npos) continue;
        temp.symbol = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Parse type
        pos = line.find(',');
        if (pos == std::string::npos) continue;
        temp.transactionType = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Parse quantity
        pos = line.find(',');
        if (pos == std::string::npos) continue;
        try {
            temp.quantity = std::stoi(line.substr(0, pos));
        } catch (...) {
            continue;  // Skip invalid entries
        }
        line.erase(0, pos + 1);

        // Parse price
        try {
            temp.price = std::stod(line);
        } catch (...) {
            continue;  // Skip invalid entries
        }

        transactions.push_back(temp);
    }
        }

        void printHistory() {
            for (const auto& t : transactions) {
                std::cout << t.symbol << " | " << t.transactionType << " | "
                          << t.quantity << " shares @ $" << t.price << std::endl;
            }
        }
};