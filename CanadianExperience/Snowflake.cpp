/**
 * \file Snowflake.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "Snowflake.h"
#include "ParticlePool.h"
#include "ActiveParticlePool.h"

using namespace std;
using namespace Gdiplus;

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
void CSnowflake::UpdatePosition()
{

}

/**
 * \brief initializes the snowflake
 */
 void CSnowflake::Initialize()
{

}

/**
 * \brief draws the snowflake
 */
 void CSnowflake::Draw(Graphics *graphics)
{
	 SolidBrush brush(Color::White);
	 graphics->FillEllipse(&brush, 210, 210, 2, 2);
}