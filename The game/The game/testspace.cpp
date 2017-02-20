#include "allegro5\allegro5.h"
#include "allegro5\allegro_native_dialog.h"
#include "allegro5\allegro_primitives.h"
#include <iostream>

enum KEYS { UP, DOWN };

int main(int argc, char** argv)
{
	bool done = false;
	bool redraw = true;
	int xPos = 100;
	int yPos = 240;
	bool keys[4] = { false,false };
	int FPS = 60;

	al_init();
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize allegro!", NULL, NULL);
		return -1;
	}
	display = al_create_display(1280, 960);
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize display", NULL, NULL);
		return -1;
	}

	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_hide_mouse_cursor(display);
	int counter = 0;
	int r = 255, b = 255, g = 255;
	al_start_timer(timer);
	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;


			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			xPos = ev.mouse.x;
			yPos = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.button & 2) {
				counter++;
				r = 10;
				b = xPos%255;
				g = yPos%255;
				al_clear_to_color(al_map_rgb(counter + 3, 0, 250 - counter));
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER) {
			yPos -= keys[UP] * 10;
			yPos += keys[DOWN] * 10;
			redraw = true;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			al_draw_filled_rectangle(xPos + 50, yPos + 50, xPos - 50, yPos - 50, al_map_rgb(r, g, b));
			al_draw_rounded_rectangle(xPos + 25, yPos + 25, xPos - 25, yPos - 25, 20, 20, al_map_rgb(255, 255, 255), -10);
			

			al_flip_display();
		}
		counter++;
	}



	al_clear_to_color(al_map_rgb(230, 0, 255));
	al_draw_filled_rectangle(xPos + 50, yPos + 50, xPos - 50, yPos - 50, al_map_rgb(255, 255, 255));

	al_flip_display();

	al_rest(5.0);
	al_destroy_display(display);



	return 0;
}