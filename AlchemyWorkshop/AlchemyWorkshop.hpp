#pragma	once
#include "RecipeManager.hpp"
#include "PotionRecipe.hpp"
#include "StockManager.hpp"

class AlchemyWorkshop {
private:
    RecipeManager recipeManager;
    StockManager stockManager;

public:
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    PotionRecipe* searchRecipeByName(const std::string& name);
    std::vector<PotionRecipe> searchRecipeByIngredient(const std::string& ingredient);

    void dispensePotion(std::string potionName);
    int getStock(std::string potionName);
    void returnPotion(std::string potionName);
};