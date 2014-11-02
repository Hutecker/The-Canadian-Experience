/**
 * \file AnimChannel.cpp
 *
 * \author Stephan Hutecker
 */


#include "stdafx.h"
#include "AnimChannel.h"

using namespace std;


/**
 * \brief constructor
 */
CAnimChannel::CAnimChannel()
{
}

/**
 * \brief destructor
 */
CAnimChannel::~CAnimChannel()
{
}

/**
 * \brief check for validity
 * \returns true if valid
 */
bool CAnimChannel::IsValid()
{
	return 1;
}

/**
 * \brief sets the frame
 * \param currFrame the frame were on
 */
void CAnimChannel::SetFrame(int currFrame)
{

}

/**
 * \brief inserts the keyframe
 * \param keyframe keyframe to insert
 */
void CAnimChannel::InsertKeyframe(shared_ptr<Keyframe> keyframe)
{

}

/**
 * \brief tweens between two keyframes
 * \param t frame tween to
 */
void CAnimChannel::Tween(double t)
{

}
