#include <stdio.h>
#include <errno.h>
int main (void) {
    FILE *fp;
	int i;
    fp = fopen ("C:\\C\\write.txt","w");
    if (fp == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
	for (i=1;i<=3;i++)
    fprintf (fp, "%d\n",i); // if you want something in the file.
    fclose (fp);
    printf ("File created okay\n");
    return 0;
}
 
