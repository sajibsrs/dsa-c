#include "../helper.h"
#include "dtst.h"
#include <stdio.h>

int rect_haspoint(rect_t rect, point_t pt) {
    return (pt.x >= rect.x && pt.x < rect.x + rect.w && pt.y >= rect.y && pt.y < rect.y + rect.h);
}

int rect_intersects(rect_t a, rect_t b) {
    return (b.x < a.x + a.w && b.x + b.w > a.x && b.y < a.y + a.h && b.y + b.h > a.y);
}

static float distsqr(point_t a, point_t b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;

    return dx * dx + dy * dy;
}

static float rect_distsqr(rect_t r, point_t p) {
    float dx = 0.0f, dy = 0.0f;

    if (p.x < r.x) dx = r.x - p.x;
    else if (p.x > r.x + r.w) dx = p.x - (r.x + r.w);

    if (p.y < r.y) dy = r.y - p.y;
    else if (p.y > r.y + r.h) dy = p.y - (r.y + r.h);

    return dx * dx + dy * dy;
}

qtreen_t *qtree_create(rect_t bounds, int capacity) {
    qtreen_t *qt = _malloc(sizeof(qtreen_t));
    qt->bounds = bounds;
    qt->capacity = capacity;
    qt->count = 0;
    qt->points = _malloc(sizeof(point_t) * capacity);

    qt->leaf = 1;
    qt->nw = qt->ne = qt->sw = qt->se = NULL;

    return qt;
}

int qtree_insert(qtreen_t *qt, point_t pt) {
    if (!rect_haspoint(qt->bounds, pt)) return 0;

    if (qt->leaf) {
        if (qt->count < qt->capacity) {
            qt->points[qt->count++] = pt;
            return 1;
        }

        qtree_subdiv(qt);
    }
    // route to exactly one child
    return qtree_insert(qt->nw, pt) || qtree_insert(qt->ne, pt) || qtree_insert(qt->sw, pt) || qtree_insert(qt->se, pt);
}

void qtree_subdiv(qtreen_t *qt) {
    if (!qt || !qt->leaf) return;

    float x = qt->bounds.x;
    float y = qt->bounds.y;
    float hw = qt->bounds.w / 2.0f;
    float hh = qt->bounds.h / 2.0f;

    int cap = qt->capacity;

    qt->nw = qtree_create((rect_t){x, y, hw, hh}, cap);
    qt->ne = qtree_create((rect_t){x + hw, y, hw, hh}, cap);
    qt->sw = qtree_create((rect_t){x, y + hh, hw, hh}, cap);
    qt->se = qtree_create((rect_t){x + hw, y + hh, hw, hh}, cap);

    qt->leaf = 0;

    // push points down
    for (int i = 0; i < qt->count; i++) {
        point_t pt = qt->points[i];
        qtree_insert(qt->nw, pt) || qtree_insert(qt->ne, pt) || qtree_insert(qt->sw, pt) || qtree_insert(qt->se, pt);
    }
    qt->count = 0;
}

int qtree_query(qtreen_t *qt, rect_t range, point_t *out, int omax, int *ocount) {
    if (!qt || !rect_intersects(qt->bounds, range)) return 0;

    if (qt->leaf) {
        for (int i = 0; i < qt->count; i++) {
            if (rect_haspoint(range, qt->points[i])) {
                if (*ocount == omax) return 1;
                out[((*ocount)++)] = qt->points[i];
            }
        }
        return 1; // shouldn't we return 0 here?
    }
    qtree_query(qt->nw, range, out, omax, ocount);
    qtree_query(qt->ne, range, out, omax, ocount);
    qtree_query(qt->sw, range, out, omax, ocount);
    qtree_query(qt->se, range, out, omax, ocount);

    return 1;
}

int qtree_nearest(qtreen_t *qt, point_t query, point_t *best, float *best_dsqr) {
    if (!qt) return 0;
    if (rect_distsqr(qt->bounds, query) >= *best_dsqr) return 0;

    int found = 0;

    if (qt->leaf) {
        for (int i = 0; i < qt->count; i++) {
            float dsqr = distsqr(qt->points[i], query);
            if (dsqr < *best_dsqr) {
                *best_dsqr = dsqr;
                *best = qt->points[i];
                found = 1;
            }
        }
        return found;
    }
    found |= qtree_nearest(qt->nw, query, best, best_dsqr);
    found |= qtree_nearest(qt->ne, query, best, best_dsqr);
    found |= qtree_nearest(qt->sw, query, best, best_dsqr);
    found |= qtree_nearest(qt->se, query, best, best_dsqr);

    return found;
}

void qtree_free(qtreen_t *qt) {
    if (!qt) return;

    if (qt->leaf) {
        qtree_free((qt->nw));
        qtree_free((qt->ne));
        qtree_free((qt->sw));
        qtree_free((qt->se));
    }
    _free(qt->points);
    _free(qt);
}

void qtree_draw(qtreen_t *qt, int depth, const char *label) {
    if (!qt) return;

    for (int i = 0; i < depth; i++) printf("  "); // indent
    if (label) printf("%s: ", label);
    printf("[%g,%g %gx%g] leaf=%d", qt->bounds.x, qt->bounds.y, qt->bounds.w, qt->bounds.h, qt->leaf);

    if (qt->leaf) {
        printf(" pts:");
        if (qt->count == 0) printf("(0)");
        for (int i = 0; i < qt->count; i++) printf("(%g,%g)", qt->points[i].x, qt->points[i].y);
    }
    printf("\n");

    if (!qt->leaf) {
        qtree_draw(qt->nw, depth + 1, "NW");
        qtree_draw(qt->ne, depth + 1, "NE");
        qtree_draw(qt->sw, depth + 1, "SW");
        qtree_draw(qt->se, depth + 1, "SE");
    }
}
