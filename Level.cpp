#include "Level.h"
#include "TextureManager.h"
#include "Game.h"
#include "Layer.h"
#include "TileLayer.h"
#include <math.h>
#include <iostream>

Level::Level()
{
}


void Level::render()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render(m_pPlayer);
		
	}
}


void Level::update()
{

	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update(this);
	}
}

Level::~Level()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		delete m_layers[i];
	}

	m_layers.clear();
}


std::vector<Tileset>* Level::getTilesets() { return &m_tilesets; }


std::vector<Layer*>* Level::getLayers() { return &m_layers; }


std::vector<TileLayer*>* Level::getCollisionLayers() { return &m_collisionLayers; }

const std::vector<TileLayer*>& Level::getCollidableLayers()
{
	return m_collisionLayers;
}

Player* Level::getPlayer() { return m_pPlayer; }


void Level::setPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }