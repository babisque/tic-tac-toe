int checksequence(char *fields);
void displayBoard(const char *player1, const char *player2, const char *fields);
void updateboard(char symbol, int play, char *fields, int *player);
void playGame(const char *player1, const char *player2, int isAgainstAI);
int getRandomMove(char *fields);
int isValidMove(int move, const char *fields);