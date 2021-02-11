/*
 * Copyright 2021 Benjamin Edgington
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file c_kzg_util.c */

#ifndef C_KZG_H
#define C_KZG_H

#include <stdbool.h>
#include "../inc/blst.h"

typedef enum {
    C_KZG_OK = 0,  // Success!
    C_KZG_BADARGS, // The supplied data is invalid in some way
    C_KZG_ERROR,   // Internal error - should never occur
    C_KZG_MALLOC,  // Could not allocate memory
} C_KZG_RET;

#ifdef DEBUG
#include <stdlib.h>
#include <stdio.h>
#define ASSERT(cond, ret)                                                                                              \
    if (!(cond)) {                                                                                                     \
        printf("\n%s:%d: Failed ASSERT: %s\n", __FILE__, __LINE__, #cond);                                             \
        abort();                                                                                                       \
    }
#else
#define ASSERT(cond, ret)                                                                                              \
    if (!(cond)) return (ret)
#endif

#endif
