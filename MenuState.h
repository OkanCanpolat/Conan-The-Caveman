#pragma once

#include <vector>
#include "GameState.h"
#include "GameObject.h"

class MenuState 
	: public GameState
{
protected:

	typedef void(*Callback)(); // function pointer
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

	std::vector<Callback> m_callbacks;
};