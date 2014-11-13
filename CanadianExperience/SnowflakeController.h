/**
 * \file SnowflakeController.h
 *
 * \author Stephan Hutecker
 *
 * \brief Controls all of the snowflakes in our scene
 */

#pragma once

#include <memory>
#include "ActiveParticlePool.h"
#include "ParticlePool.h"

class CPicture;

/** \brief Controls all of the snowflakes in our scene */
class CSnowflakeController
{
public:
	/** \brief Default constructor disabled */
	CSnowflakeController() = delete;
	/** \brief Copy constructor disabled */
	CSnowflakeController(const CSnowflakeController &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowflakeController &) = delete;
	virtual ~CSnowflakeController();
	void InitializeSnowflakeRate();
	void UpdateSnowflakes();
	void MoveToActive(CSnowflake snowflake);
	void MoveToPool(CSnowflake snowflake);
	void CreateBias();
	void SetBias();
	void Draw();

private:
	/// the bias on the snowflake (wind)
	double mBias;
	/// The picture we're drawing on
	CPicture *mPicture;
	/// our active particle pool
	std::shared_ptr<CActiveParticlePool> mActiveParticles;
	/// our reserved particles
	std::shared_ptr<CParticlePool> mParticlePool;
};

