/**
 * \file Snowflake.h
 *
 * \author Stephan Hutecker
 *
 * \brief Snowflake which will act as a node in the linked list
 */

#pragma once

#pragma warning (disable : 4244) // loss of precision warning

#include <memory>
#include <chrono>

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
	void UpdatePosition(Gdiplus::Graphics *graphics);
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

	/**
	* \brief gets this snowflakes active pool
	* \returns the snowflakes active pool
	*/
	CActiveParticlePool* GetActivePool() { return mActivePool; }

	/**
	* \brief gets this snowflakes particle pool
	* \returns the snowflakes particle pool
	*/
	CParticlePool* GetParticlePool() { return mParticlePool; }

	/**
	* \brief returns the bias
	* \returns the bias
	*/
	double GetBias(){ return mBias; }

	/**
	* \brief gets the snowflakes position
	* \returns the snowflakes postion
	*/
	Gdiplus::PointF GetPosition() { return mPosition; }

	void ResetSnowflake();

	void AddParticlePool(CParticlePool* particlePool);
	void AddActivePool(CActiveParticlePool* ActivePool);

private:
	/// the x and y location of our snowflake
	Gdiplus::PointF mPosition;
	/// the x and y velocity of our snowflake
	Gdiplus::PointF mVelocity;
	/// The time elapsed
	double mTimeElapsed = 0.0;
	/// The bias on the snowflake pushing it in one direction simulating wind
	double mBias = 0.0;
	/// pointer to the next snowflake in the list
	std::shared_ptr<CSnowflake> mNextSnowflake;
	/// pointer to its active pool
	CActiveParticlePool* mActivePool;
	/// pointer to its particle pool
	CParticlePool* mParticlePool;
	/// the last time we measured
	double mLastTime = 0.0;
};

