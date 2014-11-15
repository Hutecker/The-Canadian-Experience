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
	CSnowflakeController();
	/** \brief Copy constructor disabled */
	CSnowflakeController(const CSnowflakeController &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowflakeController &) = delete;
	virtual ~CSnowflakeController();
	int InitializeSnowflakeRate();
	void MoveToActive(int numberOfSnowflakes);
	void MoveToPool();
	void Draw(Gdiplus::Graphics *graphics);
	void InitializePool();

	/**
	* \brief sets the picture
	* \param picture the picture to set
	*/
	void SetPicture(CPicture* picture){ mPicture = picture; }

	void AddPool(std::shared_ptr<CParticlePool> pool);
	void AddActivePool(std::shared_ptr<CActiveParticlePool> pool);

	/**
	* \brief gets the active particle pool
	* \returns the active particle pool
	*/
	std::shared_ptr<CActiveParticlePool> GetActivePool() { return mActiveParticles; }

private:
	/// The picture we're drawing on
	CPicture *mPicture;
	/// our active particle pool
	std::shared_ptr<CActiveParticlePool> mActiveParticles;
	/// our reserved particles
	std::shared_ptr<CParticlePool> mParticlePool;
};

