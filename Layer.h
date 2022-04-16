#pragma once
//#include "Level.h"

class Level;
class Player;


class Layer
{
public:
	virtual ~Layer() {}
	virtual void render(Player* player) = 0;
	virtual void update(Level* pLevel) = 0;
};