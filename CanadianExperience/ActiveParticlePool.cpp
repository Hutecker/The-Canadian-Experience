/**
 * \file ActiveParticlePool.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "ActiveParticlePool.h"

using namespace Gdiplus;
using namespace std;

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
	shared_ptr<CSnowflake> current = mRoot;
	while (current != nullptr)
	{
		if (current->GetBias() == 0)
		{
			current->Initialize();
			current->Draw(graphics);
		}
		else
		{
			current->UpdatePosition(graphics);
		}
		current = current->GetNextSnowflake();
	}
}

/**
* \brief sets the active pool for the givin snowflake
* \param snowflake the snowflake to set
*/
void CActiveParticlePool::SetActivePool(std::shared_ptr<CSnowflake> snowflake)
{
	snowflake->AddActivePool(this);
}