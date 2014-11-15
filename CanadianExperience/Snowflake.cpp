/**
 * \file Snowflake.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "Snowflake.h"
#include "ParticlePool.h"
#include "ActiveParticlePool.h"

using namespace std;
using namespace Gdiplus;
using namespace std::chrono;

/**
 * \brief constructor
 */
CSnowflake::CSnowflake()
{
}

/**
 * \brief desctructor
 */
CSnowflake::~CSnowflake()
{
}

/**
 * \brief updates the position of the snowflake
 */
void CSnowflake::UpdatePosition(Graphics *graphics)
{
	milliseconds ms = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch());
	long long x = ms.count();
	mTimeElapsed = (x/1000.0) - mLastTime;

	mPosition.X = mPosition.X + (mBias * mTimeElapsed);
	mPosition.Y = mPosition.Y + (mVelocity.Y * mTimeElapsed);
	Draw(graphics);
}

/**
 * \brief creates a random double
 * \param fMin minimum double we want
 * \param fMax maximum we want
 * \returns  random floating point
 */
double DoubleRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

/**
 * \brief initializes the snowflake
 */
 void CSnowflake::Initialize()
{
	 //random number between -200 and 820
	 double x = DoubleRand(-200, 820);
	 double y = -10;
	 //y velocity between 5 and 10
	 double yVelocity = DoubleRand(0, 2);
	 double xVelocity = 0;

	 mPosition.X = x;
	 mPosition.Y = y;
	 mVelocity.X = xVelocity;
	 mVelocity.Y = yVelocity;

	 mBias = .5;
}

/**
 * \brief resets the snowflakes values
 */
 void CSnowflake::ResetSnowflake()
 {
	 mPosition.X = 0;
	 mPosition.Y = 0;
	 mVelocity.X = 0;
	 mVelocity.Y = 0;
	 mTimeElapsed = 0;
	 mBias = 0;
	 mNextSnowflake = nullptr;
 }

/**
 * \brief draws the snowflake
 */
 void CSnowflake::Draw(Graphics *graphics)
{
	 if (mLastTime == 0)
	 {
		 milliseconds ms = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch());
		 long long x = ms.count();
		 mLastTime = x / 1000.0;
	 }

	 SolidBrush brush(Color::White);
	 graphics->FillEllipse(&brush, static_cast<int>(mPosition.X), static_cast<int>(mPosition.Y), 2, 2);
}

/**
 * \brief adds the reserve particle pools
 * \param particlePool the reserveed pool
 */
 void CSnowflake::AddParticlePool(CParticlePool* particlePool)
 {
	 mParticlePool = particlePool;
 }

/**
 * \brief adds the active particle pool
 * \param ActivePool the active pool
 */
 void CSnowflake::AddActivePool(CActiveParticlePool* ActivePool)
 {
	 mActivePool = ActivePool;
 }

