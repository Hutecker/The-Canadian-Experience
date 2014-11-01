/**
* \file HelgaFactory.h
*
* \author Stephan Hutecker
*
* \brief Factory class that builds the Helga character
*/

#pragma once

#include <memory>
#include "ActorFactory.h"
#include "Actor.h"

/**
* \brief Factory class that builds the Harold character
*/
class CHelgaFactory : public CActorFactory
{
public:
	CHelgaFactory();
	virtual ~CHelgaFactory();
	std::shared_ptr<CActor> Create();
};

