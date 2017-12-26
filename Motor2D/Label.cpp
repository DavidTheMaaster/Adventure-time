#include "Label.h"
#include "j1App.h"
#include "j1Gui.h"

Label::Label(int x, int y, uint type, const SDL_Texture * texture, UIElement* parent) : UIElement(pos.x, pos.y, type, texture, parent)
{
	this->parent = parent;

	if (parent != nullptr)
	{
		pos.x = parent->pos.x + x;
		pos.y = parent->pos.y + y;
	}
	else {
		pos.x = x;
		pos.y = y;
	}

	
}