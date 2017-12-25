#ifndef _MENU_H__
#define _MENU_H__

#include "j1Scene.h"
#include "Button.h"
#include "Label.h"
#include "Image.h"


class Menu : public j1Scene
{
public:

	Menu();
	~Menu();

	bool Start();
	bool Update();
	bool CleanUp();
	
	bool MenuButtons();



private:
	Button* play_button = nullptr;
	Button* exit_button = nullptr;
	Image* background = nullptr;
	SDL_Texture* buttons_texture = nullptr;
	SDL_Texture* background_texture = nullptr;

};

#endif // !_MENU_H__

