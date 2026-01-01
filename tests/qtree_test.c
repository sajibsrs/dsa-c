#include "../src/dtst/dtst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ---------- CREATE QUADTREE ----------
    rect_t world = {0, 0, 100, 100};
    int capacity = 3;

    qtreen_t *qt = qtree_create(world, capacity);
    printf("✓ Quadtree created\n");

    assert(qt != NULL);
    assert(qt->count == 0);
    assert(qt->leaf);

    // ---------- INSERT INITIAL POINTS ----------
    point_t pts[9] = {
        {10, 10},
        {20, 20},
        {30, 30}, // cluster 1
        {60, 10},
        {70, 20}, // cluster 2
        {10, 70},
        {20, 80}, // cluster 3
        {80, 80},
        {90, 90}  // cluster 4
    };

    for (int i = 0; i < 3; i++) {
        assert(qtree_insert(qt, pts[i]));
    }

    printf("✓ Points inserted without subdivision\n");

    assert(qt->count == 3);
    assert(qt->leaf);

    // ---------- INSERT MORE POINTS (FORCE SUBDIVISION) ----------
    for (int i = 3; i < 9; i++) {
        assert(qtree_insert(qt, pts[i]));
    }

    printf("✓ Additional points inserted (subdivision expected)\n");

    assert(!qt->leaf);    // root subdivided
    assert(qt->count == 0); // parent cleared

    // ---------- VERIFY CHILD NODES EXIST ----------
    assert(qt->nw && qt->ne && qt->sw && qt->se);
    printf("✓ Child quadrants created\n");

    // ---------- DRAW QUADTREE IN SPACE ----------
    qtree_draw(qt, 0, "root");

    // ---------- QUERY FULL SPACE ----------
    rect_t full = {0, 0, 100, 100};
    point_t out[16];
    int out_count = 0;

    qtree_query(qt, full, out, 16, &out_count);
    printf("✓ Full-space query executed\n");
    assert(out_count == 9);

    // ---------- QUERY TOP-LEFT QUADRANT ----------
    rect_t nw_range = {0, 0, 50, 50};
    out_count = 0;

    qtree_query(qt, nw_range, out, 16, &out_count);
    printf("✓ NW quadrant query executed\n");
    assert(out_count == 3); // (10,10), (20,20), (30,30)

    // ---------- QUERY BOTTOM-RIGHT QUADRANT ----------
    rect_t se_range = {50, 50, 50, 50};
    out_count = 0;

    qtree_query(qt, se_range, out, 16, &out_count);
    printf("✓ SE quadrant query executed\n");
    assert(out_count == 2); // (80,80), (90,90)

    // ---------- QUERY EMPTY REGION ----------
    rect_t empty = {45, 45, 5, 5};
    out_count = 0;

    qtree_query(qt, empty, out, 16, &out_count);
    printf("✓ Empty-region query passed\n");
    assert(out_count == 0);

    // ---------- INSERT OUT-OF-BOUNDS POINT ----------
    point_t outside = {150, 150};
    assert(!qtree_insert(qt, outside));
    printf("✓ Out-of-bounds insert rejected\n");

    // ---------- CLEANUP ----------
    qtree_free(qt);
    printf("✓ Quadtree freed successfully\n");

    printf("\nAll quadtree tests passed! 🎉\n");
    return 0;
}
