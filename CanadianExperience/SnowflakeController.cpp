/**
 * \file SnowflakeController.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
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
}

/**
 * \brief destructor
 */
CSnowflakeController::~CSnowflakeController()
{
}

/**
 * \brief initializes the rate that our snowflakes are created
 */
void CSnowflakeController::InitializeSnowflakeRate()
{

}

/**
 * \brief updates all of our snowflakes
 */
void CSnowflakeController::UpdateSnowflakes()
{

}

/**
 * \brief moves a snowflake to the active pool
 * \param snowflake the snowflake to move
 */
void CSnowflakeController::MoveToActive(CSnowflake snowflake)
{

}

/**
 * \brief moves a snowflake to the particle pool
 * \param snowflake snowflake to move
 */
void CSnowflakeController::MoveToPool(CSnowflake snowflake)
{

}

/**
 * \brief creates our wind bias
 */
void CSnowflakeController::CreateBias()
{

}

/**
 * \brief sets the wind bias in our snowflakes
 */
void CSnowflakeController::SetBias()
{

}

/**
 * \brief draws our snowflakes
 */
void CSnowflakeController::Draw(Graphics *graphics)
{
	mActiveParticles->Draw(graphics);
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

