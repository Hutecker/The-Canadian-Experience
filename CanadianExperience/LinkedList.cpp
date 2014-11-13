/**
 * \file LinkedList.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "LinkedList.h"
#include "SnowflakeController.h"

using namespace std;

/**
 * \brief constructor
 * \param snowflake snowflake that will be our root
 */
CLinkedList::CLinkedList(std::shared_ptr<CSnowflake> snowflake)
{
	mRoot = snowflake;
}

/**
* \brief constructor
*/
CLinkedList::CLinkedList()
{
}

/**
 * \brief destructor
 */
CLinkedList::~CLinkedList()
{
}

/**
 * \brief adds a snowflake to the list
 * \param snowflake the snowflake to add
 */
void CLinkedList::Add(std::shared_ptr<CSnowflake> snowflake)
{
	// if no root exists
	if (mRoot == nullptr)
	{
		mRoot = snowflake;
	}
	else
	{
		snowflake->SetNextSnowflake(mRoot);
		mRoot = snowflake;
	}
}

/**
 * \brief removes a snowflake from our list
 * \param snowflake the snowflake to remove
 */
void CLinkedList::Remove(shared_ptr<CSnowflake> snowflake)
{
	shared_ptr<CSnowflake> previous = nullptr;
	shared_ptr<CSnowflake> current = mRoot;
	while (current != nullptr)
	{
		// removing root snowflake
		if (current == snowflake && previous == nullptr)
		{
			mRoot = snowflake->GetNextSnowflake();
		}
		else if (current == snowflake && previous != nullptr)
		{
			previous->SetNextSnowflake(current->GetNextSnowflake());
		}
		current = current->GetNextSnowflake();
	}
}

/**
 * \brief adds the controller
 * \param controller the controller we're adding
 */
void CLinkedList::AddController(CSnowflakeController* controller)
{
	mController = controller;
}