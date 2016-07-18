# pebble_unicode_sizeof

Functions for using Unicode characters with Pebble

## Functions

```C
static size_t unicode_buffer_size(const char * s, size_t width);
```

Corrects the snprintf buffer size for strings which may contain Unicode.
Prevents partial copying of a multi-byte character by altering the buffer size parameter.
For example, with `AppMessage` dictionary `{"x": "жh林i"}` character ж is 2 bytes wide and 林 is 3 bytes wide.

```C
char dest[100];
snprintf(dest, 1, "%s", x->value->cstring); // \0
snprintf(dest, 2, "%s", x->value->cstring); // ERROR
snprintf(dest, 3, "%s", x->value->cstring); // ж\0
snprintf(dest, 4, "%s", x->value->cstring); // жh\0
snprintf(dest, 5, "%s", x->value->cstring); // ERROR
snprintf(dest, 6, "%s", x->value->cstring); // ERROR
snprintf(dest, 7, "%s", x->value->cstring); // жh林\0
snprintf(dest, 8, "%s", x->value->cstring); // жh林i\0
```
this crash can be avoided with:

```C
char dest[5];
size_t buffer_size = unicode_buffer_size(x->value->cstring, sizeof(dest)); // 4
snprintf(dest, buffer_size, "%s", x->value->cstring); // жh\0
```

## Usage

```C
#include <pebble_unicode/buffer_size.h>
```