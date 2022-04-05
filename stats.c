
#include "stats.h"

U16 t[R][C];

r_t rs[R];

c_t cs[C];

t_t ts;

int main(void)
{

    init();

    register U16 r;
    register U16 c;
    register U16 i;
    register U16 j;
    register U16 k;
    register U16 n = R * C;

    for (i = 0; i < n; i++)
    {

        r = i / C;
        c = i % C;

        RSR.h[TRC]++;

        CSC.h[TRC]++;

        TS.h[TRC]++;
    }

    for (i = 0, k = 0; i < U16_MAX; i++)
    {
        for (j = 0; j < TS.h[i]; j++)
        {
            TS.t[k] = i;
            k++;
        }

        if (TS.mo_mx < TS.h[i])
        {
            TS.mo_mx = TS.h[i];
            TS.mo = i;
        }
    }

    TS.mn = TS.t[0];

    TS.mx = TS.t[C - 1];

    if (n & 1)
    {
        TS.me = TS.t[n / 2] * 10;
    }
    else
    {
        TS.me = (((float)TS.t[(n / 2) - 1] + (float)TS.t[n / 2]) / 2) * 10;
    }

    for (r = 0; r < R; r++)
    {
        for (i = 0, k = 0; i < U16_MAX; i++)
        {
            for (j = 0; j < RSR.h[i]; j++)
            {
                RSR.c[k] = i;
                k++;
            }

            if (RSR.mo_mx < RSR.h[i])
            {
                RSR.mo_mx = RSR.h[i];
                RSR.mo = i;
            }
        }

        RSR.mn = RSR.c[0];

        RSR.mx = RSR.c[C - 1];

        if (C & 1)
        {
            RSR.me = RSR.c[C / 2] * 10;
        }
        else
        {
            RSR.me = (((float)RSR.c[(C / 2) - 1] + (float)RSR.c[C / 2]) / 2) * 10;
        }
    }

    for (c = 0; c < C; c++)
    {
        for (i = 0, k = 0; i < U16_MAX; i++)
        {
            for (j = 0; j < CSC.h[i]; j++)
            {
                CSC.r[k] = i;
                k++;
            }

            if (CSC.mo_mx < CSC.h[i])
            {
                CSC.mo_mx = CSC.h[i];
                CSC.mo = i;
            }
        }

        CSC.mn = CSC.r[0];

        CSC.mx = CSC.r[R - 1];

        if (R & 1)
        {
            CSC.me = CSC.r[R / 2] * 10;
        }
        else
        {
            CSC.me = (((float)CSC.r[(R / 2) - 1] + (float)CSC.r[R / 2]) / 2) * 10;
        }
    }

    print();
    return 0;
}

void init(void)
{
    srand(time(0));

    memset(t, 0, R * C * sizeof(U16));

    memset(rs, 0, R * sizeof(r_t));

    memset(cs, 0, C * sizeof(c_t));

    for (U16 r = 0; r < R; r++)
    {
        for (U16 c = 0; c < C; c++)
        {

            TRC = rand() % 10;
        }
    }
}

void print(void)
{

    for (U16 r = 0; r < R; r++)
    {
        printf("ROW %02lu: ", r);

        for (U16 c = 0; c < C; c++)
        {

            printf("%02lu ", TRC);
        }
        printf("\n");
    }

    for (U16 r = 0; r < R; r++)
    {

        for (U16 i = 0; i < C; i++)
        {
            printf("%02lu ", RSR.c[i]);
        }

        printf("\nMED = %lu, MOD = %lu\n", RSR.me, RSR.mo);
    }

    for (U16 c = 0; c < C; c++)
    {

        for (U16 i = 0; i < R; i++)
        {
            printf("%02lu ", CSC.r[i]);
        }

        printf("\nMED = %lu, MOD = %lu\n", CSC.me, CSC.mo);
    }

    printf("\nMED = %lu, MOD = %lu\n", TS.me, TS.mo);
}
