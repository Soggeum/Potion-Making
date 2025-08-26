#include "StockManager.hpp"

void StockManager::initializeStock(std::string potionName)
{
    potionStock[potionName] = MAX_STOCK;
    std::cout << ">> 포션 " << potionName << "이(가) " << MAX_STOCK << "개 생성되었습니다.\n";
}

int StockManager::getStock(std::string potionName) const { return potionStock.find(potionName)->second; }

void StockManager::returnPotion(std::string potionName)
{
    potionStock[potionName] = MAX_STOCK;
    std::cout << ">> 포션 " << potionName << "이(가) " << MAX_STOCK << "개로 반납되었습니다.\n";
}

bool StockManager::dispensePotion(std::string potionName)
{
    if (getStock(potionName)) {
        std::cout << ">> 플레이어에게 " << potionName << "이(가) " << "1개 지급되었습니다.\n";
        potionStock[potionName]--;
        return true;
    }
    else
    {
        std::cout << ">> 플레이어에게 " << potionName << "을(를) 지급할 수 없습니다.(재고: 0)\n";
        return false;
    }
}