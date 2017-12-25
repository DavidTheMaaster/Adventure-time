#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"


struct SDL_Texture;
struct Menu;
struct Enemies;

enum scene
{
	NO_SCENE,
	MENU,
	IN_GAME,
};

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update();

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

public:
	uint scene = 1;
private:
	Menu* menu = nullptr;
	Enemies* enemies = nullptr;

	SDL_Texture* cursor;
};

#endif // __j1SCENE_H__