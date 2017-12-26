#ifndef _j1GUI_H__
#define _j1GUI_H__

#include "j1Module.h"
#include "p2List.h"
#include "UI.h"
#include "j1Fonts.h"

#define CURSOR_WIDTH 2

class Label;
class Image;
class Button;
class Slider;

enum COLOURS
{
	VERY_BLACK,
	BLACK,
	WHITE,
	RED,
	BLUE,
	GREEN,
	YELLOW
};

enum FONTS
{
	NO_FONT,
	ADVENTURE_TIME,
	CARTOON,
};

enum ENEMIES
{
	ACHUCHA_HOMBRES = 0,
	CHUM_GLUBS,
};


struct Enemy
{
	SDL_Texture* texture;
	Animation animation;
	Button* enemy_card;
	Button* exit;
	Button* more;
};

class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Gui creation functions
	bool Update();


	Label* AddLabel(int x, int y, char* text, uint color, uint font, int size, UIElement* parent = nullptr, Uint32 wrap = 100);
	Image* AddImage(int x, int y, SDL_Texture* texture, Animation anim = {}, bool fliped = false, UIElement* parent = nullptr);
	Button* AddButton(int x, int y, SDL_Texture* texture, Animation anim = {}, j1Module* callback = nullptr, bool dragable = false, bool fliped = false, UIElement* parent = nullptr);


	void DeleteUI(UIElement* element);


	SDL_Color GetColor(int color);
	char* GetFont(uint font);
	bool debug = false;


	Animation GetEnemy(uint type);

	Enemy AddEnemy(int x, int y, uint type);

	p2List<UIElement*> elements;


};

#endif // !_j1GUI_H__