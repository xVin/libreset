#include "avl/avl.h"

/**
 * Check if two subtrees are equal
 *
 */
static int
subtree_equal(
    struct avl_el* roota,
    struct avl_el* rootb
) {

}

int
avl_equal(
    struct avl const* avla,
    struct avl const* avlb,
) {
    if (avla == avlb ||
        (avla == NULL && avlb != NULL) || (avla != NULL && avlb == NULL)) {
        return 0;
    }

    return subtree_equal(avla->root, avlb->root);
}
