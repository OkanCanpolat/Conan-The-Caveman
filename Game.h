#pragma once
#include "SDL.h"
#include "GameObject.h"
#include <vector>
#include "GameStateMachine.h"

 class Game {
private:
    bool m_bChangingState;

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    GameStateMachine* m_pGameStateMachine;

    bool m_bRunning;

    static Game* s_pInstance;

    int m_gameWidth;
    int m_gameHeight;
    int m_mapWidth;
    int m_mapHeight;
    float m_scrollSpeed;

    int m_playerLives;

    int m_currentLevel;
    int m_nextLevel;
    bool m_bLevelComplete;

    std::vector<std::string> m_levelFiles;

    Game();
    ~Game();

    Game(const Game&);
    Game& operator=(const Game&);

public:
    static Game* Instance();
    
    bool init(const char* title, int xpos, int ypos, int width, int height, int fullscreen);

    void render();
    void update();
    void handleEvents();
    void clean();

    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    SDL_Window* getWindow() const { return m_pWindow; }
    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

    void setPlayerLives(int lives) { m_playerLives = lives; }
    int getPlayerLives() { return m_playerLives; }

    void setCurrentLevel(int currentLevel);
    const int getCurrentLevel() { return m_currentLevel; }

    void setNextLevel(int nextLevel) { m_nextLevel = nextLevel; }
    const int getNextLevel() { return m_nextLevel; }

    void setLevelComplete(bool levelComplete) { m_bLevelComplete = levelComplete; }
    const bool getLevelComplete() { return m_bLevelComplete; }

    bool running() { return m_bRunning; }

    void quit() { m_bRunning = false; }

    int getGameWidth() const { return m_gameWidth; }
    int getGameHeight() const { return m_gameHeight; }

    //map sizes
    void setMapWidth(int mapwidth)  { m_mapWidth = mapwidth; }
    int  getMapWidth() const { return m_mapWidth; }
    void setMapHeight(int mapheight) { m_mapHeight = mapheight; }
    int getMapHeight() const { return m_mapHeight; }

    float getScrollSpeed() { return m_scrollSpeed; }

    bool changingState() { return m_bChangingState; }
    void changingState(bool cs) { m_bChangingState = cs; }

    std::vector<std::string> getLevelFiles() { return m_levelFiles; }
};

 typedef Game TheGame;