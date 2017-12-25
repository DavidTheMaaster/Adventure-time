#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "UI.h"
#include "SDL\include\SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class Button : public UIElement
{
public:
	Button(int pos_x, int pos_y, uint type, SDL_Texture* texture, Animation* anim,  j1Module* callback, bool dragable = false, bool fliped = false, UIElement* parent = nullptr);
public:
	int patata;
};



#endif // !_BUTTON_H__