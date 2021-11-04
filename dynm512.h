void Init512Banks(void);
char*	alloc512(char* BankPointer, short Size);
void	free512(char* Buf, char Bank);
void	setbank(char b);
int	GetTotalFree();
