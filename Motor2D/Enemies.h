#ifndef _ENEMIES_H__
#define _ENEMIES_H__

#define MAX_ENEMIES 2

#include "j1Scene.h"
#include "Button.h"
#include "Label.h"
#include "Image.h"

class Enemies : public j1Scene
{
public:

	Enemies();
	~Enemies();

	bool Start();
	bool Update();
	bool CleanUp();


	void InGameButtons();
	void InGameButtonsDelete();


	void AddInGameUI();

	void AddEnemy(int x, int y, uint type);
	Animation GetEnemy(uint type);


	bool delete_mode = false;

	bool started = false;

private:
	Image* background = nullptr;
	SDL_Texture* buttons_texture = nullptr;
	SDL_Texture* background_texture = nullptr;
	SDL_Texture* enemies_texture = nullptr;
	SDL_Texture* cross = nullptr;


	//Enemy Buttons
	Button* enemy_selector[MAX_ENEMIES];
	Button* enemy[MAX_ENEMIES];

};

#endif // !_ENEMIES_H__

