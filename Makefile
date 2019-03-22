# Copyright (C) 2019 Ortega Froysa, Nicolás <nortega@themusicinnoise.net>
# Author: Ortega Froysa, Nicolás <nortega@themusicinnoise.net>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC=gcc
DEBUG=0
INCFLAGS=`pkg-config jack --cflags`
LDFLAGS=`pkg-config jack --libs` -lreadline
CFLAGS=$(INCFLAGS) -std=c99 -Wall -Wextra -Wfatal-errors -Werror
HDRS=src/args.h
OBJS=src/main.o

ifeq ($(DEBUG),1)
	CFLAGS+=-g -O0 -DDEBUG
else
	CFLAGS+=-O2 -DNDEBUG
endif

%.o:%.c $(HDRS)
	$(CC) -c -o $@ $< $(CFLAGS)

saus: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJS)
