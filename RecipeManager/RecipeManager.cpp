#include "RecipeManager.hpp"

PotionRecipe* RecipeManager::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
    recipes.push_back(PotionRecipe(name, ingredients));
    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
    return &recipes.back();
}

const std::vector<PotionRecipe>& RecipeManager::getAllRecipes() const
{
    return recipes;
}

PotionRecipe* RecipeManager::findRecipeByName(std::string name)
{
    for (auto& recipe : recipes) {
        if (recipe.potionName == name) {
            return &recipe;
        }
    }
    return nullptr;
}

std::vector<PotionRecipe> RecipeManager::findRecipeByIngredient(std::string ingredient)
{
    std::vector<PotionRecipe> foundRecipes;
    for (PotionRecipe recipe : recipes) {
        if (find(recipe.ingredients.begin(), recipe.ingredients.end(), ingredient) != recipe.ingredients.end()) {
            foundRecipes.push_back(recipe);
        }
    }
    return foundRecipes;
}