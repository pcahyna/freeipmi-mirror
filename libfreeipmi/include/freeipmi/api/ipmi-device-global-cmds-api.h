/*
   Copyright (C) 2003-2008 FreeIPMI Core Team

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
*/

#ifndef _IPMI_DEVICE_GLOBAL_CMDS_API_H
#define	_IPMI_DEVICE_GLOBAL_CMDS_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include <freeipmi/api/ipmi-api.h>
#include <freeipmi/fiid/fiid.h>

int8_t ipmi_cmd_get_device_id (ipmi_ctx_t ctx, fiid_obj_t obj_cmd_rs);

int8_t ipmi_cmd_cold_reset (ipmi_ctx_t ctx, fiid_obj_t obj_cmd_rs);

int8_t ipmi_cmd_warm_reset (ipmi_ctx_t ctx, fiid_obj_t obj_cmd_rs);

int8_t ipmi_cmd_get_device_guid (ipmi_ctx_t ctx, fiid_obj_t obj_cmd_rs);


#ifdef __cplusplus
}
#endif

#endif /* _IPMI_DEVICE_GLOBAL_CMDS_API_H */
