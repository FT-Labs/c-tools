#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *cmd_with_output(const char *cmd)
{
    FILE *fp;
    static char buf[1024];
    memset(buf, 0, sizeof(buf));

    fp = popen(cmd, "r");
    if (!fp) {
        fprintf(stderr, "Can't execute command");
        return NULL;
    }

    while (fgets(buf, sizeof(buf), fp));
    pclose(fp);
    return buf;
}

void cmd_without_output(const char *cmd)
{
    static char buf[1024];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, cmd);
    system(buf);
}
