#include "Functions.h"
#include "Blocks.h"

gameOn = 1;
void menu()
{
    clear_screen();
    draw_tetris();
    printf("\t\tPress N for NEW GAME\n");
    printf("\t\tPress H for CONTROLLS\n");
    //printf("\t\tPress L for LEADERBOARD\n");
    printf("\t\tPress Q to QUIT\n");

    menu_options();
}
void draw_tetris()
{
    printf("\t ########  #####  ########  #####    ##  ######\n ");
    printf("\t ########  #####  ########  ##  ##   ##  ##    \n ");
    printf("\t    ##     ##        ##     ##  ##   ##  ##    \n ");
    printf("\t    ##     #####     ##     #####    ##   #### \n ");
    printf("\t    ##     ##        ##     ## ##    ##      ##\n ");
    printf("\t    ##     #####     ##     ##  ##   ##      ##\n ");
    printf("\t    ##     #####     ##     ##   ##  ##  ######\n ");

    printf("\n");
    printf("\n");
    printf("\n");
}

int menu_options()
{
        switch(_getch())
        {
            case 110: //new game
                new_game();
                break;
            case 104: // 'h'
                show_controls();
                break;
            case 113: // 'q'
                gameOn--;
                break;
            //case 108: // 'l'
                //leaderboard(head);
                //break;
            default:
                menu();
                break;
        }
}

void delay(int milli_seconds)
{
// Storing start time
clock_t start_time = clock();
// looping till required time is not achieved
while (clock() < start_time + milli_seconds) ;
}

void show_controls()
{
    clear_screen();
    draw_tetris();
    printf("\tUP ARROW - Rotate\n");
    printf("\tLEFT ARROW - Move left\n");
    printf("\tRIGHT ARROW - Move Right\n");
    //printf("\tDOWN ARROW - Accelerate Downwards\n");
    printf("\tM - Back to Menu\n");
    printf("\tQ - Quit Game\n");

    printf("\n\n\tNOTE - CapsLock must be off\n");
    switch(_getch())
    {
    case 109: // 'm'
        menu();
        break;
    case 113: // 'q'
        gameOn--;
        break;
    default:
        show_controls();
        break;
    }
}

void new_game()
{
    clear_screen();
    int board[BOARD_WIDTH][BOARD_HEIGHT];
    clear_board(board);
    add_board_borders(board);
    draw(board);

    game_loop(board);
}



void game_loop(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    int rotation_number = 0;
    char direction = 'd'; //d-down l-left, r-right
    int dificulty_time = 100;  //poprawiæ na 500q
    double dificulty_counter = 1.30;
    int dificulty_requirements = 50;
    int gameScore = 0;
    int frameCounter = 0;
    int piece, next_piece;
    piece = generate_piece_number();
    sleep(1);
    next_piece = generate_piece_number();

    draw_piece(board, piece, gameScore);

    while(gameOn == 1)
    {
        if (GetAsyncKeyState(VK_DOWN) & (0x8000 != 0))
            direction = 'd';
        else if (GetAsyncKeyState(VK_UP) & (0x8000 != 0))
            rotate_piece(board, piece, &rotation_number);
        else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0))
            direction = 'r';
        else if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0))
            direction = 'l';
        else if (GetAsyncKeyState('Q') & (0x8000 != 0))
            gameOn--;
        else if (GetAsyncKeyState('M') & (0x8000 != 0))
            menu();
        move_piece(board, &direction, &next_piece, &piece, &gameScore);
        moved_to_piece_status(board);
        clear_screen();
        draw(board);
        show_score(&gameScore);
        show_next_piece(next_piece);
        if(frameCounter == 15)
           {
               score_from_time(&gameScore);
               frameCounter = 0;
           }
        if(gameScore > dificulty_requirements)
        {
            if(dificulty_time > 50)
                dificulty_time -= 35;
            dificulty_requirements *= dificulty_counter;
        }
        delay(dificulty_time);
        frameCounter++;
    }
}

void move_piece(int board[BOARD_WIDTH][BOARD_HEIGHT], char* direction, int *next_piece, int *piece, int *score)
{
    if(*direction == 'd')
    {
       move_down(board, next_piece, piece, score);
    }
    else if(*direction == 'l')
    {
        move_left(board);
        *direction = 'd';
    }
    else if(*direction == 'r')
    {
        move_right(board);
        *direction = 'd';
    }
    return;
}

void move_left(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    bool wall = 0;
    for(int i = 0; i < BOARD_WIDTH; i++)
    {
        for(int j = 0; j < BOARD_HEIGHT; j++)
        {
            if(board[i][j] == 2 && ((board[i-1][j] == 1) || (board[i-1][j] == -1)))
            {
                wall = 1;
            }
        }
    }

    if(wall != 1)
    {
        for(int i = 0; i < BOARD_WIDTH ; i++)
        {
            for(int j = 1; j < BOARD_HEIGHT-1; j++)
            {
                if(board[i][j] == 2)
                {
                    board[i-1][j] = 4;
                    board[i][j] = 0;
                }
            }
        }
    }
    //move_down(board);
    return;
}

void move_right(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    bool wall = 0;
    for(int i = 0; i < BOARD_WIDTH; i++)
    {
        for(int j = 0; j < BOARD_HEIGHT; j++)
        {
            if(board[i][j] == 2 && ((board[i+1][j] == 1) || (board[i+1][j] == -1)))
            {
                wall = 1;
            }
        }
    }

    if(wall != 1)
    {
        for(int i = BOARD_WIDTH-1; i >=0 ; i--)
        {
            for(int j = 1; j < BOARD_HEIGHT-1; j++)
            {
                if(board[i][j] == 2)
                {
                    board[i+1][j] = 4;
                    board[i][j] = 0;
                }
            }
        }
    }
    //move_down(board);
    return;
}

void move_down(int board[BOARD_WIDTH][BOARD_HEIGHT], int *next_piece, int *piece, int *gameScore)
{
    if (is_fallen(board) == 0)
    {
        for(int i = 0; i < BOARD_WIDTH; i++)
        {
            for(int j = BOARD_HEIGHT-1; j >= 0; j--)
            {
                if (board[i][j] == 2 || board[i][j] == 4) //przesun w dol te normalne klocki i te przesuniete w bok
                {
                    board[i][j+1] = 3; //3 jako tymczasowy stan klocka - przesuniety w bok
                    board[i][j] = 0;
                }
            }
        }
    }
    else
    {
        set_fallen_status(board);
        check_line_iffull(board, gameScore);
        *piece = *next_piece;
        *next_piece = generate_piece_number();
        draw_piece(board, *piece, gameScore); //add score to gameOver()
    }
    return;
}



bool is_fallen(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    for(int i = 0; i < BOARD_WIDTH; i++)
    {
        for(int j = 0; j < BOARD_HEIGHT; j++)
        {
            if(board[i][j] == 2)
            {
                if ((board[i][j+1] == 1) || (board[i][j+1] == -2))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}


void moved_to_piece_status(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    for(int i = 1; i < BOARD_WIDTH-1; i++)
    {
        for(int j = 1; j < BOARD_HEIGHT-1; j++)
        {
            if (board[i][j] == 3 || board[i][j] == 4)
                board[i][j] = 2;
        }
    }
    return;
}

void set_fallen_status(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    for(int i = 1; i < BOARD_WIDTH-1; i++)
    {
        for(int j = 1; j < BOARD_HEIGHT-1; j++)
        {
             if (board[i][j] == 2 || board[i][j] == 4)
                board[i][j] = 1;
        }
    }
    return;
}



void draw(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
	draw_tetris();
	printf("\n\n");
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (board[i][j] == -1)
				printf("|");
            else if(board[i][j] == 0)
                printf(" ");
            else if(board[i][j] == 1)
                printf("O");
            else if(board[i][j] == -2)
                printf("-");
            else if(board[i][j] == 2)
                printf("#");
		}
		printf("\n");
	}

}

void clear_screen()
{
    system("cls");
}

void add_board_borders(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    for(int i = 0; i < BOARD_WIDTH; i++)
    {
        board[i][0] = -2;
        board[i][BOARD_HEIGHT-1] = -2;
    }
    for(int i = 0; i < BOARD_HEIGHT; i++)
    {
        board[0][i] = -1;
        board[BOARD_WIDTH-1][i] = -1;
    }
}


void clear_board(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
    for(int i = 1; i < BOARD_WIDTH-1; i++)
    {
        for(int j = 1; j < BOARD_HEIGHT-1; j++)
        {
            board[i][j] = 0;
        }
    }
    return;
}

void check_line_iffull(int board[BOARD_WIDTH][BOARD_HEIGHT], int *score)
{
    int width_counter = 0;
    for(int i = 1; i<BOARD_HEIGHT-1; i++)
    {
        for(int j = 1; j<BOARD_WIDTH-1; j++)
        {
            if(board[j][i] == 1)
                width_counter++;
            if(width_counter == BOARD_WIDTH-2)
                move_line_down(board, i, score);
        }
        width_counter = 0;
    }
}

void move_line_down(int board[BOARD_WIDTH][BOARD_HEIGHT], int i, int *score)
{
    for(i; i>1; i--)
    {
        for(int j=1; j<BOARD_WIDTH-1; j++)
        {
            board[j][i] = board[j][i-1];
        }
    }
    score_from_line(score);
}

void show_score(int* s)
{
    printf("\n\n\nSCORE: %d\n", *s);
    printf("\n");
}

void score_from_line(int *s)
{
    *s += 20;
}

void score_from_time(int* s)
{
    (*s)++;
}


void game_over(int *gameScore)
{
    clear_screen();
    draw_tetris();

    printf("\n\\\\\\\\\\\\\\\t\t\tYOU LOST!\t\t\t//////////////");
    printf("\n\\\\\\\\\\\\\\\t\t\tYour Score was: %i\t\t\t//////////////", &gameScore);

    //add_new_person(&head, gameScore);
    delay(3000);
    menu();


}



//  \\\\\NOT IMPLEMENTED/////

//poprawic otwieranie i zamykanie pliku

/*

void leaderboard(struct Statistics **head)
{

    clear_screen();

    draw_tetris();

    printf("\tName:\t\t\tScore:\n");

    writeList(*head);

    printf("\n\n\tM - Back to Menu\n");
    printf("\tQ - Quit Game\n");
    switch(_getch())
    {
        case 109: // 'm'
            menu();
            break;
        case 113: // 'q'
            gameOn--;
            break;
        default:
            leaderboard(head);
            break;
    }
}


void initialize_list(struct Statistics **head)
{
    *head = NULL;
    return;
}

void writeList(struct Statistics** head)
{
    clear_screen();
    draw_tetris();
    if (*head == NULL)
    {
        printf("\n\n\tThe Ladderboard is empty");
        delay(3000);
        menu();
    }
    else
    {
        struct Statistics *end = *head;
        while(end != NULL)
        {
            printf("%s: %s\n", end->person, end->score);
            end = end->next;
        }
    }


}

void add_new_person(struct Statistics** head, int *gameScore )
{
    char *person[20];
    int *score;

    printf("\n\tWrite your name!\n");

    fflush(stdin);
    printf("Name: ");
    scanf("%s", person);

    struct Statistics* new_person = (struct Statistics*)malloc(sizeof(struct Statistics));
    fill_struct(new_person, person, score);
    add_to_beginning(head, new_person);

    //sort_list(*head);
    return;
}

void fill_struct(struct Statistics* new_person, char* person[20], int* score)
{
    new_person->person[20] = person;
    new_person->score = score;
    return;
}

void add_to_beginning(struct Statistics** head, struct Statistics* list)
{
    list->next = *head;
    *head = list;
    return;
}
//sorting by score (need to change to that) (not working)
void sort_list(struct Statistics** head)
{
    struct Statistics* temp = NULL;
    struct Statistics* help = NULL;
    char* l;
    char* t;

    for(temp = *head; temp != NULL; temp = temp->next)
    {
        for(help = temp; help != NULL; help = help->next)
        {
            if((temp->score) < (help->score))
            {
                swap_person(help, temp);
            }
        }
    }
}



void swap_person(struct Statistics* first, struct Statistics* second)
{
    struct Statistics *temp_word = first;
    memcpy(&first, &second, sizeof(first));
    memcpy(&second, &temp_word, sizeof(second));
    //first->person = second->person;
    //second->person = temp_word;

    //int *temp_score = first->score;
    //first->score = second->score;
    //second->score = temp_score;
}

void read_data(struct Statistics** head)
{
    struct Statistics* list = *head;

    int i = 0;
    char *person;
    int *score;
    int new_score;

    FILE* high_score = fopen("C:\\Users\\kroth\\Desktop\\Tetris\\Tetris\\leaderboard.txt", "rb");
    if (high_score == NULL)
    {
        puts ("ERROR! Unable to open file.\n");
        fclose(high_score);
     }
     while (fscanf(high_score, "%s %d", person[i], &score) == 2)
     {
           if (new_score >= score)
           {
               score = new_score;
               new_score = -1;
            }
            printf("%s\t\t%d\n", person[i], score);
            i++;

    }

    fclose(high_score);
    return;
}


void save_data(struct Statistics** head)
{
    FILE* outputFile = fopen("leaderboard.txt", "wb");

    int i = 0;
    if (outputFile)
    {
        struct Statistics *temp = *head;
        while(temp != NULL && i < 10)
        {
            fwrite(temp->person, sizeof(char), (strlen(temp->person) + 1), outputFile);
            fwrite(temp->score, sizeof(int), (strlen(temp->score) + 1), outputFile);
            temp = temp->next;
        }
        fwrite(NULL, sizeof(char), 1, outputFile);
    }
    fclose(outputFile);
    return;
}

void delete_list(struct Statistics** head)
{
    struct Statistics *temp = *head;
    struct Statistics *temp2;
    while(temp != NULL)
    {
        temp2 = temp->next;
        free(temp->person);
        free(temp->score);
        free(temp);
        temp = temp2;
    }
    *head = NULL;
}

*/
