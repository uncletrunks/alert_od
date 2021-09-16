
#include "../include/general.h"

int initPAD(void);
void closePAD(void);
int getPAD(void);

int	pad_type;
int	pads;
int	trgs;
int	reps;

SDL_Joystick *joys;
Uint8 *keys;

static int pads_old;
static int rep_cnt;

int initPAD(void)
{
	if(SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0){
		return 0;
    }

	if(SDL_NumJoysticks() > 0){
		joys = SDL_JoystickOpen(0);
		SDL_JoystickEventState(SDL_ENABLE);
	}else{
		joys = NULL;
	}

	pad_type = 0;
	trgs = 0;
	reps = 0;

	rep_cnt = 0;

	return 1;
}

void closePAD(void)
{
	if(SDL_JoystickOpened(0)){
		SDL_JoystickClose(joys);
	}
}

int getPAD(void)
{
	int x = 0, y = 0;
	int pad = 0;

	keys = SDL_GetKeyState(NULL);

	if(joys){
		x = SDL_JoystickGetAxis(joys, 0);
		y = SDL_JoystickGetAxis(joys, 1);
	}
	if(pad_type == 0){
		if(keys[SDLK_RIGHT] == SDL_PRESSED || keys[SDLK_KP6] == SDL_PRESSED || x > JOYSTICK_AXIS){
			pad |= PAD_RIGHT;
		}
		if(keys[SDLK_LEFT] == SDL_PRESSED || keys[SDLK_KP4] == SDL_PRESSED || x < -JOYSTICK_AXIS){
			pad |= PAD_LEFT;
		}
		if(keys[SDLK_DOWN] == SDL_PRESSED || keys[SDLK_KP2] == SDL_PRESSED || y > JOYSTICK_AXIS){
			pad |= PAD_DOWN;
		}
		if(keys[SDLK_UP] == SDL_PRESSED || keys[SDLK_KP8] == SDL_PRESSED || y < -JOYSTICK_AXIS){
			pad |= PAD_UP;
		}
	}
	if(pad_type == 1){
		if(keys[SDLK_RIGHT] == SDL_PRESSED || keys[SDLK_KP6] == SDL_PRESSED || x > JOYSTICK_AXIS){
			pad |= PAD_RIGHT;
		}
		if(keys[SDLK_LEFT] == SDL_PRESSED || keys[SDLK_KP4] == SDL_PRESSED || x < -JOYSTICK_AXIS){
			pad |= PAD_LEFT;
		}
		if(keys[SDLK_DOWN] == SDL_PRESSED || keys[SDLK_KP2] == SDL_PRESSED || y > JOYSTICK_AXIS){
			pad |= PAD_DOWN;
		}
		if(keys[SDLK_UP] == SDL_PRESSED || keys[SDLK_KP8] == SDL_PRESSED || y < -JOYSTICK_AXIS){
			pad |= PAD_UP;
		}
	}

	int	btn1 = 0, btn2 = 0, btn3 = 0, btn4 = 0, btn5 = 0, btn6 = 0, btn7 = 0, btn8 = 0, btn9 = 0, btnA = 0;

	if(joys){
		btn1 = SDL_JoystickGetButton(joys, 0);
		btn2 = SDL_JoystickGetButton(joys, 1);
		btn3 = SDL_JoystickGetButton(joys, 2);
		btn4 = SDL_JoystickGetButton(joys, 3);
		btn5 = SDL_JoystickGetButton(joys, 4);
		btn6 = SDL_JoystickGetButton(joys, 5);
		btn7 = SDL_JoystickGetButton(joys, 6);
		btn8 = SDL_JoystickGetButton(joys, 7);
		btn9 = SDL_JoystickGetButton(joys, 8);
		btnA = SDL_JoystickGetButton(joys, 9);
	}
	if(pad_type == 0){
		if(keys[SDLK_LCTRL] == SDL_PRESSED || btn1){
			pad |= PAD_BUTTON1;
		}
		if(keys[SDLK_LALT] == SDL_PRESSED || btn2){
			pad |= PAD_BUTTON2;
		}
		if(keys[SDLK_RETURN] == SDL_PRESSED || btn3){
			pad |= PAD_BUTTON3;
		}
	}
	if(pad_type == 1){
		if(keys[SDLK_BACKSLASH] == SDL_PRESSED || btn1){
			pad |= PAD_BUTTON1;
		}
		if(keys[SDLK_RSHIFT] == SDL_PRESSED || btn2){
			pad |= PAD_BUTTON2;
		}
		if(keys[SDLK_p] == SDL_PRESSED || btn3){
			pad |= PAD_BUTTON3;
		}
	}
	if(btn4){
		pad |= PAD_BUTTON4;
	}
	if(btn5){
		pad |= PAD_BUTTON5;
	}
	if(btn6){
		pad |= PAD_BUTTON6;
	}
	if(btn7){
		pad |= PAD_BUTTON7;
	}
	if(btn8){
		pad |= PAD_BUTTON8;
	}
	if(btn9){
		pad |= PAD_BUTTON9;
	}
	if(btnA){
		pad |= PAD_BUTTONA;
	}
	pads_old = pads;
	pads = pad;
	trgs = pads & ~pads_old;

	reps = 0;
	if(pads){
		if(!trgs && !rep_cnt){
			reps = pads;
			rep_cnt = REP_MIN;
		}else if(!trgs && rep_cnt){
			rep_cnt--;
		}else if(trgs){
			rep_cnt = REP_MAX;
			reps = trgs;
		}
	}else{
		rep_cnt = 0;
	}

	return pad;
}
