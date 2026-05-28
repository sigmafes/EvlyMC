#ifndef NET_MINECRAFT_WORLD_ITEM_CRAFTING__Recipe_H__
#define NET_MINECRAFT_WORLD_ITEM_CRAFTING__Recipe_H__

#include "../ItemInstance.h"
#include <map>
#include <vector>

class CraftingContainer;
class Inventory;

enum RecipeType {
    Crafting,
    StoneCutter
};

class ItemPack {
public:
	typedef std::map<int, int> Map;

	void add(int id, int count = 1);
	int  getCount(int id) const;
	void print() const;

	int getMaxMultipliesOf(ItemPack& v) const;
	std::vector<ItemInstance> getItemInstances() const;

	static int getIdForItemInstance(const ItemInstance* ii);
	static int getIdForItemInstanceAnyAux( const ItemInstance* ii );
	static ItemInstance getItemInstanceForId(int id);
private:
	Map items;
};


class Recipe
{
public:
	static const int SIZE_2X2;
	static const int SIZE_3X3;
	static const int ANY_AUX_VALUE = -1;

	virtual ~Recipe() = default;
    virtual bool matches(CraftingContainer* craftSlots) = 0;
	virtual const ItemPack& getItemPack() { return myItems; }
	virtual int getMaxCraftCount(ItemPack& fromItems) = 0;

    virtual int size() = 0;

    virtual ItemInstance assemble(CraftingContainer* craftSlots) = 0;
    virtual ItemInstance getResultItem() const = 0;

	static bool isAnyAuxValue(const ItemInstance* ii) {
		return isAnyAuxValue(ii->id);
	}

	virtual int getCraftingSize() = 0;

    virtual void consumeCraftingIngredients(Inventory* inventory);

    virtual RecipeType getRecipeType() const { return RecipeType::Crafting; }
private:
	static bool isAnyAuxValue(int id);
protected:
	ItemPack myItems;
};

#endif /*NET_MINECRAFT_WORLD_ITEM_CRAFTING__Recipe_H__*/
