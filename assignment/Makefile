CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -Werror -O0 -g

ifneq ($(shell which dcc),)
	CC = dcc
endif

.PHONE: all clear

all: ./crawler 

crawler: crawler.c graph.c list.c graph.h list.h
	$(CC) $(CFLAGS) -o $@ crawler.c graph.c list.c -lxml2 -lcurl -I/usr/include/libxml2

clear:
	rm -f $(BIN)
