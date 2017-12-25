#include "Menu.h"
#include "j1App.h"
#include "j1Gui.h"
#include "UI.h"
#include "j1Textures.h"
#include "j1Input.h"
#include "FadeToBlack.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

inline bool Menu::Start()
{
	background_texture = App->tex->Load("gui/background.png");
	buttons_texture = App->tex->Load("gui/buttons.png");

	background = App->gui->AddImage(0, 0, background_texture);
	play_button = App->gui->AddButton(220, 550, buttons_texture, {}, App->scene);
	exit_button = App->gui->AddButton(700, 550, buttons_texture, {}, App->scene, true);
	App->gui->AddLabel(130, 0, "PLAY", BLACK, ADVENTURE_TIME, 45, play_button);
	App->gui->AddLabel(140, 0, "EXIT", BLACK, ADVENTURE_TIME, 45, exit_button);

	return true;
}

bool Menu::Update()
{
	bool ret = true;


	ret = MenuButtons();


	return ret;
}

bool Menu::CleanUp()
{
	App->tex->UnLoad(buttons_texture);
	App->tex->UnLoad(background_texture);

	return true;
}

bool Menu::MenuButtons()
{
	bool ret = true;
	if (exit_button->state == L_MOUSE_PRESSED)
	{
		ret = false;
	}
	if (play_button->state == L_MOUSE_PRESSED)
	{
		App->scene->scene = IN_GAME;
		App->fade->FadeToBlack(App->scene,App->scene,0.5f);
	}

	return ret;
}
