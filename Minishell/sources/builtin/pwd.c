void    do_pwd(void)
{
    char *dir;

    dir = getcwd(NULL, 0);
    printf("%s\n", dir);
    free(dir);
}