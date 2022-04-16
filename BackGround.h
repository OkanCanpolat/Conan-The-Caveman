#pragma once
#include "PlatformerObject.h"
#include "Camera.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObjectFactory.h"


class BackGround :
	public PlatformerObject
{
	virtual void load(std::unique_ptr<LoaderParams> const& pParams)
	{
		PlatformerObject::load(std::move(pParams));
	}

	virtual void draw()
	{
		if (TheCamera::Instance()->getPosition().m_x > 16400) 
		{
			TextureManager::Instance()->drawFrame(m_textureID,
				(Uint32)m_position.getX(), (Uint32)m_position.getY(), 
				m_width, m_height, m_currentRow, m_currentFrame,
				TheGame::Instance()->getRenderer(), m_angle, m_alpha);
		}
	}


};


class BackGroundCreator 
	: public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new BackGround();
	}
};