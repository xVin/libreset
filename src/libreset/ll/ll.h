/*
 * libreset - Reentrent set library for fast set operations in C
 *
 * Copyright (C) 2014 Matthias Beyer
 * Copyright (C) 2014 Julian Ganz
 *
 * This file is part of libreset.
 *
 * libreset is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * libreset is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libreset. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @addtogroup internal_linkedlist_interface
 *
 * This group contains the interface definition for the linked list type used in
 * the codebase.
 *
 * @{
 */

#ifndef __LL_H__
#define __LL_H__

#include "util/attributes.h"
#include "libreset/set.h"

/**
 * Linked list element type
 *
 * The linked list is a single linked one, so we only hold a pointer to the next
 * element.
 */
struct ll_element {
    struct ll_element*  next; /**< Pointer to next element of linked list */
    void*               data; /**< Pointer to the data in this node */
};

/**
 * Linked list type
 *
 * This type is used as interface to the world.
 * It was introducted for hiding the head pointer of a linked list, so we can
 * modify this one with more ease.
 */
struct ll {
    struct ll_element* head; /**< Head of the linked list */
};

/**
 * Destroy a linked list object
 *
 * @memberof ll
 *
 * Removes the linked list from the memory but does not remove the referenced
 * elements.
 *
 * @warning the function may crash if either of the arguments is NULL
 */
void
ll_destroy(
    struct ll* ll, //!< Ptr to the struct ll object
    struct r_set_cfg const* cfg //!< type information proveded by the user
)
__nonnull__(1, 2)
;

/**
 * Insert a element from the actual void* which references the data
 *
 * @memberof ll
 *
 * @warning the function may crash when being passed NULL for either argument
 * @return 1 if the insertion was successful, 0 on failure
 */
int
ll_insert(
    struct ll* ll, /**< Ptr to the linked list object */
    void* data, /**< Ptr to the data to insert */
    struct r_set_cfg const* cfg //!< type information proveded by the user
)
__nonnull__(1, 2, 3)
;

/**
 * Find an element from the linked list by predicate
 *
 * @memberof ll
 *
 * @return pointer to the data element or NULL on failure
 */
void*
ll_find(
    struct ll* ll, //!< The linked list to search in
    void const* const d, //!< Data element to compare to
    struct r_set_cfg const* cfg //!< Type information provided by the user
)
__nonnull__(1, 2, 3)
;

/**
 * Delete an item from the list
 *
 * @memberof ll
 *
 * @return 1 if the deletion was successful, 0 on failure
 * @warning the function may crash if either of the arguments is NULL
 */
int
ll_delete(
    struct ll* ll, //! Ptr to the linked list object
    void const* del, //!< Comparable to object to be removed
    struct r_set_cfg const* cfg //!< type information proveded by the user
)
__nonnull__(1, 2, 3)
;

/**
 * Delete items from the list by predicate
 *
 * @memberof ll
 *
 * @return Number of deleted elements.
 */
unsigned int
ll_ndel(
    struct ll* ll, //!< Ptr to the linked list object
    r_predf pred, //!< Predicate for deleting elements
    void* etc, //!< User data for the predicate function
    struct r_set_cfg const* cfg //!< type information proveded by the user
)
__nonnull__(1, 4)
;

/**
 * Check whether a linked list is empty or not.
 *
 * @memberof ll
 *
 * @return 1 if the list is empy, 0 otherwise
 */
int
ll_is_empty(
    struct ll const* ll //!< Ptr to the linked list object
)
__nonnull__(1)
;

/**
 * Loop through an linked list
 *
 * Helper macro for looping through an linked list.
 * The first parameter should be the name of the iterator,
 * the second parameter is the linked list to iterate through.
 */
#define ll_foreach(it,ll) \
    for (struct ll_element* it = (ll)->head; it; it = it->next)

/**
 * @}
 */

#endif
