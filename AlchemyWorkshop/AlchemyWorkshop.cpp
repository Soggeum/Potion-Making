#include "AlchemyWorkshop.hpp"

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
    recipeManager.addRecipe(name, ingredients);
    stockManager.initializeStock(name);
}

// ��� ������ ��� �޼���
void AlchemyWorkshop::displayAllRecipes() const {
    const std::vector<PotionRecipe>& recipes = recipeManager.getAllRecipes();

    if (recipes.empty()) {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "\n--- [ ��ü ������ ��� ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << "- ���� �̸�: " << recipes[i].potionName << "(" << stockManager.getStock(recipes[i].potionName) << "��)" << std::endl;
        std::cout << "  > �ʿ� ���: ";

        // ��� ����� ��ȸ�ϸ� ���
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
            std::cout << recipes[i].ingredients[j];
            // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
            if (j < recipes[i].ingredients.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}

PotionRecipe* AlchemyWorkshop::searchRecipeByName(const std::string& name)
{
    return recipeManager.findRecipeByName(name);
}

std::vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(const std::string& ingredient)
{
    return recipeManager.findRecipeByIngredient(ingredient);
}

void AlchemyWorkshop::dispensePotion(std::string potionName) 
{ 
    if (!recipeManager.findRecipeByName(potionName)) {
        std::cout << ">> �ش� �̸��� ������ �����ϴ�." << std::endl;
        return;
	}
    stockManager.dispensePotion(potionName); 
}
int AlchemyWorkshop::getStock(std::string potionName) 
{ 
    return stockManager.getStock(potionName); 
}
void AlchemyWorkshop::returnPotion(std::string potionName) 
{ 
    if (!recipeManager.findRecipeByName(potionName)) {
        std::cout << ">> �ش� �̸��� ������ �����ϴ�." << std::endl;
        return;
    }
    stockManager.returnPotion(potionName); 
}