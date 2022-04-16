#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include "LoaderParams.h"



class PlatformerObject 
	: public GameObject
{
public:

	virtual ~PlatformerObject() {}// for polymorphism

	virtual void load(std::unique_ptr<LoaderParams> const
		& pParams);

	virtual void draw();
	virtual void update();

	virtual void clean(); // not implemented in this class
	virtual void collision() {}//not implemented in this class

	virtual std::string type() { return "SDLGameObject"; }

protected:
	// we won't directly create PlatformerObject's
	PlatformerObject();

	bool checkCollideTile(Vector2D newPos);

	// draw the animation for the object being destroyed
	void doDyingAnimation();

	// how fast will this object fire bullets? with a counter
	int m_bulletFiringSpeed;
	int m_bulletCounter;

	// how fast will this object move?
	int m_moveSpeed;

	// how long will the death animation takes? with a counter
	int m_dyingTime;
	int m_dyingCounter;

	// has the explosion sound played?
	bool m_bPlayedDeathSound;

	bool m_bFlipped;
	bool m_bMoveLeft;
	bool m_bMoveRight;
	bool m_bRunning;
	bool m_bFalling;
	bool m_bJumping;
	bool m_bCanJump;

	Vector2D m_lastSafePos;

	int m_jumpHeight;
};