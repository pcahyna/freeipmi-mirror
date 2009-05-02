/*
  Copyright (C) 2008-2009 FreeIPMI Core Team

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA
*/

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#if STDC_HEADERS
#include <string.h>
#endif /* STDC_HEADERS */
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else /* !TIME_WITH_SYS_TIME */
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else /* !HAVE_SYS_TIME_H */
#include <time.h>
#endif /* !HAVE_SYS_TIME_H */
#endif /* !TIME_WITH_SYS_TIME */
#include <assert.h>
#include <errno.h>

#include <freeipmi/freeipmi.h>

#include "bmc-device.h"
#include "bmc-device-argp.h"

#include "freeipmi-portability.h"
#include "pstdout.h"
#include "tool-common.h"
#include "tool-cmdline-common.h"
#include "tool-hostrange-common.h"

static int
cold_reset (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_cold_reset_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_cold_reset (state_data->ipmi_ctx, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_cold_reset: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
warm_reset (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_warm_reset_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_warm_reset (state_data->ipmi_ctx, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_warm_reset: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_self_test_results (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_self_test_results_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_self_test_results (state_data->ipmi_ctx, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_self_test_results: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "self_test_result",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'self_test_result': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  pstdout_printf (state_data->pstate,
                  "Self Test Result: ");
  if (val == IPMI_SELF_TEST_RESULT_NO_ERROR)
    pstdout_printf (state_data->pstate,
                    "No Error\n");
  else if (val == IPMI_SELF_TEST_RESULT_SELF_TEST_FUNCTION_NOT_IMPLEMENTED_IN_THIS_CONTROLLER)
    pstdout_printf (state_data->pstate,
                    "Self Test function not implemented in this controller.\n");
  else if (val == IPMI_SELF_TEST_RESULT_CORRUPTED_OR_INACCESSIBLE_DATA_OR_DEVICES)
    pstdout_printf (state_data->pstate,
                    "Corrupted or inaccessible data or devices\n");
  else if (val == IPMI_SELF_TEST_RESULT_FATAL_HARDWARE_ERROR)
    pstdout_printf (state_data->pstate,
                    "Fatal hardware error (system should consider BMC inoperative).  Controller hardware may need to be repaired or replaced.\n");
  else
    pstdout_printf (state_data->pstate,
                    "Device-specific error: %Xh\n",
                    val);

  if (val == IPMI_SELF_TEST_RESULT_CORRUPTED_OR_INACCESSIBLE_DATA_OR_DEVICES)
    {
      if (FIID_OBJ_GET (obj_cmd_rs,
                        "controller_operation_firmware_corrupted",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'controller_operation_firmware_corrupted': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }

      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [Controller operation firmware corrupted]\n");

      if (FIID_OBJ_GET (obj_cmd_rs,
                        "controller_update_boot_block_firmware_corrupted",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'controller_update_boot_block_firmware_corrupted': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }
      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [Controller update 'boot block' firmware corrupted]\n");

      if (FIID_OBJ_GET (obj_cmd_rs,
                        "internal_use_area_of_bmc_fru_corrupted",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'internal_use_area_of_bmc_fru_corrupted': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }

      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [Internal Use Area of BMC FRU corrupted]\n");

      if (FIID_OBJ_GET (obj_cmd_rs,
                        "sdr_repository_empty",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'sdr_repository_empty': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }

      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [SDR Repository empty]\n");

      if (FIID_OBJ_GET (obj_cmd_rs,
                        "ipmb_signal_lines_do_not_respond",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'ipmb_signal_lines_do_not_respond': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }

      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [IPMB signal lines do not respond]\n");

      if (FIID_OBJ_GET (obj_cmd_rs,
                        "cannot_access_bmc_fru_device",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'cannot_access_bmc_fru_device': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }

      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [Cannot access BMC FRU device]\n");

      if (FIID_OBJ_GET (obj_cmd_rs,
                        "cannot_access_sdr_repository",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'cannot_access_sdr_repository': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }

      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [Cannot access SDR Repository]\n");

      if (FIID_OBJ_GET (obj_cmd_rs,
                        "cannot_access_sel_device",
                        &val) < 0)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "fiid_obj_get: 'cannot_access_sel_device': %s\n",
                           fiid_obj_errormsg (obj_cmd_rs));
          goto cleanup;
        }

      if (val)
        pstdout_printf (state_data->pstate,
                        "                  [Cannot access SEL device]\n");

    }

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_acpi_power_state (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint8_t system_power_state_enumeration;
  uint8_t device_power_state_enumeration;
  uint64_t val;
  char *statestr = NULL;
  char statestrbuf[1024];
  char *verbosestr = NULL;
  char verbosestrbuf[1024];
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_acpi_power_state_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_acpi_power_state (state_data->ipmi_ctx, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_acpi_power_state: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "system_power_state_enumeration",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'system_power_state_enumeration': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  system_power_state_enumeration = val;

  switch (system_power_state_enumeration)
    {
    case IPMI_ACPI_SYSTEM_POWER_STATE_S0_G0:
      statestr = "S0/G0";
      verbosestr = "working";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_S1:
      statestr = "S1";
      verbosestr = "hardware context maintained, typically equates to processor/chip set clocks stopped";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_S2:
      statestr = "S2";
      verbosestr = "typically equates to stopped clocks with processor/cache context lost";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_S3:
      statestr = "S3";
      verbosestr = "typically equates to \"suspend-to-RAM\"";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_S4:
      statestr = "S4";
      verbosestr = "typically equates to \"suspend-to-disk\"";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_S5_G2:
      statestr = "S5/G2";
      verbosestr = "soft off";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_S4_S5:
      statestr = "S4/S5";
      verbosestr = "soft off, cannot differentiate between S4 and S5";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_G3:
      statestr = "G3";
      verbosestr = "mechanical off";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_SLEEPING:
      statestr = "SLEEPING";
      verbosestr = "sleeping - cannot differentiate between S1-S3";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_G1_SLEEPING:
      statestr = "G1 SLEEPING";
      verbosestr = "sleeping - cannot differentiate between S1-S4";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_OVERRIDE:
      statestr = "OVERRIDE";
      verbosestr = "S5 entered by override";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_LEGACY_ON:
      statestr = "LEGACY_ON";
      /* achu: specification text uses singular "system".  I substitute in correct english. */
      verbosestr = "Legacy On (indicates On for systems that don't support ACPI or have ACPI capabilities disabled:";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_LEGACY_OFF:
      statestr = "LEGACY_OFF";
      verbosestr = "Legacy Soft-Off";
      break;
    case IPMI_ACPI_SYSTEM_POWER_STATE_UNKNOWN:
      statestr = "UNKNOWN";
      verbosestr = "power state has not been initialized, or device lost track of power state";
      break;
    default:
      snprintf (statestrbuf, 1024, "UNSPECIFIED");
      statestr = statestrbuf;
      snprintf (verbosestrbuf, 1024, "%Xh", system_power_state_enumeration);
      verbosestr = verbosestrbuf;
      break;
    }

  if (state_data->prog_data->args->verbose && verbosestr)
    pstdout_printf (state_data->pstate,
                    "ACPI System Power State: %s: %s\n",
                    statestr,
                    verbosestr);
  else
    pstdout_printf (state_data->pstate,
                    "ACPI System Power State: %s\n",
                    statestr);

  statestr = NULL;
  verbosestr = NULL;

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "device_power_state_enumeration",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'device_power_state_enumeration': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  device_power_state_enumeration = val;

  switch (device_power_state_enumeration)
    {
    case IPMI_ACPI_DEVICE_POWER_STATE_D0:
      statestr = "D0";
      break;
    case IPMI_ACPI_DEVICE_POWER_STATE_D1:
      statestr = "D1";
      break;
    case IPMI_ACPI_DEVICE_POWER_STATE_D2:
      statestr = "D2";
      break;
    case IPMI_ACPI_DEVICE_POWER_STATE_D3:
      statestr = "D3";
      break;
    case IPMI_ACPI_DEVICE_POWER_STATE_UNKNOWN:
      statestr = "UNKNOWN";
      verbosestr = "power state has not been initialized, or device lost track of power state";
      break;
    default:
      snprintf (statestrbuf, 1024, "UNSPECIFIED");
      statestr = statestrbuf;
      snprintf (verbosestrbuf, 1024, "%Xh", device_power_state_enumeration);
      verbosestr = verbosestrbuf;
      break;
    }

  if (state_data->prog_data->args->verbose && verbosestr)
    pstdout_printf (state_data->pstate,
                    "ACPI Device Power State: %s: %s\n",
                    statestr,
                    verbosestr);
  else
    pstdout_printf (state_data->pstate,
                    "ACPI Device Power State: %s\n",
                    statestr);

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
set_acpi_power_state (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint8_t system_power_state;
  uint8_t device_power_state;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_set_acpi_power_state_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  system_power_state = state_data->prog_data->args->set_acpi_power_state_args.system_power_state;
  device_power_state = state_data->prog_data->args->set_acpi_power_state_args.device_power_state;

  if (ipmi_cmd_set_acpi_power_state (state_data->ipmi_ctx,
                                     system_power_state,
                                     (system_power_state == IPMI_ACPI_SYSTEM_POWER_STATE_NO_CHANGE) ? IPMI_ACPI_SET_SYSTEM_POWER_STATE_DONT_SET_SYSTEM_POWER_STATE : IPMI_ACPI_SET_SYSTEM_POWER_STATE_SET_SYSTEM_POWER_STATE,
                                     device_power_state,
                                     (device_power_state == IPMI_ACPI_DEVICE_POWER_STATE_NO_CHANGE) ? IPMI_ACPI_SET_DEVICE_POWER_STATE_DONT_SET_DEVICE_POWER_STATE : IPMI_ACPI_SET_DEVICE_POWER_STATE_SET_DEVICE_POWER_STATE,
                                     obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_set_acpi_power_state: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_lan_statistics (bmc_device_state_data_t *state_data)
{
  uint16_t ip_packets_received, received_ip_header_errors, received_ip_address_errors;
  uint16_t fragmented_ip_packets_received, ip_packets_transmitted, udp_packets_received;
  uint16_t valid_rmcp_packets_received, udp_proxy_packets_received, udp_proxy_packets_dropped;
  fiid_obj_t obj_cmd_rs = NULL;
  uint8_t lan_channel_number;
  uint64_t val;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_ip_udp_rmcp_statistics_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_get_channel_number (state_data->ipmi_ctx,
                               IPMI_CHANNEL_MEDIUM_TYPE_LAN_802_3,
                               &lan_channel_number) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_get_channel_number: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (ipmi_cmd_get_ip_udp_rmcp_statistics (state_data->ipmi_ctx,
                                           lan_channel_number,
                                           IPMI_DONT_CLEAR_ALL_STATISTICS,
                                           obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_ip_udp_rmcp_statistics: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "ip_packets_received",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'ip_packets_received': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  ip_packets_received = val;

  pstdout_printf (state_data->pstate,
                  "IP Packets Received: %u\n",
                  ip_packets_received);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "received_ip_header_errors",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'received_ip_header_errors': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  received_ip_header_errors = val;

  pstdout_printf (state_data->pstate,
                  "Received IP Header Errors: %u\n",
                  received_ip_header_errors);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "received_ip_address_errors",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'received_ip_address_errors': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  received_ip_address_errors = val;

  pstdout_printf (state_data->pstate,
                  "Received IP Address Errors: %u\n",
                  received_ip_address_errors);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "fragmented_ip_packets_received",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'fragmented_ip_packets_received': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  fragmented_ip_packets_received = val;

  pstdout_printf (state_data->pstate,
                  "Fragmented IP Packets Received: %u\n",
                  fragmented_ip_packets_received);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "ip_packets_transmitted",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'ip_packets_transmitted': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  ip_packets_transmitted = val;

  pstdout_printf (state_data->pstate,
                  "IP Packets Transmitted: %u\n",
                  ip_packets_transmitted);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "udp_packets_received",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'udp_packets_received': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  udp_packets_received = val;

  pstdout_printf (state_data->pstate,
                  "UDP Packets Received: %u\n",
                  udp_packets_received);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "valid_rmcp_packets_received",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'valid_rmcp_packets_received': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  valid_rmcp_packets_received = val;

  pstdout_printf (state_data->pstate,
                  "Valid RMCP Packets Received: %u\n",
                  valid_rmcp_packets_received);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "udp_proxy_packets_received",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'udp_proxy_packets_received': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  udp_proxy_packets_received = val;
  
  pstdout_printf (state_data->pstate,
                  "UDP Proxy Packets Received: %u\n",
                  udp_proxy_packets_received);

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "udp_proxy_packets_dropped",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'udp_proxy_packets_dropped': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  udp_proxy_packets_dropped = val;

  pstdout_printf (state_data->pstate,
                  "UDP Proxy Packets Dropped: %u\n",
                  udp_proxy_packets_dropped);

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
clear_lan_statistics (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint8_t lan_channel_number;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_ip_udp_rmcp_statistics_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_get_channel_number (state_data->ipmi_ctx,
                               IPMI_CHANNEL_MEDIUM_TYPE_LAN_802_3,
                               &lan_channel_number) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_get_channel_number: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (ipmi_cmd_get_ip_udp_rmcp_statistics (state_data->ipmi_ctx,
                                           lan_channel_number,
                                           IPMI_CLEAR_ALL_STATISTICS,
                                           obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_ip_udp_rmcp_statistics: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_sdr_repository_time (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  char str[512];
  int rv = -1;
  time_t t;
  struct tm tm;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_sdr_repository_time_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_sdr_repository_time (state_data->ipmi_ctx, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_sdr_repository_time: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs, "time", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'time': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  t = val;
  localtime_r (&t, &tm);
  strftime (str, sizeof (str), "%m/%d/%Y - %H:%M:%S", &tm);
  pstdout_printf (state_data->pstate,
                  "SDR Repository Time: %s\n",
                  str);
  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
set_sdr_repository_time (bmc_device_state_data_t *state_data)
{
  struct bmc_device_arguments *args;
  fiid_obj_t obj_cmd_rs = NULL;
  int rv = -1;
  time_t t;
  struct tm tm;

  assert (state_data);

  args = state_data->prog_data->args;

  if (!strcasecmp (args->set_sdr_repository_time_arg, "now"))
    t = time (NULL);
  else
    {
      if (!strptime (args->set_sdr_repository_time_arg, "%m/%d/%Y - %H:%M:%S", &tm))
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "Invalid time specification '%s'.\n",
                           args->set_sdr_repository_time_arg);
          goto cleanup;
        }
      if ((t = mktime (&tm)) == (time_t)-1)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "Time specification '%s' cannot be represented.\n",
                           args->set_sdr_repository_time_arg);
          goto cleanup;
        }
    }

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_set_sdr_repository_time_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_set_sdr_repository_time (state_data->ipmi_ctx, t, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_set_sdr_repository_time: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_sel_time (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  char str[512];
  int rv = -1;
  time_t t;
  struct tm tm;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_sel_time_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_sel_time (state_data->ipmi_ctx, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_sel_time: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs, "time", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'time': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  t = val;
  localtime_r (&t, &tm);
  strftime (str, sizeof (str), "%m/%d/%Y - %H:%M:%S", &tm);
  pstdout_printf (state_data->pstate,
                  "SEL Time: %s\n",
                  str);
  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
set_sel_time (bmc_device_state_data_t *state_data)
{
  struct bmc_device_arguments *args;
  fiid_obj_t obj_cmd_rs = NULL;
  int rv = -1;
  time_t t;
  struct tm tm;

  assert (state_data);

  args = state_data->prog_data->args;

  if (!strcasecmp (args->set_sel_time_arg, "now"))
    t = time (NULL);
  else
    {
      if (!strptime (args->set_sel_time_arg, "%m/%d/%Y - %H:%M:%S", &tm))
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "Invalid time specification '%s'.\n",
                           args->set_sel_time_arg);
          goto cleanup;
        }
      if ((t = mktime (&tm)) == (time_t)-1)
        {
          pstdout_fprintf (state_data->pstate,
                           stderr,
                           "Time specification '%s' cannot be represented.\n",
                           args->set_sel_time_arg);
          goto cleanup;
        }
    }

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_set_sel_time_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_set_sel_time (state_data->ipmi_ctx, t, obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_set_sel_time: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_mca_auxiliary_log_status (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  fiid_obj_t mca_obj_cmd_rs = NULL;
  uint8_t log_type;
  uint32_t mca_log_entry_count;
  uint64_t val;
  char str[512];
  int rv = -1;
  time_t t;
  struct tm tm;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_auxiliary_log_status_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_auxiliary_log_status (state_data->ipmi_ctx,
                                         IPMI_AUXILIARY_LOG_TYPE_MCA,
                                         obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_auxiliary_log_status: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs,
                    "log_type",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'log_type': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  log_type = val;
  
  if (log_type != IPMI_AUXILIARY_LOG_TYPE_MCA)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_auxiliary_log_status: invalid log type returned: %Xh\n",
                       log_type);
      goto cleanup;
    }

  if (!(mca_obj_cmd_rs = fiid_obj_copy (obj_cmd_rs, tmpl_cmd_get_auxiliary_log_status_mca_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_copy: %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  if (FIID_OBJ_GET (mca_obj_cmd_rs,
                    "timestamp",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'timestamp': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  t = val;
  localtime_r (&t, &tm);
  strftime (str, sizeof (str), "%m/%d/%Y - %H:%M:%S", &tm);
  pstdout_printf (state_data->pstate,
                  "Last Entry Added to MCA Log: %s\n",
                  str);

  if (FIID_OBJ_GET (mca_obj_cmd_rs,
                    "mca_log_entry_count",
                    &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'mca_log_entry_count': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  mca_log_entry_count = val;
  
  pstdout_printf (state_data->pstate,
                  "Number of entries in MCA log: %u\n",
                  mca_log_entry_count);

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  fiid_obj_destroy (mca_obj_cmd_rs);
  return (rv);
}

static int
get_ssif_interface_capabilities (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint8_t ssif_version;
  uint8_t pec_support;
  uint8_t transaction_support;
  uint8_t input_message_size;
  uint8_t output_message_size;
  uint64_t val;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_system_interface_capabilities_ssif_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_system_interface_capabilities_ssif (state_data->ipmi_ctx,
                                                       obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_system_interface_capabilities_ssif: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs, "ssif_version", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'ssif_version': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  ssif_version = val;

  /* achu: for some stupid reason 000b == "version 1" */
  if (ssif_version == IPMI_SSIF_SYSTEM_INTERFACE_VERSION_1)
    pstdout_printf (state_data->pstate,
                    "SSIF Version:                     %Xh (version 1)\n", ssif_version);
  else
    pstdout_printf (state_data->pstate,
                    "SSIF Version:                     %Xh\n", ssif_version);

  if (FIID_OBJ_GET (obj_cmd_rs, "pec_support", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'pec_support': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  pec_support = val;

  pstdout_printf (state_data->pstate,
                  "SSIF PEC Support:                 ");

  switch (pec_support)
    {
    case IPMI_SSIF_SYSTEM_INTERFACE_IMPLEMENTS_PEC:
      pstdout_printf (state_data->pstate, "Yes\n");
      break;
    case IPMI_SSIF_SYSTEM_INTERFACE_DOES_NOT_SUPPORT_PEC:
      pstdout_printf (state_data->pstate, "No\n");
      break;
    default:
      pstdout_printf (state_data->pstate, "Unknown\n");
      break;
    }

  if (FIID_OBJ_GET (obj_cmd_rs, "transaction_support", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'transaction_support': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  transaction_support = val;

  pstdout_printf (state_data->pstate,
                  "SSIF Transaction Support:         ");
  switch (transaction_support)
    {
    case IPMI_SSIF_SYSTEM_INTERFACE_TRANSACTION_SUPPORT_SINGLE_PART_READS_WRITES_SUPPORTED:
      pstdout_printf (state_data->pstate, "Only single-part reads/writes supported.\n");
      break;
    case IPMI_SSIF_SYSTEM_INTERFACE_TRANSACTION_SUPPORT_MULTI_PART_READS_WRITES_SUPPORTED_START_AND_END_ONLY:
      pstdout_printf (state_data->pstate, "multi-part reads/writes upported.  Start and End transactions only.\n");
      break;
    case IPMI_SSIF_SYSTEM_INTERFACE_TRANSACTION_SUPPORT_MULTI_PART_READS_WRITES_SUPPORTED_START_MIDDLE_END:
      pstdout_printf (state_data->pstate, "multi-part reads/writes upported.  Start, Middle, and End transactions supported.\n");
      break;
    default:
      pstdout_printf (state_data->pstate, "Unknown\n");
      break;
    }

  if (FIID_OBJ_GET (obj_cmd_rs, "input_message_size", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'input_message_size': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  input_message_size = val;

  pstdout_printf (state_data->pstate,
                  "SSIF Maximum Input Message Size:  %u bytes\n",
                  input_message_size);

  if (FIID_OBJ_GET (obj_cmd_rs, "output_message_size", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'output_message_size': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  output_message_size = val;

  pstdout_printf (state_data->pstate,
                  "SSIF Maximum Output Message Size: %u bytes\n",
                  output_message_size);

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_kcs_interface_capabilities (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint8_t system_interface_version;
  uint8_t input_maximum_message_size;
  uint64_t val;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_system_interface_capabilities_kcs_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_system_interface_capabilities_kcs (state_data->ipmi_ctx,
                                                      obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_system_interface_capabilities_kcs: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs, "system_interface_version", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'system_interface_version': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  system_interface_version = val;

  /* achu: for some stupid reason 000b == "version 1" */
  if (system_interface_version == IPMI_KCS_SYSTEM_INTERFACE_VERSION_1)
    pstdout_printf (state_data->pstate,
                    "KCS Version:                    %Xh (version 1)\n", system_interface_version);
  else
    pstdout_printf (state_data->pstate,
                    "KCS Version:                    %Xh\n", system_interface_version);

  if (FIID_OBJ_GET (obj_cmd_rs, "input_maximum_message_size", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'input_maximum_message_size': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }
  input_maximum_message_size = val;

  pstdout_printf (state_data->pstate,
                  "KCS Maximum Input Message Size: %u bytes\n",
                  input_maximum_message_size);

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
get_bt_interface_capabilities (bmc_device_state_data_t *state_data)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  int rv = -1;

  assert (state_data);

  if (!(obj_cmd_rs = fiid_obj_create (tmpl_cmd_get_bt_interface_capabilities_rs)))
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_create: %s\n",
                       strerror (errno));
      goto cleanup;
    }

  if (ipmi_cmd_get_bt_interface_capabilities (state_data->ipmi_ctx,
                                              obj_cmd_rs) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "ipmi_cmd_get_bt_interface_capabilities: %s\n",
                       ipmi_ctx_errormsg (state_data->ipmi_ctx));
      goto cleanup;
    }

  if (FIID_OBJ_GET (obj_cmd_rs, "number_of_outstanding_requests_supported", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'number_of_outstanding_requests_supported': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  pstdout_printf (state_data->pstate,
                  "BT Number of Outstanding Requests Supported: %u\n",
                  val);

  if (FIID_OBJ_GET (obj_cmd_rs, "input_buffer_size", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'input_buffer_size': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  pstdout_printf (state_data->pstate,
                  "BT Input Buffer Size:                        %u bytes\n",
                  val);

  if (FIID_OBJ_GET (obj_cmd_rs, "output_buffer_size", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'output_buffer_size': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  pstdout_printf (state_data->pstate,
                  "BT Output Buffer Size:                       %u bytes\n",
                  val);

  if (FIID_OBJ_GET (obj_cmd_rs, "bmc_request_to_response_time", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'bmc_request_to_response_time': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  pstdout_printf (state_data->pstate,
                  "BT Request to Response Time:                 %u seconds\n",
                  val);

  if (FIID_OBJ_GET (obj_cmd_rs, "recommended_retries", &val) < 0)
    {
      pstdout_fprintf (state_data->pstate,
                       stderr,
                       "fiid_obj_get: 'recommended_retries': %s\n",
                       fiid_obj_errormsg (obj_cmd_rs));
      goto cleanup;
    }

  pstdout_printf (state_data->pstate,
                  "BT Recommended Retries:                      %u\n",
                  val);

  rv = 0;
 cleanup:
  fiid_obj_destroy (obj_cmd_rs);
  return (rv);
}

static int
run_cmd_args (bmc_device_state_data_t *state_data)
{
  struct bmc_device_arguments *args;
  int rv = -1;

  assert (state_data);

  args = state_data->prog_data->args;

  if (args->cold_reset)
    return (cold_reset (state_data));

  if (args->warm_reset)
    return (warm_reset (state_data));

  if (args->get_self_test_results)
    return (get_self_test_results (state_data));

  if (args->get_acpi_power_state)
    return (get_acpi_power_state (state_data));

  if (args->set_acpi_power_state)
    return (set_acpi_power_state (state_data));

  if (args->get_lan_statistics)
    return (get_lan_statistics (state_data));

  if (args->clear_lan_statistics)
    return (clear_lan_statistics (state_data));

  if (args->get_sdr_repository_time)
    return (get_sdr_repository_time (state_data));

  if (args->set_sdr_repository_time)
    return (set_sdr_repository_time (state_data));

  if (args->get_sel_time)
    return (get_sel_time (state_data));

  if (args->set_sel_time)
    return (set_sel_time (state_data));

  if (args->get_mca_auxiliary_log_status)
    return (get_mca_auxiliary_log_status (state_data));

  if (args->get_ssif_interface_capabilities)
    return (get_ssif_interface_capabilities (state_data));

  if (args->get_kcs_interface_capabilities)
    return (get_kcs_interface_capabilities (state_data));

  if (args->get_bt_interface_capabilities)
    return (get_bt_interface_capabilities (state_data));

  rv = 0;
  return (rv);
}

static int
_bmc_device (pstdout_state_t pstate,
             const char *hostname,
             void *arg)
{
  bmc_device_state_data_t state_data;
  bmc_device_prog_data_t *prog_data;
  char errmsg[IPMI_OPEN_ERRMSGLEN];
  int exit_code = -1;

  prog_data = (bmc_device_prog_data_t *)arg;
  memset (&state_data, '\0', sizeof (bmc_device_state_data_t));

  state_data.prog_data = prog_data;
  state_data.pstate = pstate;

  if (!(state_data.ipmi_ctx = ipmi_open (prog_data->progname,
                                         hostname,
                                         &(prog_data->args->common),
                                         errmsg,
                                         IPMI_OPEN_ERRMSGLEN)))
    {
      pstdout_fprintf (pstate,
                       stderr,
                       "%s\n",
                       errmsg);
      exit_code = EXIT_FAILURE;
      goto cleanup;
    }

  if (run_cmd_args (&state_data) < 0)
    {
      exit_code = EXIT_FAILURE;
      goto cleanup;
    }

  exit_code = 0;
 cleanup:
  if (state_data.ipmi_ctx)
    {
      ipmi_ctx_close (state_data.ipmi_ctx);
      ipmi_ctx_destroy (state_data.ipmi_ctx);
    }
  return (exit_code);
}

int
main (int argc, char **argv)
{
  bmc_device_prog_data_t prog_data;
  struct bmc_device_arguments cmd_args;
  int exit_code;
  int rv;

  ipmi_disable_coredump ();

  memset (&prog_data, '\0', sizeof (bmc_device_prog_data_t));
  prog_data.progname = argv[0];
  bmc_device_argp_parse (argc, argv, &cmd_args);
  prog_data.args = &cmd_args;

  if (pstdout_setup (&(prog_data.args->common.hostname),
                     prog_data.args->hostrange.buffer_output,
                     prog_data.args->hostrange.consolidate_output,
                     prog_data.args->hostrange.fanout,
                     prog_data.args->hostrange.eliminate,
                     prog_data.args->hostrange.always_prefix) < 0)
    {
      exit_code = EXIT_FAILURE;
      goto cleanup;
    }

  if ((rv = pstdout_launch (prog_data.args->common.hostname,
                            _bmc_device,
                            &prog_data)) < 0)
    {
      fprintf (stderr,
               "pstdout_launch: %s\n",
               pstdout_strerror (pstdout_errnum));
      exit_code = EXIT_FAILURE;
      goto cleanup;
    }

  exit_code = rv;
 cleanup:
  return (exit_code);
}
