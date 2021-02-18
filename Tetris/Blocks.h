#ifndef BLOCKS_H
#define BLOCKS_H

#include "Functions.h"

//void clear_board();
void generate_random_piece();
void rotate_piece();
int generate_piece_number();
void show_next_piece(int piece_number);
int draw_piece(int board[BOARD_WIDTH][BOARD_HEIGHT], int next_piece, int *gameScore);
void rotate_piece(int board[BOARD_WIDTH][BOARD_HEIGHT], int piece, int *rotation_number);

int piece_o[4][4];
int piece_i[2][4][4];
int piece_z[2][4][4];
int piece_s[2][4][4];
int piece_t [4][4][4];
int piece_l[4][4][4];
int piece_j[4][4][4];

int draw_piece_o(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore);
int draw_piece_i(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore);
int draw_piece_z(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore);
int draw_piece_s(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore);
int draw_piece_t(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore);
int draw_piece_l(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore);
int draw_piece_j(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore);

void show_next();

#endif // BLOCKS_H
