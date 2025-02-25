#pragma once

#include <Common.h>

f32 PSVECMag(const Vec3 *v);

f32 PSVECDotProduct(const Vec3 *a, const Vec3 *b);

void C_MTXOrtho(float mtx[4][4], float top, float bottom, float left, float right,
        float near, float far);
void PSMTXIdentity(float[3][4]);
