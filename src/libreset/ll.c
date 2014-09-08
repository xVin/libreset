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
#include "ll.h"

#include <stdlib.h>

void
ll_destroy(
    struct ll* ll
) {
    struct ll_element* iter = ll->head;
    struct ll_element* next;

    while (iter) {
        next = iter->next;
        free(iter);
        iter = next;
    }
}

struct ll*
ll_insert(
    struct ll* ll,
    struct ll_element* e
) {
    if (!ll || !e) {
        return NULL;
    }

    e->next = ll->head;
    ll->head = e;
    return ll;
}

struct ll*
ll_insert_data(
    struct ll* ll,
    void* data
) {
    struct ll_element* el = ll_element_alloc_new(data);
    return ll_insert(ll, el);
}

struct ll*
ll_delete(
    struct ll* ll,
    struct ll_element* del
) {
    struct ll_element* iter;
    struct ll_element* last;

    if (del == ll->head) {
        iter = ll->head;
        ll->head = ll->head->next;
        free(iter);
        return ll;
    }

    for (iter = ll->head; iter; iter = iter->next) {
        if (iter == del) {
            last->next = iter->next;
            free(iter);
            break;
        }

        last = iter;
    }

    return ll;
}

struct ll_element*
ll_element_alloc(void) {
    return calloc(1, sizeof(struct ll_element));
}

struct ll_element*
ll_element_alloc_new(
    void* data
) {
    struct ll_element* el = ll_element_alloc();
    if (el) {
        el->data = data;
    }
    return el;
}

void
ll_element_destroy(
    struct ll_element* el
) {
    free(el);
}

