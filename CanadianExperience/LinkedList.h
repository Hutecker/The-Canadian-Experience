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

/** \brief a simple singly linked list */
class CLinkedList
{
public:
	/** \brief Default constructor disabled */
	CLinkedList() = delete;
	/** \brief Copy constructor disabled */
	CLinkedList(const CLinkedList &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CLinkedList &) = delete;
	virtual ~CLinkedList();
	void Add(CSnowflake snowflake);
	void Remove(CSnowflake snowflake);
	void Insert(CSnowflake snowflake);
	CSnowflake* Find(CSnowflake snowflake);

private:
	/// pointer to all of our snowflakes
	std::vector<std::shared_ptr<CSnowflake> > mSnowflakeVector;
};

