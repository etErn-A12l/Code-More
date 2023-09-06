#include <stdio.h>

int main() {
    FILE *fp;
    char path[1024];

    fp = popen("ls -l", "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("%s", path);
    }

    pclose(fp);
    return 0;
}
