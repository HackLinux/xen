/*
 * HVM SeaBIOS support.
 *
 * Leendert van Doorn, leendert@watson.ibm.com
 * Copyright (c) 2005, International Business Machines Corporation.
 * Copyright (c) 2006, Keir Fraser, XenSource Inc.
 * Copyright (c) 2011, Citrix Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 */

#include "config.h"
#include "config-seabios.h"

#include "util.h"

#define ROM_INCLUDE_SEABIOS
#include "roms.inc"

//BUILD_BUG_ON(sizeof(seabios) > (0x00100000U - SEABIOS_PHYSICAL_ADDRESS));

struct bios_config seabios_config = {
	.name = "SeaBIOS",

    .image = seabios,
    .image_size = sizeof(seabios),

    .bios_address = SEABIOS_PHYSICAL_ADDRESS,

    .load_roms = 0,

    .optionrom_start = 0,
    .optionrom_end = 0,

    .bios_info_setup = NULL,
    .bios_info_finish = NULL,

    .bios_relocate = NULL,

    .vm86_setup = NULL,
    .e820_setup = NULL,

    .acpi_build_tables = NULL,
    .create_mp_tables = NULL,
    .create_smbios_tables = NULL,
};

/*
 * Local variables:
 * mode: C
 * c-set-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
