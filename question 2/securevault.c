#include <stdio.h>
#include <stdbool.h>
#define MAX 20

int N;
int board[MAX];
bool cols[MAX];
bool diag1[2 * MAX];
bool diag2[2 * MAX];
int solutionCount = 0;

void printSolution() {
    printf("Solution %d:\n", solutionCount);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("V ");   //vault
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

//backtracking implementation
void solve(int row) {
    if (row == N) {
        solutionCount++;
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++) {
        
        //check if there is a conflict
        if (cols[col] || diag1[row-col+N] || diag2[row + col])
            continue;

        //vault position in correct place
        board[row] = col;
        cols[col] = true;
        diag1[row - col + N] = true;
        diag2[row + col] = true;

        //rec
        solve(row + 1);

        //backtrack
        cols[col] = false;
        diag1[row - col + N] = false;
        diag2[row + col] = false;
    }
}

int main() {
    printf("Enter N: ");
    scanf("%d", &N);

    //init arrays
    for (int i = 0; i < N; i++) {
        board[i] = -1;
        cols[i] = false;
    }

    for (int i = 0; i < 2 * N; i++) {
        diag1[i] = false;
        diag2[i] = false;
    }

    //solve
    solve(0);

    printf("Total solutions: %d\n", solutionCount);
    return 0;
}