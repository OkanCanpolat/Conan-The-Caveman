#include "ObjectLayer.h"
#include "Game.h"
#include "Level.h"
#include "Camera.h"



ObjectLayer::~ObjectLayer()
{
    for (std::vector<GameObject*>::iterator it = m_gameObjects.begin(); 
        it != m_gameObjects.end(); ++it)// < m_gameObjects.size(); i++)
    {
        delete (*it);
    }
    m_gameObjects.clear();
}



void ObjectLayer::update(Level* pLevel)
{
    

    m_collisionManager.checkPlayerEnemyCollision(pLevel->getPlayer(), 
        (const std::vector<GameObject*>&)m_gameObjects);

    

    // iterate through the objects
    if (!m_gameObjects.empty())
    {
        for (std::vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end();)// < m_gameObjects.size(); i++)
        {
            if (((*it)->getPosition().getX() <= TheCamera::Instance()->getPosition().m_x + TheGame::Instance()->getGameWidth() 
                && ((*it)->getPosition().getY() < TheCamera::Instance()->getPosition().m_y + TheGame::Instance()->getGameHeight() && 
                    (*it)->getPosition().getY() + (*it)->getHeight() > TheCamera::Instance()->getPosition().m_y)) || (*it)->getUpdated())
            {
                (*it)->setUpdated(true);
                (*it)->setUpdating(true);
                (*it)->update();
            }
            else
            {
                if ((*it)->type() != std::string("Player"))
                {
                    (*it)->setUpdating(false);
                }
                else
                {
                    (*it)->update();
                }
            }

            // check if dead or off screen
            if ((*it)->dead() /*|| (*it)->getPosition().m_y - TheCamera::Instance()->getPosition().m_y >
                TheGame::Instance()->getGameHeight()*/)
            {
                std::cout << "deleting";
                delete* it;
                it = m_gameObjects.erase(it); // erase from vector and get new iterator
            }
            else
            {
                ++it; // increment if all ok
            }

        }
    }
}




void ObjectLayer::render(Player* player)
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {

        m_gameObjects[i]->draw();

    }
}