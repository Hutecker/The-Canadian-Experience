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
	/** \brief Default constructor disabled */
	CParticlePool() = delete;
	/** \brief Copy constructor disabled */
	CParticlePool(const CParticlePool &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CParticlePool &) = delete;
	virtual ~CParticlePool();
};

