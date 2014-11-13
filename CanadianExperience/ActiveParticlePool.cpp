/**
 * \file ActiveParticlePool.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "ActiveParticlePool.h"

using namespace Gdiplus;


/**
* \brief constructor
*/
CActiveParticlePool::CActiveParticlePool()
{
}

/**
 * \brief desctructor
 */
CActiveParticlePool::~CActiveParticlePool()
{
}

/**
 * \brief draws the active snowflakes
 */
void CActiveParticlePool::Draw(Graphics *graphics)
{
	std::shared_ptr<CSnowflake> current = mRoot;
	while (current != nullptr)
	{
		current->Draw(graphics);
		current = current->GetNextSnowflake();
	}
}

/**
 * \brief updates the active snowflakes
 */
void CActiveParticlePool::UpdateSnowflakes()
{

}