/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef CONTAINER_OF_H
#define CONTAINER_OF_H

#ifndef container_of
#define container_of(ptr, type, member)                                        \
	(type *)((char *)(ptr) - offsetof(type, member))
#endif

#endif
