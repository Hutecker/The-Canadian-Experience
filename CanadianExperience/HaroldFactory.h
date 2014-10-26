/**
 * \file HaroldFactory.h
 *
 * \author Stephan Hutecker
 *
 * \brief Factory class that builds the Harold character
 */

#pragma once

#include <memory>
#include "ActorFactory.h"
#include "Actor.h"

/**
* \brief Factory class that builds the Harold character
*/
class CHaroldFactory : public CActorFactory
{
public:
	CHaroldFactory();
	virtual ~CHaroldFactory();
	std::shared_ptr<CActor> Create();
};

