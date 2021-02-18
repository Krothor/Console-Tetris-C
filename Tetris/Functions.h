#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <windows.h>

#define BOARD_WIDTH 19
#define BOARD_HEIGHT 25
#define TIME_PER_FRAME 10000
#define LEVEL_DIFICULTY 10
#define TIME_L_MAX 50
#define TIME_F_MAX 60
/*
typedef struct Statistics
{
    char person[20];
    int score;
    struct Statistics* next;
};

struct Statistics *head;

void initialize_list(struct Statistics** head);
void add_new_person(struct Statistics** head, int *gameScore );
void fill_struct(struct Statistics* new_person, char* person[20], int* score);
void add_to_beginning(struct Statistics** head, struct Statistics* list);
void read_data(struct Statistics** head);
void writeList(struct Statistics** head);
void saveData(struct Statistics** head);
void sort_list(struct Statistics** head);
void delete_list(struct Statistics** head);
*/

void add_board_borders(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void draw(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void clear_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);

void game_loop(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void movePiece(int board[BOARD_WIDTH][BOARD_HEIGHT], char* direction, int *next_piece, int *piece, int *gameScore);
void move_down(int board[BOARD_WIDTH][BOARD_HEIGHT], int *next_piece, int *piece, int *score);
void move_left(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void move_right(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void moved_to_piece_status(int board[BOARD_WIDTH][BOARD_HEIGHT]);
bool is_fallen(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void set_fallen_status(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void check_line_iffull(int board[BOARD_WIDTH][BOARD_HEIGHT], int *score);
void move_line_down(int board[BOARD_WIDTH][BOARD_HEIGHT], int i, int *score);

void menu();
int menu_options();
void delay(int milli_seconds);
void show_controls();
void new_game();
int gameOn;
void draw_tetris();
void leaderboard(struct Statistics **head);
void clear_screen();

void show_score(int* s);
void score_from_time(int* s);
void score_from_line(int *s);


#endif // FUNCTIONS_H_INCLUDED
