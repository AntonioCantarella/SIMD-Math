#pragma once

#define FORCE_INLINE __forceinline
#define SHUFFLE3(Vector3fv, X, Y, Z) _mm_shuffle_ps(Vector3fv._value, Vector3fv._value, _MM_SHUFFLE(Z, Z, Y, X))