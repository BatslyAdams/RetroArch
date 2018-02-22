/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2017 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include "hid_device_driver.h"

struct ds4_instance {
  hid_driver_t *driver;
  void *handle;
};

static void *ds4_init(hid_driver_instance_t *hid_driver)
{
  return NULL;
}

static void ds4_free(void *data)
{
  struct ds4_instance *instance = (struct ds4_instance *)data;
  if(!instance)
    return;

  free(instance);
}

static void ds4_handle_packet(void *data, uint8_t *buffer, size_t size)
{
}

static bool ds4_detect(uint16_t vendor_id, uint16_t product_id)
{
  return vendor_id == VID_SONY && product_id == PID_SONY_DS4;
}

hid_device_t ds4_hid_device = {
  ds4_init,
  ds4_free,
  ds4_handle_packet,
  ds4_detect,
  "Sony DualShock 4"
};
