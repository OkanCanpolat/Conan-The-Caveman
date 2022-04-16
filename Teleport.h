#pragma once
#include "PlatformerObject.h"
#include "GameObjectFactory.h"
#include "Camera.h"
#include "TextureManager.h"
#include "Game.h"
#include <memory>
#include <iostream>
#include <string>
#include "Player.h"




class Teleport : 
	public PlatformerObject 
{
public:
    Teleport() {
        m_currentFrame = 0;
        m_currentRow = 0;
        m_angle = 0;
        m_alpha = 255;
    }

    virtual void load(std::unique_ptr<LoaderParams> const& pParams)
    {
        PlatformerObject::load(std::move(pParams));
        
    }

    virtual void draw() {

        TextureManager::Instance()->drawFrame(m_textureID, 
            (Uint32)m_position.getX() - TheCamera::Instance()->getPosition().m_x, 
            (Uint32)m_position.getY() - TheCamera::Instance()->getPosition().m_y,
            m_width, m_height, m_currentRow, m_currentFrame, 
            TheGame::Instance()->getRenderer(), m_angle, m_alpha);
    }

    virtual void update() {};

    std::string type() { return "Teleport"; }

    void teleportPlayer(Player* player) {
        player->setPosition(18775, 250);
    }
};




class TeleportCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Teleport();
    }
};