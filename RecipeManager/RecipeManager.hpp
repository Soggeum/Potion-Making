#pragma once
#include "PotionRecipe.hpp"
#include <iostream>
#include <vector>
#include <string>


class RecipeManager
{
private:
    std::vector<PotionRecipe> recipes;

public:
    PotionRecipe* addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    const std::vector<PotionRecipe>& getAllRecipes() const;

    PotionRecipe* findRecipeByName(std::string name);

    std::vector<PotionRecipe> findRecipeByIngredient(std::string ingredient);
};