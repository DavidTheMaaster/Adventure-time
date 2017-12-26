#ifndef _UIElement_
#define _UIElement_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Textures.h"
#include "Animation.h"

struct _TTF_Font;

enum UI_TYPE
{
	NO_UI_TYPE,
	LABEL,
	BUTTON,
	IMAGE,
	ENEMY
};

enum UI_STATE {
	NO_STATE,
	MOUSE_ENTER,
	MOUSE_LEAVE,
	L_MOUSE_PRESSED,
	R_MOUSE_PRESSED,
	FOCUSED,
};

class UIElement
{

public:

	SDL_Rect rect;
	SDL_Rect current_animation;
	iPoint pos;
	iPoint original_pos;
	bool fliped;
	int w;
	int h;
	bool dragable = false;


	j1Module* callback = nullptr;
	UIElement* parent = nullptr;
	UIElement* child = nullptr;

	bool debug;

	iPoint mouse_movement;
	iPoint mouse2;

	uint type;

	UI_STATE state;
	_TTF_Font* font = nullptr;

	const SDL_Texture *texture = nullptr;


public:

	UIElement(int x, int y, uint type, const SDL_Texture* texture, UIElement* parent = nullptr);
	virtual ~UIElement() { };

	virtual void Draw();
	virtual void Update();

	void ChangeLabel(const char* text, uint colors);

	int GetSliderValue(UIElement* zap, UIElement* slider);
public:
	Animation anim;



};

#endif
