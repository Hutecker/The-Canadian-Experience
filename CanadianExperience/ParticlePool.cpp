/**
 * \file ParticlePool.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "ParticlePool.h"
#include "SnowflakeController.h"

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