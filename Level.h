#pragma once

#include <iostream>
#include <vector>
#include "Layer.h"
#include "LevelParser.h"
#include "Player.h"
#include "CollisionManager.h"


class Tilelayer;

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};

class Level
{
public:
	~Level();
	void update();
	void render();

	std::vector<Tileset>* getTilesets();

	std::vector<Layer*>* getLayers();

	std::vector<TileLayer*>* getCollisionLayers();

	const std::vector<TileLayer*>& getCollidableLayers();
	
	Player* getPlayer();

	void setPlayer(Player* pPlayer);

private:

	Player* m_pPlayer;

	Level();

	friend class LevelParser;

	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	std::vector<TileLayer*> m_collisionLayers;
};
