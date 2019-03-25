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
#include "processing.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <jack/jack.h>

jack_port_t *in_port;
jack_port_t *out_port;
jack_client_t *client;

void jack_shutdown(void *arg);

int main(int argc, char *argv[]) {
	struct arguments arguments;
	arguments.verbose = 0;
	arguments.script_file = NULL;
	arguments.playlist_file = NULL;

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	/*const char **ports;*/
	const char *client_name = "saus";
	const char *server_name = NULL;
	jack_options_t options = JackNullOption;
	jack_status_t status;

	client = jack_client_open(client_name, options, &status, server_name);
	if(!client)
	{
		fprintf(stderr, "jack_client_open() failed, "
				"status = 0x%2.0x\n", status);
		if(status & JackServerFailed)
		{
			fprintf(stderr, "Unable to connect to JACK server\n");
		}
		exit(1);
	}
	if(status & JackServerStarted)
	{
		fprintf(stderr, "JACK server started\n");
	}
	if(status & JackNameNotUnique)
	{
		client_name = jack_get_client_name(client);
		fprintf(stderr, "unique name `%s' assigned\n", client_name);
	}

	jack_set_process_callback(client, process, 0);
	jack_on_shutdown(client, jack_shutdown, "Shut down by JACK server");

	in_port = jack_port_register(client, "input",
			JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
	out_port = jack_port_register(client, "output",
			JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

	if(!in_port || !out_port)
	{
		fprintf(stderr, "No more JACK ports available\n");
		exit(1);
	}

	if(jack_activate(client))
	{
		fprintf(stderr, "Cannot activate JACK client\n");
		exit(1);
	}

	// TODO: add main loop here

	jack_client_close(client);

	return 0;
}

void jack_shutdown(void *arg) {
	fprintf(stderr, "%s", (char*)arg);
	exit(1);
}
