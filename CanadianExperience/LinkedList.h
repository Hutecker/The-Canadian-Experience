/**
 * \file LinkedList.h
 *
 * \author Stephan Hutecker
 *
 * \brief a simple singly linked list
 */

#pragma once

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
};

