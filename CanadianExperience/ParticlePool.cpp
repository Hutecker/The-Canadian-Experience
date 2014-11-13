/**
 * \file ParticlePool.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include <memory>
#include "ParticlePool.h"

using namespace std;

/**
 * \brief constructor
 * \param snowflake the snowflake that will be the root
 */
CParticlePool::CParticlePool(std::shared_ptr<CSnowflake> snowflake) : CLinkedList(snowflake)
{
}

/**
 * \brief destructor
 */
CParticlePool::~CParticlePool()
{
}

/**
 * \brief moves a particle from this pool to the active pool
 * \returns the snowflake we popped off
 */
CSnowflake* CParticlePool::Pop()
{
	CSnowflake flake;
	return &flake;
}


/**
 * \brief creates the snowflaxes for our pool
 */
void CParticlePool::Initialize()
{
	for (int i = 0; i <= 1000; i++)
	{
		auto snow = make_shared<CSnowflake>();
		this->Add(snow);
		mAvailable++;
	}
}