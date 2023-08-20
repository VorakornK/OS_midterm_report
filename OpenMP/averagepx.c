#include <stdio.h>
#include <omp.h>

int main() {
    int N;
    scanf("%d", &N);

    int num[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    int sum = 0;
    int num_threads = omp_get_max_threads();
    int local_sums[num_threads];

    for (int i = 0; i < num_threads; i++) {
        local_sums[i] = 0;
    }

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        local_sums[thread_id] = 0;

        for (int i = thread_id; i < N; i += num_threads) {
            local_sums[thread_id] += num[i];
        }
    }

    for (int i = 0; i < num_threads; i++) {
        sum += local_sums[i];
    }

    int average = sum / N;
    printf("%d\n", average);

    return 0;
}
