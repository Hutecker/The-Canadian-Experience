/**
 * \file SnowflakeController.h
 *
 * \author Stephan Hutecker
 *
 * \brief Controls all of the snowflakes in our scene
 */

#pragma once

/** \brief Controls all of the snowflakes in our scene */
class CSnowflakeController
{
public:
	/** \brief Default constructor disabled */
	CSnowflakeController() = delete;
	/** \brief Copy constructor disabled */
	CSnowflakeController(const CSnowflakeController &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowflakeController &) = delete;
	virtual ~CSnowflakeController();
};

