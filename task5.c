#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char **argv ) {
    //Создаем новый процесс
	int pid = fork();

    //Если процесс создан успешно, то
	if ( pid == 0 ) {
	    //Запускаем exec с нашими аргументами
		execvp( "./sequential_min_max", argv);
		return 0;
	}
    
    //Создаем переменную, в которой отображен статус процесса
	int status;
	//Ждем пока статус процесса изменится
	wait(&status);

	return 0;
}