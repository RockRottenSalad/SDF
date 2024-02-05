
#ifndef MAT4_H
#define MAT4_H
#include "types.h"
#include<stdio.h>

#define MAT4_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}
#define MAT4_IDENTITY_INIT {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}}

void mat4_init(mat4_t* restrict mat);

void mat4_identity_init(mat4_t* restrict mat);

void mat4_copy(mat4_t mat1, mat4_t* restrict mat2);

void mat4_mult(mat4_t* restrict mat1, mat4_t mat2);

void mat4_translate_vec2(mat4_t* restrict mat, vec2_t vec);

void mat4_translate(mat4_t* restrict mat, vec3_t vec);

void mat4_scale(mat4_t* restrict mat, vec3_t vec);

void mat4_rotate(mat4_t* mat, vec3_t vec, float angle);

void mat4_mult_vec4(mat4_t mat, vec4_t* restrict vec);

void mat4_mult_vec3(mat4_t mat, vec3_t* restrict vec);

void mat4_perspective(mat4_t* restrict mat, float n_z, float f_z, float aspect);

void mat4_perspective_fov(mat4_t* restrict mat, float n_z, float f_z, float aspect, float fov);

void mat4_orthographic(mat4_t* restrict mat, float n_z, float f_z, float aspect);

void mat4_orthographic_fov(mat4_t* restrict mat, float n_z, float f_z, float aspect, float fov);

void mat4_lookat(mat4_t* restrict mat, vec3_t pos, vec3_t direction);

void mat4_print(mat4_t mat);

#endif
