#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "compression.h"

void compression (char* archive)
{
		char* nomArchive= archive;
		char *buf;
		asprintf(&buf, "gzip %s", nomArchive);
		system(buf);
		free(buf);
}
