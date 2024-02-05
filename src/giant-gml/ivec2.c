
#include "giant-gml/ivec2.h"

inline
void ivec2_init(ivec2_t* restrict vec)
{
    (*vec)[X] = 0;
    (*vec)[Y] = 0;
}

inline
void ivec2_copy(ivec2_t vec1, ivec2_t* restrict ivec2)
{
    (*ivec2)[X] = vec1[X];
    (*ivec2)[Y] = vec1[Y];
}

inline
void ivec2_add(ivec2_t* restrict vec, ivec2_t arg)
{
    (*vec)[X] += arg[X];
    (*vec)[Y] += arg[Y];
}

inline
void ivec2_add_to(ivec2_t vec, ivec2_t arg, ivec2_t* restrict dest)
{
    (*dest)[X] = vec[X] + arg[X];
    (*dest)[Y] = vec[Y] + arg[Y];
}

inline
void ivec2_sub(ivec2_t* restrict vec, ivec2_t arg)
{
    (*vec)[X] -= arg[X];
    (*vec)[Y] -= arg[Y];
}

inline
void ivec2_sub_to(ivec2_t vec, ivec2_t arg, ivec2_t* restrict dest)
{
    (*dest)[X] = vec[X] - arg[X];
    (*dest)[Y] = vec[Y] - arg[Y];
}

inline
void ivec2_scale(ivec2_t* restrict vec, float scale)
{
    (*vec)[X] *= scale;
    (*vec)[Y] *= scale;
}

inline
void ivec2_scale_to(ivec2_t vec, float scale, ivec2_t* restrict dest)
{
    ivec2_copy(vec, dest);

    (*dest)[X] *= scale;
    (*dest)[Y] *= scale;
}

inline 
void ivec2_print(ivec2_t vec)
{
    printf("%d %d\n", vec[X], vec[Y]);
}
