#include "AlchemyWorkshop.hpp"

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
    recipeManager.addRecipe(name, ingredients);
    stockManager.initializeStock(name);
}

// 모든 레시피 출력 메서드
void AlchemyWorkshop::displayAllRecipes() const {
    const std::vector<PotionRecipe>& recipes = recipeManager.getAllRecipes();

    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << "- 물약 이름: " << recipes[i].potionName << "(" << stockManager.getStock(recipes[i].potionName) << "개)" << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
            std::cout << recipes[i].ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
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
        std::cout << ">> 해당 이름의 포션이 없습니다." << std::endl;
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
        std::cout << ">> 해당 이름의 포션이 없습니다." << std::endl;
        return;
    }
    stockManager.returnPotion(potionName); 
}