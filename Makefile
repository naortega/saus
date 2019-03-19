CC=gcc
DEBUG=0
INCFLAGS=`pkg-config jack --cflags`
LDFLAGS=`pkg-config jack --libs` -lreadline
CFLAGS=$(INCFLAGS) -std=c99 -Wall -Wextra -Wfatal-errors -Werror
OBJS=src/main.o

ifeq ($(DEBUG),1)
	CFLAGS+=-g -O0 -DDEBUG
else
	CFLAGS+=-O2 -DNDEBUG
endif

%.o:%.c
	$(CC) -c -o $@ $< $(CFLAGS)

saus: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJS)
