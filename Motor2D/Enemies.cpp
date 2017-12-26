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
	background_texture = App->tex->Load("gui/background2.png");
	buttons_texture = App->tex->Load("gui/buttons2.png");


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
		InGameButtons();
	}

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
			enemy.add(App->gui->AddEnemy(200, 200, i));
			enemy_selector[i]->state = FOCUSED;
			 
		}
		p2List_item<Enemy> *item;
		item = enemy.start;

		while (item != nullptr)
		{
			if (item->data.exit->state == L_MOUSE_PRESSED)
			{
				App->gui->DeleteUI(item->data.exit->parent);
				App->gui->DeleteUI(item->data.more);
				App->gui->DeleteUI(item->data.exit);	
			}
			item = item->next;
		}
	}
}



