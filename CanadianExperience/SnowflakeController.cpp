/**
 * \file SnowflakeController.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "SnowflakeController.h"
#include "Snowflake.h"
#include "Picture.h"

using namespace std;
using namespace Gdiplus;

/**
* \brief constructor
*/
CSnowflakeController::CSnowflakeController()
{
	auto flake = make_shared<CSnowflake>();
	auto pool = make_shared<CParticlePool>(flake);
	auto activePool = make_shared<CActiveParticlePool>();
	this->AddPool(pool);
	this->AddActivePool(activePool);
	mActiveParticles->AddController(this);
	mParticlePool->AddController(this);
	InitializePool();

	srand(time(NULL));
}

/**
 * \brief destructor
 */
CSnowflakeController::~CSnowflakeController()
{
}

/**
 * \brief initializes the rate that our snowflakes are created
 * \returns the random number generated
 */
int CSnowflakeController::InitializeSnowflakeRate()
{
	//random number between 10 and 19
	int rate = rand() % 15 + 5;
	return rate;
}

/**
 * \brief moves a snowflake to the active pool
 * \param numberOfSnowflakes the number of snowflakes to move
 */
void CSnowflakeController::MoveToActive(int numberOfSnowflakes)
{
	mParticlePool->Pop(numberOfSnowflakes);
}

/**
 * \brief moves a snowflake to the particle pool
 * \param snowflake snowflake to move
 */
void CSnowflakeController::MoveToPool()
{
	shared_ptr<CSnowflake> current = mActiveParticles->GetRoot();
	shared_ptr<CSnowflake> newCurrent;
	while (current != nullptr)
	{
		PointF location = current->GetPosition();
		// if below screen remove
		if (location.Y > 610)
		{
			newCurrent = current->GetNextSnowflake();
			mActiveParticles->Remove(current);
			current->ResetSnowflake();
			mParticlePool->Add(current);
			current = newCurrent;
		}
		else
		{
			current = current->GetNextSnowflake();
		}
	}
}

/**
 * \brief draws our snowflakes
 */
void CSnowflakeController::Draw(Graphics *graphics)
{
	int rate = InitializeSnowflakeRate();
	MoveToActive(rate);
	mActiveParticles->Draw(graphics);
	MoveToPool();
}

/**
 * \brief initializes our particle pool
 */
void CSnowflakeController::InitializePool()
{
	mParticlePool->Initialize();
}

/**
 * \brief adds the particle pools
 * \param pool the pool to add
 */
void CSnowflakeController::AddPool(std::shared_ptr<CParticlePool> pool)
{
	mParticlePool = pool;
	pool->AddController(this);
}

/**
* \brief adds the active particle pool
* \param pool the pool to add
*/
void CSnowflakeController::AddActivePool(std::shared_ptr<CActiveParticlePool> pool)
{
	mActiveParticles = pool;
	pool->AddController(this);
}
