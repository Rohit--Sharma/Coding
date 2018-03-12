#include <cstdio>
#include <cmath>

using namespace std;

int potency(int corner_id, int crnr_wts[], int n_dims) 
{
    int pot = 0;
    for (int i = 0; i < n_dims; i++) {
        // i is the bit that is to be flipped (adjacent nodes in an n-dim cube have one bit flipped each)
        pot += crnr_wts[(corner_id ^ (1 << i))];
    }
    return pot;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        int array_corner_weights[60000], array_potency[60000];
        for (int i = 0; i < pow(2, n); i++) {
            scanf("%d", &array_corner_weights[i]);
        }
        for (int i = 0; i < pow(2, n); i++) {
            array_potency[i] = potency(i, array_corner_weights, n);
        }
        
        int max_edge_potency = -1;
        for (int i = 0; i < pow(2, n); i++) {
            for (int j = 0; j < n; j++) {
                int edge_potency = array_potency[i] + array_potency[i ^ (1 << j)];
                if(edge_potency > max_edge_potency) {
                    max_edge_potency = edge_potency;
                    //printf("i: %d, j: %d, edge_pot: %d\n", i, i ^ (1 << j), edge_potency);
                }
            }
        }

        printf("%d\n", max_edge_potency);
    }

    return 0;
}