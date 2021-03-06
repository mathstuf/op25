/* -*- c++ -*- */
/* 
 * Copyright 2018 Graham J. Norbury
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_LOG_TS_H
#define INCLUDED_LOG_TS_H

#include <sys/time.h>

class log_ts
{
private:
	struct timeval curr_time;
	double tstamp;
	char log_ts[30];

public:
	inline const char* get()
	{
		if (gettimeofday(&curr_time, 0) == 0)
		    sprintf(log_ts, "%010lu.%06lu", curr_time.tv_sec, curr_time.tv_usec);
		else
		    log_ts[0] = 0;

		return log_ts;
	}	

	inline const char* get(const int id)
	{
		if (gettimeofday(&curr_time, 0) == 0)
		    sprintf(log_ts, "%010lu.%06lu [%d]", curr_time.tv_sec, curr_time.tv_usec, id);
		else
		    sprintf(log_ts, "[%d]", id);

		return log_ts;
	}

	inline double get_ts()
	{
		if (gettimeofday(&curr_time, 0) == 0)
			tstamp = curr_time.tv_sec + (curr_time.tv_usec / 1e6);
		else
			tstamp = 0;

		return tstamp;
	}
};

#endif // INCLUDED_LOG_TS_H
