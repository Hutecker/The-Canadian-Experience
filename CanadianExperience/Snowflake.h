/**
 * \file Snowflake.h
 *
 * \author Stephan Hutecker
 *
 * \brief Snowflake which will act as a node in the linked list
 */

#pragma once

#include <memory>

class CParticlePool;
class CActiveParticlePool;

/** \brief Snowflake which will act as a node in the linked list */
class CSnowflake
{
public:
	CSnowflake();
	/** \brief Copy constructor disabled */
	CSnowflake(const CSnowflake &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowflake &) = delete;
	virtual ~CSnowflake();
	void UpdatePosition();
	void Initialize();
	void Draw(Gdiplus::Graphics *graphics);

	/**
	* \brief sets the next snowflake in the list
	* \param snowflake the next snowflake
	*/
	void SetNextSnowflake(std::shared_ptr<CSnowflake> snowflake){ mNextSnowflake = snowflake; }

	/**
	* \brief returns the next snowflake
	* \returns a pointer to the next snowflake
	*/
	std::shared_ptr<CSnowflake> GetNextSnowflake() { return mNextSnowflake; }

private:
	/// the x and y location of our snowflake
	Gdiplus::PointF mPosition;
	/// the x and y velocity of our snowflake
	Gdiplus::PointF mVelocity;
	/// The time elapsed
	double mTimeElapsed;
	/// The bias on the snowflake pushing it in one direction simulating wind
	double mBias;
	/// pointer to the next snowflake in the list
	std::shared_ptr<CSnowflake> mNextSnowflake;
	/// pointer to its active pool
	CActiveParticlePool* mActivePool;
	/// pointer to its particle pool
	CParticlePool* mParticlePool;
};

