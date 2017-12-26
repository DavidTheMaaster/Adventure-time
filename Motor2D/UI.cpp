#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"
#include "UI.h"
#include "j1Input.h"
#include "p2Log.h"



UIElement::UIElement(int x, int y, uint type, const SDL_Texture* texture, UIElement* parent)
{
	this->texture = texture;
	App->tex->GetSize(texture, w, h);

	this->type = type;

	pos.x = x;
	pos.y = y;

	rect = { x, y, (int)w, (int)h };
}

void UIElement::Draw()
{

	if (anim.GetCurrentFrame().w != 0)
		rect = anim.GetCurrentFrame();

	if (type == LABEL)
		App->render->Blit(texture, pos.x, pos.y, {}, 0.0, fliped);
	else
		App->render->Blit(texture, pos.x, pos.y, &(rect), 0.0, fliped);
	

	if (App->gui->debug) 
	{
		SDL_Rect rect2 = { pos.x, pos.y, rect.w, rect.h };
		App->render->DrawQuad({ rect2 }, 0, 255, 0, 255, false);
	}

}

void UIElement::Update()
{

	SDL_Rect button_rect;

	if (current_animation.w == 0)
		button_rect = rect;
	else
		button_rect = current_animation;

	if (type == BUTTON) {

		int mouse_x = 0, mouse_y = 0;
		App->input->GetMousePosition(mouse_x, mouse_y);

		if (state == MOUSE_ENTER) {
			state = FOCUSED;
		}

		if ((mouse_x > this->pos.x && mouse_x < this->pos.x + button_rect.w) && (mouse_y > this->pos.y && mouse_y < this->pos.y + button_rect.h) && state != L_MOUSE_PRESSED && state != FOCUSED) {
			state = MOUSE_ENTER;
			this->callback->UIEvent(this, state);
			LOG("Mouse Enter");
		}
		else if (state == FOCUSED && ((mouse_x < this->pos.x || mouse_x > this->pos.x + button_rect.w) || (mouse_y < this->pos.y || mouse_y > this->pos.y + button_rect.h))) {
			state = MOUSE_LEAVE;
			this->callback->UIEvent(this, state);
			LOG("Mouse Leave");
		}
		else if (state == MOUSE_LEAVE)
			state = NO_STATE;

		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN && state == FOCUSED) {
			state = L_MOUSE_PRESSED;
			this->callback->UIEvent(this, state);
			LOG("Mouse Left Click");
		}
		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP && state == L_MOUSE_PRESSED) {
			state = NO_STATE;
			this->callback->UIEvent(this, state);
			LOG("Mouse Stop Left Click");
		}

		if (state == L_MOUSE_PRESSED)
		{
			if (dragable == true)
			{
				if (mouse_x != mouse2.x || mouse_y != mouse2.y) 
				{
					App->input->GetMouseMotion(mouse_movement.x, mouse_movement.y);
					pos.x += mouse_movement.x;
					pos.y += mouse_movement.y;
					this->child->pos.x += mouse_movement.x;
					this->child->pos.y += mouse_movement.y;
					mouse2.x = mouse_x;
					mouse2.y = mouse_y;
				}
			}
		}

	}

}

void UIElement::ChangeLabel(const char* text, uint colors)
{
	SDL_Color color;
	color = App->gui->GetColor(colors);
	_TTF_Font* fonts;
	fonts = this->font;
	App->tex->UnLoad((SDL_Texture*)texture);
	App->font->CalcSize(text, rect.w, rect.h, fonts);
	texture = App->font->Print(text, color, fonts);
}

int UIElement::GetSliderValue(UIElement* zap, UIElement* slider)
{

	return ((zap->pos.x - slider->pos.x) * 100) / (slider->rect.w - zap->rect.w);
}