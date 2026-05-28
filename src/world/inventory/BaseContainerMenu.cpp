#include "BaseContainerMenu.h"
#include "../item/ItemInstance.h"
#include "../item/crafting/Recipe.h"

BaseContainerMenu::BaseContainerMenu( int containerType )
:   containerId(-1),
	containerType(containerType),
	listener(NULL)
{
}

void BaseContainerMenu::setListener( IContainerListener* listener )
{
	if (!(this->listener = listener))
		return;

	if (listener)
		listener->refreshContainer(this, lastSlots = getItems());
}

void BaseContainerMenu::broadcastChanges()
{
	if (!listener)
		return;

	ItemList slots = getItems();
	if (slots.size() != lastSlots.size()) {
		listener->refreshContainer(this, lastSlots = slots);
		return;
	}

	for (unsigned int i = 0; i < slots.size(); i++) {
		ItemInstance& current = slots[i];
		ItemInstance& expected = lastSlots[i];
		if (!ItemInstance::matches(&expected, &current)) {
			expected = current;
			listener->slotChanged(this, i, expected, isResultSlot(i));
		}
	}
}
