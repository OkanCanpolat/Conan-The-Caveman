#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {
	
public:
	void initialiseJoysticks();
	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}
	bool getMouseButtonState(int buttonNumber){
		return m_mouseButtonStates[buttonNumber];
	}
	static InputHandler* Instance();
	void update();
	void clean();
	Vector2D* getMousePosition();
	bool isKeyDown(SDL_Scancode key);
	void reset();

private:
	InputHandler();
	~InputHandler() {}
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition = new Vector2D(0,0);
	const Uint8* m_keystates;
	static InputHandler* s_pInstance;
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
	
	// handle keyboard events
	void onKeyDown();
	void onKeyUp();

	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

};

	typedef InputHandler TheInputHandler;