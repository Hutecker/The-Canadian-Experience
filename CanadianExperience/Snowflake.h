/**
 * \file Snowflake.h
 *
 * \author Stephan Hutecker
 *
 * \brief Snowflake which will act as a node in the linked list
 */

#pragma once

/** \brief Snowflake which will act as a node in the linked list */
class CSnowflake
{
public:
	/** \brief Default constructor disabled */
	CSnowflake() = delete;
	/** \brief Copy constructor disabled */
	CSnowflake(const CSnowflake &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowflake &) = delete;
	virtual ~CSnowflake();
};

