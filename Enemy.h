#pragma once

#include "PlatformerObject.h"
#include "GameObjectFactory.h"

class Enemy 
	: public PlatformerObject
{
public:

	virtual std::string type() { return"Enemy"; }

protected:

	int m_health;

	Enemy() : PlatformerObject() {}

	virtual ~Enemy() {} // for polymorphism
};


