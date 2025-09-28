#include <stdio.h>
#include <unistd.h>

struct cell {
    int current; /* current situation, which is visible on screen */
    int future; /* temporary calculation area for next round calculation */
};

void print_board(struct cell board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j].current == 1)
                printf("O ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int x, int y, struct cell board[9][9]) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9) {
                if (board[nx][ny].current == 1)
                    count++;
            }
        }
    }
    return count;
}

void calculate_game(struct cell board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int neighbors = count_neighbors(i, j, board);
            if (board[i][j].current == 1) {
                if (neighbors < 2 || neighbors > 3)
                    board[i][j].future = 0;
                else
                    board[i][j].future = 1;
            } else {
                if (neighbors == 3)
                    board[i][j].future = 1;
                else
                    board[i][j].future = 0;
            }
        }
    }
}

void copy_future_to_current(struct cell board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j].current = board[i][j].future;
        }
    }
}

int main() {
    struct cell board[9][9] = {0, 0};
    int step = 0;

    board[1][2].current = 1;
    board[2][3].current = 1;
    board[3][1].current = 1;
    board[3][2].current = 1;
    board[3][3].current = 1;

    while (1) {
	printf("\033[H\033[J");
        printf("Generation %d:\n", step);
        print_board(board);
        calculate_game(board);
        copy_future_to_current(board);
        step++;
	sleep(1);
    }

    return 0;
}

