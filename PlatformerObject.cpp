#include "PlatformerObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "TileLayer.h"
#include "Player.h"


PlatformerObject::PlatformerObject() : GameObject(),
m_bulletFiringSpeed(0),
m_bulletCounter(0),
m_moveSpeed(0),
m_dyingTime(0),
m_dyingCounter(0),
m_bPlayedDeathSound(false)
{
}


void PlatformerObject::draw() {
	TextureManager::Instance()->drawFrame(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->
		getRenderer(), m_angle, m_alpha);
}

void PlatformerObject::clean() {}


void PlatformerObject::update() {
	m_position += m_velocity;
	m_currentFrame = int(((SDL_GetTicks() / (1000 / 3)) % m_numFrames));
}


void PlatformerObject::load(std::unique_ptr<LoaderParams> const& pParams)
{
	m_position = Vector2D(pParams->getX(), pParams->getY());
	m_velocity = Vector2D(0, 0);
	m_acceleration = Vector2D(0, 0);
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	//m_currentRow = 1;
	//m_currentFrame = 1;
	m_numFrames = pParams->getNumFrames();
}



void PlatformerObject::doDyingAnimation()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / 10)) % m_numFrames));

	if (m_dyingCounter == m_dyingTime)
	{
		m_bDead = true;
	}
	m_dyingCounter++;
}


bool PlatformerObject::checkCollideTile(Vector2D newPos)
{
	if (newPos.m_y + m_height >= 790/*TheGame::Instance()->getGameHeight()
		- 32*/ )
	{
		return false;
	}

	else{

 for (std::vector<TileLayer*>::iterator it = m_pCollisionLayers
	 ->begin(); it != m_pCollisionLayers->end(); ++it)
 {
	 TileLayer* pTileLayer = (*it);
	 std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();

	 Vector2D layerPos = pTileLayer->getPosition();

	 int x, y, tileColumn, tileRow, tileid = 0;

	 x = layerPos.getX() / pTileLayer->getTileSize();
	 y = layerPos.getY() / pTileLayer->getTileSize();

	 Vector2D startPos = newPos;

	 startPos.m_x += 15;
	 startPos.m_y += 20;

	 Vector2D endPos(newPos.m_x + (m_width - 15), (newPos.m_y) +
		 m_height - 4);

	 for (int i = startPos.m_x; i < endPos.m_x; i++)
	 {
		 for (int j = startPos.m_y; j < endPos.m_y; j++)
		 {
			 tileColumn = i / pTileLayer->getTileSize();
			 tileRow = j / pTileLayer->getTileSize();
			 tileid = tiles[tileRow + y][tileColumn + x];
			 if (tileid != 0)
			 {
				 return true;
			 }
		 }
	 }
 }

 return false;

 }

}
