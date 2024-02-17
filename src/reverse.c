#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_CHUNK_LENGTH 1024

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0 ; i < len / 2 ; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* readLine() {
    char* buff = calloc(LINE_CHUNK_LENGTH, sizeof(char));
    char line[LINE_CHUNK_LENGTH];
    while(fgets(line, LINE_CHUNK_LENGTH, stdin)) {

        if(buff[0] != 0) {
            buff = realloc(buff, (strlen(buff) + strlen(line)) * sizeof(char));
            if(buff == NULL) {
                printf("Failed to reallocate memory.\n");
                free(buff);
                buff = NULL;
                exit(1);
            }
        }

        buff = strcat(buff, line);

        char lastChar = line[strlen(line) - 1];
        if(lastChar == '\n' || lastChar == EOF) {
            return buff;
        }
    }
    free(buff);
    buff = NULL;
    return NULL;
}

int main(int argc, char *argv[]) {
    int opt;
    int verbose_flag = 0;

    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
        case 'v':
            verbose_flag = 1;
            break;
        default:
            fprintf(stderr, "Usage: %s [-v (optional)]\n", argv[0]);
            return 1;
        }
    }
    
    char* line;
    while (line = readLine()) {
        line[strcspn(line, "\n")] = 0;

        if (verbose_flag) {
            fputs(line, stdout);
            fputs(" -> ", stdout);
        }

        reverse(line);
        fputs(line, stdout);
        putchar('\n');
        free(line);
        line = NULL;
    }
    return 0;
}