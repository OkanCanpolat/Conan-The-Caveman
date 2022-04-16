#include "Camera.h"
#include "Game.h"

Camera* Camera::s_pCamera = new Camera();


Camera::Camera() : m_pTarget(0), m_position(0, 0)
{

}


Camera::~Camera()
{
	delete m_pTarget;
}

const Vector2D Camera::getPosition() const
{
		if (m_pTarget != 0)
		{
			//because of this code our character will always be in the middle of the screen
			Vector2D pos(m_pTarget->m_x - (TheGame::Instance()
				->getGameWidth() / 2), m_pTarget->m_y - (TheGame::Instance()
					->getGameHeight() / 2 )/*0*/);

			if (pos.m_x > TheGame::Instance()->getMapWidth() - 
				TheGame::Instance()->getGameWidth()) 
			{

				pos.m_x = TheGame::Instance()->getMapWidth() - 
					TheGame::Instance()->getGameWidth();
			}


			if (pos.m_y > TheGame::Instance()->getMapHeight() -
				TheGame::Instance()->getGameHeight())
			{
				pos.m_y= TheGame::Instance()->getMapHeight() -
					TheGame::Instance()->getGameHeight();

			}

			if (pos.m_x < 0)
			{
				pos.m_x = 0;
			}
			if (pos.m_y < 0)
			{
				pos.m_y = 0;
			}
			return pos;
		}

	return m_position;
}


void Camera::update(Vector2D velocity)
{
	m_position += velocity;

	if (m_position.m_x < 0)
	{
		m_position.m_x = 0;
	}
}

