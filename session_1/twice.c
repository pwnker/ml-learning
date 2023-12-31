#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN(xs) sizeof(xs)/sizeof(xs[0])

float train_data[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

float rand_float(void)
{
    return (float)rand()/(float)RAND_MAX;
}

float cost(float w)
{
    size_t train_count = ARRAY_LEN(train_data);
    float cost = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x    = train_data[i][0];
        float y    = x*w;
        float d    = y - train_data[i][1]; 
        cost += d*d;
    }
    cost /= train_count;
    return cost;
}

void train(float *w, size_t titer, float eps, float rate)
{
    for (size_t j=0; j < titer; ++j) {
        float dw = (cost(*w + eps) - cost(*w))/eps;
        *w -= rate*dw;

        printf("ost: %f, w: %f\n", cost(*w), *w);
    }
}

int main() 
{
    srand(time(0));

    float w = rand_float()*10.0f;

    float eps = 1e-3;
    float rate = 1e-3;

    train(&w, 900, eps, rate);
    printf("--------------------------------\n");

    printf("w: %f\n", w);
    printf("--------------------------------\n");

    printf("f(x) = x * w:\n");
    for (size_t i = 0; i < 5; ++i) {
        float y = i*w;
        printf("%zu -> %f\n", i, y);
    }

    return 0;
}
