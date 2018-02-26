#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int l;
    scanf("%d", &l);
    while (l) {
        char rot[3];
        char prev[3] = "";
        while (--l) {
            scanf("%s", rot);
            if (strcmp(rot, "No")) {
                //printf("Not no\n");
                if (!strcmp(prev, "") || !strcmp(prev, "+x")) {
                    strcpy(prev, rot);
                } else if (!strcmp(prev, "-x")) {
                    if (!strcmp(rot, "+z")) {
                        strcpy(prev, "-z");
                    } else if (!strcmp(rot, "-z")) {
                        strcpy(prev, "+z");
                    } else if (!strcmp(rot, "+y")) {
                        strcpy(prev, "-y");
                    } else if (!strcmp(rot, "-y")) {
                        strcpy(prev, "+y");
                    }
                } else {
                    if (!strcmp(prev, "+z")) {
                        if (!strcmp(rot, "+y")) {
                            strcpy(prev, "+z");
                        } else if (!strcmp(rot, "-y")) {
                            strcpy(prev, "+z");
                        } else if (!strcmp(rot, "+z")) {
                            strcpy(prev, "-x");
                        } else if (!strcmp(rot, "-z")) {
                            strcpy(prev, "+x");
                        }
                    } else if (!strcmp(prev, "-z")) {
                        if (!strcmp(rot, "+y")) {
                            strcpy(prev, "-z");
                        } else if (!strcmp(rot, "-y")) {
                            strcpy(prev, "-z");
                        } else if (!strcmp(rot, "+z")) {
                            strcpy(prev, "+x");
                        } else if (!strcmp(rot, "-z")) {
                            strcpy(prev, "-x");
                        }
                    } else if (!strcmp(prev, "+y")) {
                        if (!strcmp(rot, "+z")) {
                            strcpy(prev, "+y");
                        } else if (!strcmp(rot, "-z")) {
                            strcpy(prev, "+y");
                        } else if (!strcmp(rot, "+y")) {
                            strcpy(prev, "-x");
                        } else if (!strcmp(rot, "-y")) {
                            strcpy(prev, "+x");
                        }
                    } else if (!strcmp(prev, "-y")) {
                        if (!strcmp(rot, "+z")) {
                            strcpy(prev, "-y");
                        } else if (!strcmp(rot, "-z")) {
                            strcpy(prev, "-y");
                        } else if (!strcmp(rot, "+y")) {
                            strcpy(prev, "+x");
                        } else if (!strcmp(rot, "-y")) {
                            strcpy(prev, "-x");
                        }
                    }
                }
            }
            //printf("%s\n", prev);
        }
        printf("%s\n", prev);
        scanf("%d", &l);
    }

    return 0;
}