/**
 * \file ActiveParticlePool.h
 *
 * \author Stephan Hutecker
 *
 * \brief The list of active particles (snowflakes)
 */

#pragma once

#include "LinkedList.h"

class CSnowflakeController;

/** \brief The list of active particles (snowflakes) */
class CActiveParticlePool : public CLinkedList
{
public:
	/** \brief Default constructor disabled */
	CActiveParticlePool();
	/** \brief Copy constructor disabled */
	CActiveParticlePool(const CActiveParticlePool &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActiveParticlePool &) = delete;
	virtual ~CActiveParticlePool();
	void Draw(Gdiplus::Graphics *graphics);
	void UpdateSnowflakes();
};

