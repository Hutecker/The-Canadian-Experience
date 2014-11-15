/**
 * \file ParticlePool.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include <memory>
#include "ParticlePool.h"
#include "ActiveParticlePool.h"
#include "SnowflakeController.h"

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
 * \param numberOfSnowflakes the amount of snowflakes to pop
 */
void CParticlePool::Pop(int numberOfSnowflakes)
{
	shared_ptr<CSnowflake> current = mRoot;
	for (int i = 0; i < numberOfSnowflakes; i++)
	{
		//CActiveParticlePool* x = current->GetActivePool();
		//x->Add(current);
		//mRoot = current->GetNextSnowflake();
		//this->Remove(current);
		//current = current->GetNextSnowflake();

		shared_ptr<CActiveParticlePool>activePool = mController->GetActivePool();
		shared_ptr<CSnowflake> tempRoot = current->GetNextSnowflake();
		current->SetNextSnowflake(nullptr);
		activePool->Add(current);		
		this->Remove(current);
		mRoot = tempRoot;
		current = mRoot;
	}
}


/**
 * \brief creates the snowflakes for our pool
 */
void CParticlePool::Initialize()
{
	
	for (int i = 0; i <= 2000; i++)
	{
		auto snow = make_shared<CSnowflake>();
		snow->AddParticlePool(this); 
		shared_ptr<CActiveParticlePool> active = mController->GetActivePool();
		active->SetActivePool(snow);
		this->Add(snow);
	}
}