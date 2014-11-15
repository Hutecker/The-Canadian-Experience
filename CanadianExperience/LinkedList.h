/**
 * \file LinkedList.h
 *
 * \author Stephan Hutecker
 *
 * \brief a simple singly linked list
 */

#pragma once

#include <vector>
#include <memory>
#include "Snowflake.h"

class CSnowflakeController;

/** \brief a simple singly linked list */
class CLinkedList
{
public:
	CLinkedList(std::shared_ptr<CSnowflake> snowflake);
	/** \brief Default constructor disabled */
	CLinkedList();
	/** \brief Copy constructor disabled */
	CLinkedList(const CLinkedList &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CLinkedList &) = delete;
	virtual ~CLinkedList();
	void Add(std::shared_ptr<CSnowflake> snowflake);
	void Remove(std::shared_ptr<CSnowflake> snowflake);
	void AddController(CSnowflakeController* controller);

	/**
	* \brief get the root node
	* \returns the root node
	*/
	std::shared_ptr<CSnowflake> GetRoot() { return mRoot; }

protected:
	/// First element in our list
	std::shared_ptr<CSnowflake> mRoot;
	/// Pointer to the snowflake controller
	CSnowflakeController* mController;
	/// available particles
	int mAvailable = -1;
};

