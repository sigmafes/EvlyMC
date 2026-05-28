#include "StonecutterScreen.h"
#include "../../../../world/item/crafting/Recipes.h"
#include "../../components/InventoryPane.h"
#include "../../components/ItemPane.h"
#include "../../components/ScrolledSelectionList.h"

StonecutterScreen::StonecutterScreen()
:   super(Recipes::getInstance()->getRecipes())
{
}

bool StonecutterScreen::filterRecipe(const Recipe& recipe)
{
    return recipe.getRecipeType() == RecipeType::StoneCutter;
}
