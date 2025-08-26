#include "StockManager.hpp"

void StockManager::initializeStock(std::string potionName)
{
    potionStock[potionName] = MAX_STOCK;
    std::cout << ">> ���� " << potionName << "��(��) " << MAX_STOCK << "�� �����Ǿ����ϴ�.\n";
}

int StockManager::getStock(std::string potionName) const { return potionStock.find(potionName)->second; }

void StockManager::returnPotion(std::string potionName)
{
    potionStock[potionName] = MAX_STOCK;
    std::cout << ">> ���� " << potionName << "��(��) " << MAX_STOCK << "���� �ݳ��Ǿ����ϴ�.\n";
}

bool StockManager::dispensePotion(std::string potionName)
{
    if (getStock(potionName)) {
        std::cout << ">> �÷��̾�� " << potionName << "��(��) " << "1�� ���޵Ǿ����ϴ�.\n";
        potionStock[potionName]--;
        return true;
    }
    else
    {
        std::cout << ">> �÷��̾�� " << potionName << "��(��) ������ �� �����ϴ�.(���: 0)\n";
        return false;
    }
}