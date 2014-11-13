/**
 * \file ParticlePool.h
 *
 * \author Stephan Hutecker
 *
 * \brief reserved particle pool
 */

#pragma once

#include "LinkedList.h"

/** \brief reserved particle pool */
class CParticlePool : public CLinkedList
{
public:
	CParticlePool(std::shared_ptr<CSnowflake> snowflake);
	/** \brief default constructor disabled */
	CParticlePool() = delete;
	/** \brief Copy constructor disabled */
	CParticlePool(const CParticlePool &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CParticlePool &) = delete;
	virtual ~CParticlePool();
	CSnowflake* Pop();
	void Initialize();
	/**
	* \brief gets the available particles
	* \returns the available particles
	*/
	int GetAvailable() { return mAvailable; }

private:
	/// available particles
	int mAvailable = 1;
};

