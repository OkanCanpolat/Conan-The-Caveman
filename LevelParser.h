#pragma once

#include "Level.h"
#include "tinyxml.h"
#include "TileLayer.h"

class Level;
struct Tileset;
class Layer;
class TileLayer;

class LevelParser
{

public:
	Level* parseLevel(const char* levelFile);
private:

	void parseTextures(TiXmlElement* pTextureRoot);

	void parseObjectLayer(TiXmlElement* pObjectElement,
		std::vector<Layer*>* pLayers, Level* pLevel);

	void parseTilesets(TiXmlElement* pTilesetRoot,
		std::vector<Tileset>* pTilesets);

	void parseTileLayer(TiXmlElement* pTileElement,
		std::vector<Layer*>* pLayers, const std::vector<Tileset>*
		pTilesets, std::vector<TileLayer*>* pCollisionLayers);

	int m_tileSize;
	int m_width;
	int m_height;
};
