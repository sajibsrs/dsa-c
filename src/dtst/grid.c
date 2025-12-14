#include "../helper.h"
#include "./dtst.h"
#include <math.h>
#include <stdio.h>

static inline point_t center(const grid_t *grid, int row, int col) {
    return (point_t){grid->origin.x + (col + 0.5f) * grid->cwidth, grid->origin.y + (row + 0.5f) * grid->cheight};
}

grid_t *grid_new(int rows, int cols, point_t origin, float cwidth, float cheight) {
    grid_t *grid = _malloc(sizeof(grid_t));
    grid->rows = rows;
    grid->cols = cols;
    grid->origin = origin;
    grid->cwidth = cwidth;
    grid->cheight = cheight;
    grid->data = _calloc(rows * cols, sizeof(char));

    return grid;
}

int grid_isvalid(const grid_t *grid, int row, int col) {
    return row >= 0 && row < grid->rows && col >= 0 && col < grid->cols;
}

int grid_set(grid_t *grid, int row, int col, char val) {
    if (!grid_isvalid(grid, row, col)) return 0;
    grid->data[row * grid->cols + col] = val;
    return 1;
}

char grid_get(const grid_t *grid, int row, int col) {
    if (!grid_isvalid(grid, row, col)) return 0;
    return grid->data[row * grid->cols + col];
}

int grid_find(const grid_t *grid, char targ) {
    int size = grid->rows * grid->cols;
    for (int i = 0; i < size; i++) {
        if (grid->data[i] == targ) return i;
    }
    return -1;
}

int grid_nearest(const grid_t *grid, point_t pt) {
    int best_idx = -1;
    float best_dsqr = INFINITY;

    int size = grid->rows * grid->cols;
    for (int i = 0; i < size; i++) {
        int row = i / grid->cols;
        int col = i % grid->cols;

        point_t ctr = center(grid, row, col);

        float dx = pt.x - ctr.x;
        float dy = pt.y - ctr.y;
        float dsqr = dx * dx + dy * dy;

        if (dsqr < best_dsqr) {
            best_idx = i;
            best_dsqr = dsqr;
        }
    }
    return best_idx;
}

int grid_nearexp(const grid_t *grid, point_t pt, int radius) {
    // Wold-space bound check
    float max_x = grid->origin.x + grid->cols * grid->cwidth;
    float max_y = grid->origin.y + grid->rows * grid->cheight;

    if (pt.x < grid->origin.x || pt.x >= max_x || pt.y < grid->origin.y || pt.y >= max_y) return -1;

    // Determine starting cell
    int start_col = (int)((pt.x - grid->origin.x) / grid->cwidth);
    int start_row = (int)((pt.y - grid->origin.y) / grid->cheight);

    int best_idx = -1;
    float best_dsqr = INFINITY;

    for (int rad = 0; rad <= radius; rad++) {
        for (int drow = -rad; drow <= rad; drow++) {
            for (int dcol = -rad; dcol <= rad; dcol++) {
                // Visit ring, not inner cells
                if (abs(drow) != rad && abs(dcol) != rad) continue;

                int row = start_row + drow;
                int col = start_col + dcol;

                if (!grid_isvalid(grid, row, col)) continue;

                point_t ctr = center(grid, row, col);
                float dx = pt.x - ctr.x;
                float dy = pt.y - ctr.y;
                float dsqr = dx * dx + dy * dy;

                if (dsqr < best_dsqr) {
                    best_dsqr = dsqr;
                    best_idx = row * grid->cols + col;
                }
            }
        }
    }
    return best_idx;
}

void grid_free(grid_t *grid) {
    if (!grid) return;
    _free(grid->data);
    _free(grid);
}

void grid_print(const grid_t *grid) {
    printf("\nGrid %dx%d:\n", grid->rows, grid->cols);
    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->cols; col++) {
            char val = grid_get(grid, row, col);
            printf("%3c", val ? val : '.'); // print '.' for empty
        }
        printf("\n");
    }
}
