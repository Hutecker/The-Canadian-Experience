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
		auto current = mRoot;
		while (current->GetNextSnowflake() != nullptr)
		{
			current = current->GetNextSnowflake();
		}
		current->SetNextSnowflake(snowflake);
	}
	mAvailable++;
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
			break;
		}
		else if (current == snowflake && previous != nullptr)
		{
			previous->SetNextSnowflake(current->GetNextSnowflake());
			break;
		}
		previous = current;
		current = current->GetNextSnowflake();
	}
	mAvailable--;
}

/**
 * \brief adds the controller
 * \param controller the controller we're adding
 */
void CLinkedList::AddController(CSnowflakeController* controller)
{
	mController = controller;
}

