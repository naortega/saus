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

#include "processing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int process(jack_nframes_t nframes, void *arg) {
	if(!arg)
	{
		fprintf(stderr, "No script supplied");
		exit(1);
	}
	jack_default_audio_sample_t *in, *out;

	memcpy(out, in,
			sizeof(jack_default_audio_sample_t) *nframes);

	return 0;
}
