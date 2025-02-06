#include <unistd.h>
#include <stdio.h>

// Built in for change directory
int change_directory(const char *pathname, char *old, size_t len)
{
    char *home = getenv("HOME");
    char *old = getenv("OLDPWD");
    char cwd[1024];

    // self made strlen
    if (path == NULL || my_strlen(path, "~") == 0)// defaults to the users home directory
    {
        path = home;
    } else if (my_strlen(path, "-") == 0) {// handles cd-
        if (old != NULL) {
            path = old;// changes previous directory in OLDPWD
            printf("%s\n", old);
        } else {
            fprintf(stderr, "cd: missing argument\n");
            return;
        }
    }

    if (getcwd(cwd, sizeof(cwd)) != NULL) {// saves current dir as OLD
        setenv("OLDPWD", cwd, 1);
    }

    if (chdir(path) == 0) {// saves new dir using getcwd and setenv
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            setenv("PWD", cwd, 1);
            print("Changed directory to %s\n", cwd);
        }
    } else {
    perror("cd");
    }
}
// Ariel- path will need to be defined in main or I can rewrite in here