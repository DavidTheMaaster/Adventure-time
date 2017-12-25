#include "Enemies.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"
#include "j1Input.h"

Enemies::Enemies()
{
}

Enemies::~Enemies()
{
}

bool Enemies::Start()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
		enemy[i] = nullptr;
	

	background_texture = App->tex->Load("gui/background2.png");
	buttons_texture = App->tex->Load("gui/buttons2.png");
	enemies_texture = App->tex->Load("characters/enemies.png");
	cross = App->tex->Load("gui/cross.png");


	background = App->gui->AddImage(0, 0, background_texture);

	AddInGameUI();

	started = true;

	return true;
}

bool Enemies::Update()
{
	bool ret = true;

	if (App->scene->scene == IN_GAME && started == true)
	{
		if (delete_mode)
			InGameButtonsDelete();
		else
			InGameButtons();
	}
	 
	if (App->input->GetKey(SDL_SCANCODE_O) == KEY_DOWN)
		delete_mode = !delete_mode;

	return ret;
}

bool Enemies::CleanUp()
{
	return false;
}

void Enemies::AddInGameUI()
{
	background = App->gui->AddImage(0, 0, background_texture);
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		enemy_selector[i] = App->gui->AddButton(0,	i * 40, buttons_texture, {}, this);
	}
	App->gui->AddLabel(30, 5, "Achucha Hombres", BLACK, CARTOON, 20, enemy_selector[0], 200);
	App->gui->AddLabel(30, 5, "Chum Blubs", BLACK, CARTOON, 20, enemy_selector[1], 200);


}


void Enemies::InGameButtons()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
			if (enemy_selector[i]->state == L_MOUSE_PRESSED)
			{
				AddEnemy(200, 200, i);
				enemy_selector[i]->state = FOCUSED;
			}
		
	}
}

void Enemies::InGameButtonsDelete()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemy[i] != nullptr)
		{
			if (enemy[i]->state == L_MOUSE_PRESSED)
			{
				App->gui->DeleteUI(enemy[i]);
			}
		}
	}
}

void Enemies::AddEnemy(int x, int y, uint type)
{
	Animation enemy_animation;
	enemy_animation = GetEnemy(type);
	enemy_animation.Reset();
	enemy[type] = App->gui->AddButton(x,y,enemies_texture, enemy_animation,this,true);
}

Animation Enemies::GetEnemy(uint type)
{
	Animation enemy_animation;

	switch (type)
	{
	case ACHUCHA_HOMBRES:
		enemy_animation.PushBack({ 0,0,217,412 });
		break;
	case CHUM_GLUBS:
		enemy_animation.PushBack({ 216,0,425,412 });
		break;
	default:
		break;
	}

	return enemy_animation;
}