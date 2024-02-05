
#ifndef VEC2_H
#define VEC2_H

#include "types.h"

#define VEC2_INIT {0.0f, 0.0f}

void vec2_init(vec2_t* restrict vec);

void vec2_copy(vec2_t vec1, vec2_t* restrict vec2);

void vec2_add(vec2_t* restrict vec, vec2_t arg);

void vec2_add_to(vec2_t vec, vec2_t arg, vec2_t* restrict dest);

void vec2_sub(vec2_t* restrict vec, vec2_t arg);

void vec2_sub_to(vec2_t vec, vec2_t arg, vec2_t* restrict dest);

void vec2_div(vec2_t* restrict vec, float divby);

void vec2_div_to(vec2_t vec, float divby, vec2_t* restrict dest);

void vec2_scale(vec2_t* vec, float scale);

void vec2_scale_to(vec2_t vec, float scale, vec2_t* restrict dest);

// 2D cross product is a scalar
float vec2_cross(vec2_t* restrict vec1, vec2_t vec2);

float vec2_length(vec2_t vec);

float vec2_dot(vec2_t vec1, vec2_t vec2);

void vec2_normalize(vec2_t* restrict vec);

void vec2_normalize_to(vec2_t vec, vec2_t* restrict dest);

void vec2_print(vec2_t vec);

#endif
