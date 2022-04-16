#pragma once
#include "GameState.h"
#include <vector>
#include "PlatformerObject.h"
#include "GameObject.h"
#include "Level.h"
#include "CollisionManager.h"



class PlayState 
	: public GameState
{
public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

	

private:
	Level* pLevel;
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	CollisionManager m_collisionManager;
};