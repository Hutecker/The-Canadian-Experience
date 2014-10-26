/**
 * \file ActorFactory.h
 *
 * \author Stephan Hutecker
 *
 * \brief Abstract base class for actor factories.
 */

#pragma once

#include <memory>
#include "Actor.h"

/**
* \brief Abstract base class for actor factories.
*/
class CActorFactory
{
public:
	CActorFactory();
	virtual ~CActorFactory();
	virtual std::shared_ptr<CActor> Create() = 0;
};

