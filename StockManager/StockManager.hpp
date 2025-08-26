#pragma	once
#include <iostream>
#include <map>
#include <string>   

class StockManager
{
private:
    std::map<std::string, int> potionStock;
    const int MAX_STOCK = 3;

public:
    void initializeStock(std::string potionName);
    int getStock(std::string potionName) const;
    void returnPotion(std::string potionName);
    bool dispensePotion(std::string potionName);
};