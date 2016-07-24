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

#include <buffer_size.h>

// Correct snprintf size for strings which may contain multi-byte utf-8 characters
// We must never replace a continuation byte with \0 when shortening a string
size_t unicode_buffer_size(const char * s, size_t n) {
	if(n == 0) return 0;
	
	do {
		n--; // Zero-index of last char (char to be replaced by \0)
	} while(
		n  // String will be just '\0' if width+1 is 1
		&& s[n]  // If last char is already '\0' 
		&& (s[n] & 0xc0) == 0x80  // UTF-8 continuation byte (cannot be replaced by \0)
	);
	
	// Last byte is not a utf-8 continuation byte, so it can be safely replaced by \0
	return n + 1;
}
