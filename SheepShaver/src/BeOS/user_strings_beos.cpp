/*
 *  user_strings_beos.cpp - Localizable strings, BeOS specific strings
 *
 *  SheepShaver (C) 1997-2005 Christian Bauer and Marc Hellwig
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "sysdeps.h"
#include "user_strings.h"


// Platform-specific string definitions
user_string_def platform_strings[] = {
	// Common strings that have a platform-specific variant
	{STR_VOLUME_IS_MOUNTED_WARN, "The volume '%s' is mounted under BeOS. Basilisk II will try to unmount it."},
	{STR_EXTFS_CTRL, "BeOS Root"},
	{STR_EXTFS_NAME, "BeOS Directory Tree"},
	{STR_EXTFS_VOLUME_NAME, "BeOS"},

	// Purely platform-specific strings
	{STR_NO_SHEEP_DRIVER_ERR, "Cannot open /dev/sheep: %s (%08x). SheepShaver is not properly installed."},
	{STR_NO_RAM_AREA_ERR, "Not enough memory to create RAM area: %s (%08x)."},
	{STR_NO_ROM_AREA_ERR, "Not enough memory to create ROM area."},
	{STR_NO_SHEEP_MEM_AREA_ERR, "Not enough memory to create SheepShaver area."},
	{STR_SHEEP_UP_ERR, "Cannot allocate Low Memory Globals: %s (%08x)."},
	{STR_NO_NET_ADDON_WARN, "The SheepShaver net server add-on cannot be found. Ethernet will not be available."},
	{STR_NET_CONFIG_MODIFY_WARN, "To enable Ethernet networking for SheepShaver, your network configuration has to be modified and the network restarted. Do you want this to be done now (selecting \"Cancel\" will disable Ethernet under SheepShaver)?."},
	{STR_NET_ADDON_INIT_FAILED, "SheepShaver net server add-on found\nbut there seems to be no network hardware.\nPlease check your network preferences."},
	{STR_NET_ADDON_CLONE_FAILED, "Cloning of the network transfer area failed."},
	{STR_NO_SHEEP_MEM_AREA_ERR, "Cannot create SheepShaver Globals area: %s (%08x)."},
	{STR_NO_DR_CACHE_AREA_ERR, "Cannot create DR Cache area: %s (%08x)."},
	{STR_NO_DR_EMULATOR_AREA_ERR, "Cannot create DR Emulator area: %s (%08x)."},

	{-1, NULL}	// End marker
};


/*
 *  Fetch pointer to string, given the string number
 */

const char *GetString(int num)
{
	// First search for platform-specific string
	int i = 0;
	while (platform_strings[i].num >= 0) {
		if (platform_strings[i].num == num)
			return platform_strings[i].str;
		i++;
	}

	// Not found, search for common string
	i = 0;
	while (common_strings[i].num >= 0) {
		if (common_strings[i].num == num)
			return common_strings[i].str;
		i++;
	}
	return NULL;
}
