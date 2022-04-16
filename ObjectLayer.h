#pragma once
#include "Layer.h"
#include <vector>
#include "GameObject.h"
#include "CollisionManager.h"
//#include "Level.h"

class ObjectLayer
	: public Layer
{
public:
    virtual ~ObjectLayer();

    // pass a level object through
    virtual void update(Level* pLevel);
    virtual void render(Player* player);

    // return a pointer to this layers objects, the level parser will fill this
    std::vector<GameObject*>* getGameObjects() { return &m_gameObjects; }

private:

    // check for collisions between game objects
    CollisionManager m_collisionManager;

    // a list of game objects
    std::vector<GameObject*> m_gameObjects;
};