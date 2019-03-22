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

#pragma once

#include <argp.h>

const char *argp_program_version = "SAUS v1.0";
const char *argp_program_bug_address = "<nortega@themusicinnoise.net>";

static char doc[] = "saus -- a command-line tool for real-time "
	"scripted audio filtering.";

static char args_doc[] = "[-v] -f FILE | -l FILE";

static struct argp_option options[] = {
	{ "verbose",   'v', 0,       0, "Make output verbose", 0 },
	{ "file",      'f', "FILE",  0, "Script file", 0 },
	{ "playlist",  'l', "FILE",  0, "Playlist of script files", 0 },
	{ 0 }
};

struct arguments {
	int verbose;
	char *script_file;
	char *playlist_file;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	struct arguments *arguments = state->input;

	switch(key)
	{
		case 'v':
			arguments->verbose = 1;
			break;
		case 'f':
			arguments->script_file = arg;
			break;
		case 'l':
			arguments->playlist_file = arg;
			break;
		/*case ARGP_KEY_ARG:
			if(state->arg_num > 2)
				argp_usage(state);
			break;
		case ARGP_KEY_END:
			if(state->arg_num < 1)
				argp_usage(state);
			break;*/
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };
