#pragma once
#include <pebble.h>

/*
    pebble-unicode provides functions for handling Unicode on Pebble
    Copyright (C) 2016 Ben Caller

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
	Correct snprintf size for strings which may contain unicode.
	Avoids splitting a multi-byte utf-8 character.
	Usage:
	snprintf(dest,
		unicode_buffer_size(t_name->value->cstring, sizeof(dest)),
		PRINT_FORMAT, t_name->value->cstring);
*/
size_t unicode_buffer_size(const char * s, size_t n);