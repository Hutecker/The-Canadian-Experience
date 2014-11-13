/**
 * \file ActiveParticlePool.h
 *
 * \author Stephan Hutecker
 *
 * \brief The list of active particles (snowflakes)
 */

#pragma once

#include "LinkedList.h"

/** \brief The list of active particles (snowflakes) */
class CActiveParticlePool : public CLinkedList
{
public:
	/** \brief Default constructor disabled */
	CActiveParticlePool() = delete;
	/** \brief Copy constructor disabled */
	CActiveParticlePool(const CActiveParticlePool &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActiveParticlePool &) = delete;
	virtual ~CActiveParticlePool();
};
