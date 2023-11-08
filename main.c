#include "DS.h"

int main()
{
    int done = 0;
    int t;
    char a[100];
    List l[10];
    while(!done)
    {
        printf("1. add data, 2: delete data, 3: print data with chain, 4: search_count, 5: exit\n");
        scanf("%d" , &t);
        switch(t)
        {
            case 1:
                printf("Oruulah utga: ");
                scanf("%s" , a);
                int id = hash(a);
                addData(&l[id], a);
                break;
            case 2:
                printf("Ustgah utga: ");
                scanf("%s" , a);
                id = hash(a);
                deleteData(&l[id], a);
                break;
            case 3:
                printf("Haih utga: ");
                scanf("%s" , a);
                id = hash(a);
                printData(&l[id], a);
                break;
            case 4:
                printf("Haih utga: ");
                scanf("%s" , a);
                id = hash(a);
                printf("Search count: %d\n" , count(&l[id], a));
                break;
            case 5:
                done = 1;
                break;
            default:
                printf("wrong input\n");
                break;
        }
    }
}