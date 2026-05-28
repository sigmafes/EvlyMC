#ifndef STONECUTTER_RECIPE_H
#define STONECUTTER_RECIPE_H

#include "Recipe.h"

class StonecutterRecipe : public Recipe {
public:
    StonecutterRecipe(ItemInstance output, ItemInstance input);

    bool matches(CraftingContainer* craftSlots) override;
    ItemInstance assemble(CraftingContainer* craftSlots) override;
    int getCraftingSize() override;
    ItemInstance getResultItem() const override;
    int getMaxCraftCount(ItemPack& fromItems) override;
    int size() override;

    RecipeType getRecipeType() const override { return RecipeType::StoneCutter; }

private:
    ItemInstance output;
    ItemInstance input;
};

#endif // STONECUTTER_RECIPE_H
