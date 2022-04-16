#pragma once
#include <string>
#include <SDL.h>
#include <map>

 class TextureManager {	

 private:
	 TextureManager() {}

	 static TextureManager* s_pInstance;

public:
	void clearFromTextureMap(std::string id);

	void drawTile(std::string id, int margin, int
		spacing, int x, int y, int width, int height, int currentRow,
		int currentFrame, SDL_Renderer* pRenderer);

	static TextureManager* Instance();

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, 
		int currentRow, int currentFrame, SDL_Renderer* pRenderer, 
		double angle, int alpha, SDL_RendererFlip flip = SDL_FLIP_NONE);
	

	void clearTextureMap();

	std::map<std::string, SDL_Texture*> getTextureMap() { return m_textureMap; }

	std::map<std::string, SDL_Texture*> m_textureMap;
 };


 typedef TextureManager TheTextureManager;