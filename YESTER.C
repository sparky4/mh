#include "yester.h"

//originally from: https://stackoverflow.com/questions/4748956/how-do-i-get-yesterdays-date-in-c
char *yester()
{
	time_t now;
	struct tm *ts;
	char yearchar[80];

	now = time(NULL);
	ts = localtime(&now);
	ts->tm_mday--;
	mktime(ts); /* Normalise ts */
	strftime(yearchar, sizeof(yearchar), "%Y%m%d", ts);
	printf("Target String: \"%s\"", yearchar);
	return yearchar;
}

char *yesterweek(unsigned short weeklen)
{
	time_t now;
	struct tm *ts;
	char yearchar[18];

	now = time(NULL);
	ts = localtime(&now);
	ts->tm_mday-=weeklen;
	mktime(ts); /* Normalise ts */
	strftime(yearchar, sizeof(yearchar), "%Y%m%d.mh", ts);
	return yearchar;
}

void weekloop(unsigned short weeklen)
{
    FILE *fptr;
	short len;
    static char filename[9];	//i dont know why it has to be static but here it is~ w
	len = 0;

	while(len<=weeklen)
	{
        strcpy(filename, yesterweek(len));
//        printf("filename: \"%s\"\n", filename);
		fptr = fopen(filename, "wb+");
//        fprintf(fptr, "a");
		fclose(fptr);
		len++;
	}
	unlink(filename);
}
