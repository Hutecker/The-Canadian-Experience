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
	/**
	* \brief will create our actors
	* \returns a actor pointer
	*/
	virtual std::shared_ptr<CActor> Create() = 0;
};

