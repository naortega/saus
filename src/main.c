/*
 * Copyright (C) 2019 Ortega Froysa, Nicolás <nortega@themusicinnoise.net>
 * Author: Ortega Froysa, Nicolás <nortega@themusicinnoise.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "args.h"

#include <stdio.h>
#include <readline/readline.h>
#include <jack/jack.h>

int main(int argc, char *argv[]) {
	struct arguments arguments;
	arguments.verbose = 0;
	arguments.script_file = NULL;
	arguments.playlist_file = NULL;

	argp_parse(&argp, argc, argv, 0, 0, &arguments);
	return 0;
}
