#include "AnimatedGraphic.h"
#include <SDL.h>
#include <memory>




AnimatedGraphic::AnimatedGraphic() 
	: PlatformerObject()
{

}

void AnimatedGraphic::draw()
{
	PlatformerObject::draw();
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %
		2));
}

void AnimatedGraphic::clean()
{
}

void AnimatedGraphic::load(std::unique_ptr<LoaderParams> const &pParams)
{
	PlatformerObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}