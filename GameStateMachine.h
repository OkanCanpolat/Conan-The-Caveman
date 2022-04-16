#pragma once
#include "GameState.h"
#include <vector>
class GameStateMachine
{
public:

    GameStateMachine() {}
    ~GameStateMachine() {}

    void update();
    void render();

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();

    void clean();

    std::vector<GameState*>& getGameStates() { return m_gameStates; }

private:
	std::vector<GameState*> m_gameStates;

};