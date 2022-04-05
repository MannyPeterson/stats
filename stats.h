#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef STATS_H_
#define STATS_H_

#define R 20
#define C 20
#define RSR rs[r]
#define CSC cs[c]
#define TRC t[r][c]
#define TS ts
#define U16 uint_fast16_t
#define U16_MAX UINT16_MAX

typedef struct r_s
{
    U16 mx; /* maximum */
    U16 mn; /* mininum */
    U16 me; /* median */
    U16 mo; /* mode */
    U16 mo_mx;
    U16 c[C];
    U16 h[U16_MAX];
} r_t;

typedef struct c_s
{
    U16 mx; /* maximum */
    U16 mn; /* mininum */
    U16 me; /* median */
    U16 mo; /* mode */
    U16 mo_mx;
    U16 r[R];
    U16 h[U16_MAX];
} c_t;

typedef struct t_s
{
    U16 mx; /* maximum */
    U16 mn; /* mininum */
    U16 me; /* median */
    U16 mo; /* mode */
    U16 mo_mx;
    U16 t[R * C];
    U16 h[U16_MAX];
} t_t;

void init(void);
void print(void);

#endif