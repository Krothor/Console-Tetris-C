#include "Blocks.h"
#include "Functions.h"





//bloki i ich rotacja

//blok O
int piece_o[4][4] =
{
    //blok o jest nieobracalny
        {2,2,0,0},
        {2,2,0,0},
        {0,0,0,0},
        {0,0,0,0}

};

int draw_piece_o(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore)
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
            if(board[j+2][i+1] == 1)
                game_over(gameScore);
            else
                board[j+2][i+1] = piece_o[i][j];
        }
}

//blok I
int piece_i[2][4][4] =
{
    {
        {2,0,0,0},
        {2,0,0,0},
        {2,0,0,0},
        {2,0,0,0}
    },
    {
        {2,2,2,2},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    }
};

int draw_piece_i(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore)
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
            if(board[j+2][i+1] == 1)
                game_over(gameScore);
            else
                board[j+2][i+1] = piece_i[0][i][j];
        }
}

//blok Z
int piece_z[2][4][4] =
{
    {
        {2,2,0,0},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {2,2,0,0},
        {2,0,0,0},
        {0,0,0,0}
    }
};

int draw_piece_z(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore)
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
            if(board[j+2][i+1] == 1)
                game_over(gameScore);
            else
                board[j+2][i+1] = piece_z[0][i][j];
        }
}

//blok S
int piece_s[2][4][4] =
{
    {
        {2,0,0,0},
        {2,2,0,0},
        {0,2,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {2,2,0,0},
        {0,0,0,0},
        {0,0,0,0}
    }
};

int draw_piece_s(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore)
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
            if(board[j+2][i+1] == 1)
                game_over(gameScore);
            else
                board[j+2][i+1] = piece_s[0][i][j];
        }
}

//blok T
int piece_t [4][4][4] =
{
    {
        {2,0,0,0},
        {2,2,0,0},
        {2,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {2,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {2,2,0,0},
        {0,2,0,0},
        {0,0,0,0}

    },
    {
        {2,2,2,0},
        {0,2,0,0},
        {0,0,0,0},
        {0,0,0,0}
    }
};

int draw_piece_t(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore)
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
            if(board[j+2][i+1] == 1)
                game_over(gameScore);
            else
                board[j+2][i+1] = piece_t[0][i][j];
        }
}

//blok L
int piece_l[4][4][4] =
{
  {
    {2,0,0,0},
    {2,0,0,0},
    {2,2,0,0},
    {0,0,0,0}
  },
  {
    {2,2,2,0},
    {2,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  },
  {
    {2,2,0,0},
    {0,2,0,0},
    {0,2,0,0},
    {0,0,0,0}
  },
  {
    {0,0,2,0},
    {2,2,2,0},
    {0,0,0,0},
    {0,0,0,0}
  }
};

int draw_piece_l(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore)
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
            if(board[j+2][i+1] == 1)
                game_over(gameScore);
            else
                board[j+2][i+1] = piece_l[0][i][j];
        }

}

//blok J
int piece_j[4][4][4] =
{
  {
    {2,2,0,0},
    {2,0,0,0},
    {2,0,0,0},
    {0,0,0,0}
  },
  {
    {2,2,2,0},
    {0,0,2,0},
    {0,0,0,0},
    {0,0,0,0}
  },
  {
    {0,2,0,0},
    {0,2,0,0},
    {2,2,0,0},
    {0,0,0,0}
  },
  {
    {2,0,0,0},
    {2,2,2,0},
    {0,0,0,0},
    {0,0,0,0}
  }
};

int draw_piece_j(int board[BOARD_WIDTH][BOARD_HEIGHT], int *gameScore)
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
            if(board[j+2][i+1] == 1)
                game_over(gameScore);
            else
                board[j+2][i+1] = piece_j[0][i][j];
        }
}


int generate_piece_number()
{
    srand((unsigned) time(NULL));
    int random = rand() % 7;
    return random;
}



void show_next_piece(int piece_number)
{
    switch(piece_number)
    {
    case 0:
        show_next(piece_o);
        break;
    case 1:
        show_next(piece_i);
        break;
    case 2:
        show_next(piece_s);
        break;
    case 3:
        show_next(piece_z);
        break;
    case 4:
        show_next(piece_t);
        break;
    case 5:
        show_next(piece_l);
        break;
    case 6:
        show_next(piece_j);
        break;
    }
}

int draw_piece(int board[BOARD_WIDTH][BOARD_HEIGHT], int next_piece, int *gameScore)
{
    int piece_number = next_piece;
    switch(piece_number)
    {
    case 0:
        draw_piece_o(board, gameScore);
        break;
    case 1:
        draw_piece_i(board, gameScore);
        break;
    case 2:
        draw_piece_z(board, gameScore);
        break;
    case 3:
        draw_piece_s(board, gameScore);
        break;
    case 4:
        draw_piece_t(board, gameScore);
        break;
    case 5:
        draw_piece_j(board, gameScore);
        break;
    case 6:
        draw_piece_l(board, gameScore);
        break;
    }
}

void show_next(int next_piece[4][4][4])
{
    for(int m = 0; m<8; m++)
    {
        for(int n = 0; n<8; n++)
        {
            if(n==0 || n==7)
                printf("|");
            else if((m==0 || m==7)&&(n>0 && n<7))
                printf("-");
            else if((m==1 || m==6)&&(n>0 && n<7))
                printf(" ");
            else if((m>1 &&  m<6)&&(n==1 || n==6))
                printf(" ");
            else
            {
                if(next_piece[0][n-2][m-2] == 2)
                    printf("O");
                else if(next_piece[0][n-2][m-2] == 0)
                    printf(" ");
            }
        }
        printf("\n");
    }
}


void rotate_piece(int board[BOARD_WIDTH][BOARD_HEIGHT], int piece, int *rotation_number)
{
    int x = 0,y = 0;
    for(int i = 1; i<BOARD_HEIGHT-1+4; i++)
        for(int j = 1; j<BOARD_WIDTH-1; j++)
            if(piece != 0)
                if(board[j][i] == 2)
                {
                    if(x == 0 && y == 0)
                    {
                        x = i;
                        y = j;
                    }
                    board[j][i] = 0;
                }
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(board[y+i][x+j] == 0)
            {
                if(piece == 1 || piece == 2 || piece == 3)
                {
                    if(*rotation_number>0)
                        *rotation_number = -1;
                    if(piece == 1)
                        board[y+i][x+j] = piece_i[*rotation_number+1][i][j];
                    if(piece == 2)
                        board[y+i][x+j] = piece_s[*rotation_number+1][i][j];
                    if(piece == 3)
                        board[y+i][x+j] = piece_z[*rotation_number+1][i][j];
                }
                if(piece == 4 || piece == 5 || piece == 6)
                {
                    if(*rotation_number>2)
                        *rotation_number = -1;
                    if(piece == 4)
                        board[y+i][x+j] = piece_t[*rotation_number+1][i][j];
                    if(piece == 5)
                        board[y+i][x+j] = piece_l[*rotation_number+1][i][j];
                    if(piece == 6)
                        board[y+i][x+j] = piece_j[*rotation_number+1][i][j];
                }
            }
        }
    }
    (*rotation_number)++;
}

