#include "ll/ll.h"

int
ll_equal(
    struct ll const* lla,
    struct ll const* llb
) {
    if (lla == llb) {
        return 1;
    }

    if ((lla == NULL && llb != NULL) || (lla != NULL && llb == NULL)) {
        return 1;
    }

    int res = 1;

    ll_foreach(it_a, lla) {
        ll_foreach(it_b, llb) {
            if (it_a != it_b) {
                res = 0;
                break;
            }
        }
    }

    return res;
}
