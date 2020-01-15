/*
 * Copyright (C) 2003-2015 FreeIPMI Core Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef IPMI_SENSOR_NUMBERS_OEM_INTEL_SPEC_H
#define IPMI_SENSOR_NUMBERS_OEM_INTEL_SPEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <freeipmi/spec/oem/ipmi-sensor-numbers-oem-intel-s5500wb-spec.h>
#include <freeipmi/spec/oem/ipmi-sensor-numbers-oem-intel-quanta-qssc-s4r-spec.h>
#include <freeipmi/spec/oem/ipmi-sensor-numbers-oem-intel-s2600jf-spec.h>
#include <freeipmi/spec/oem/ipmi-sensor-numbers-oem-intel-s2600wp-spec.h>
#include <freeipmi/spec/oem/ipmi-sensor-numbers-oem-intel-windmill-spec.h>

/* Intel S2600KP
 * Intel S2600WT2
 * Intel S2600WTT
 * Intel S2600GZ
 */

/* BMC owned sensors (GID = 0020h) */
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_UNIT_STATUS                                   0x01
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_UNIT_REDUNDANCY                               0x02
#define IPMI_SENSOR_NUMBER_OEM_INTEL_IPMI_WATCHDOG                                       0x03
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PHYSICAL_SECURITY                                   0x04
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FP_INTERRUPT                                        0x05
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SMI_TIMEOUT                                         0x06
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SYSTEM_EVENT_LOG                                    0x07
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SYSTEM_EVENT                                        0x08
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BUTTON_SENSOR                                       0x09
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BMC_WATCHDOG                                        0x0A
#define IPMI_SENSOR_NUMBER_OEM_INTEL_VOLTAGE_REGULATOR_WATCHDOG                          0x0B
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FAN_REDUNDANCY                                      0x0C
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SSB_THERMAL_TRIP                                    0x0D
#define IPMI_SENSOR_NUMBER_OEM_INTEL_IO_MODULE_PRESENCE                                  0x0E
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SAS_MODULE_PRESENCE                                 0x0F
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BMC_FIRMWARE_HEALTH                                 0x10
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SYSTEM_AIRFLOW                                      0x11
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FIRMWARE_UPDATE_STATUS                              0x12
#define IPMI_SENSOR_NUMBER_OEM_INTEL_IO_MODULE2_PRESENCE                                 0x13
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE5                              0x14
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE6                              0x15
#define IPMI_SENSOR_NUMBER_OEM_INTEL_IO_MODULE2_TEMPERATURE                              0x16
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PCI_RISER3_TEMPERATURE                              0x17
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PCI_RISER4_TEMPERATURE                              0x18
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE1                              0x20
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FRONT_PANEL_TEMPERATURE                             0x21
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SSB_TEMPERATURE                                     0x22
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE2                              0x23
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE3                              0x24
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE4                              0x25
#define IPMI_SENSOR_NUMBER_OEM_INTEL_IO_MODULE_TEMPERATURE                               0x26
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PCI_RISER1_TEMPERATURE                              0x27
#define IPMI_SENSOR_NUMBER_OEM_INTEL_IO_RISER_TEMPERATURE                                0x28
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HOT_SWAP_BACK_PLANE1_TEMPERATURE                    0x29
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HOT_SWAP_BACK_PLANE2_TEMPERATURE                    0x2A
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HOT_SWAP_BACK_PLANE3_TEMPERATURE                    0x2B
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PCI_RISER2_TEMPERATURE                              0x2C
#define IPMI_SENSOR_NUMBER_OEM_INTEL_SAS_MODULE_TEMPERATURE                              0x2D
#define IPMI_SENSOR_NUMBER_OEM_INTEL_EXIT_AIR_TEMPERATURE                                0x2E
#define IPMI_SENSOR_NUMBER_OEM_INTEL_NETWORK_INTERFACE_CONTROLLER_TEMPERATURE            0x2F
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FAN_TACHOMETER_SENSORS_MIN                          0x30
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FAN_TACHOMETER_SENSORS_MAX                          0x3F
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FAN_PRESENT_SENSORS_MIN                             0x40
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FAN_PRESENT_SENSORS_MAX                             0x4F
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY1_STATUS                                0x50
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY2_STATUS                                0x51
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY1_AC_POWER_INPUT                        0x54
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY2_AC_POWER_INPUT                        0x55
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY1_12V_PERCENT_OF_MAXIMUM_CURRENT_OUTPUT 0x58
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY2_12V_PERCENT_OF_MAXIMUM_CURRENT_OUTPUT 0x59
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY1_TEMPERATURE                           0x5C
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY2_TEMPERATURE                           0x5D
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE15                                   0x60
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE16                                   0x61
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE17                                   0x62
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE18                                   0x63
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE19                                   0x64
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE20                                   0x65
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE21                                   0x66
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE22                                   0x67
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE23                                   0x68
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HOT_SWAP_CONTROLLER1_STATUS                         0x69
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HOT_SWAP_CONTROLLER2_STATUS                         0x6A
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HOT_SWAP_CONTROLLER3_STATUS                         0x6B
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR1_STATUS                                   0x70
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR2_STATUS                                   0x71
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR3_STATUS                                   0x72
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR4_STATUS                                   0x73
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR1_THERMAL_MARGIN                           0x74
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR2_THERMAL_MARGIN                           0x75
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR3_THERMAL_MARGIN                           0x76
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR4_THERMAL_MARGIN                           0x77
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR1_THERMAL_CONTROL_PERCENT                  0x78
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR2_THERMAL_CONTROL_PERCENT                  0x79
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR3_THERMAL_CONTROL_PERCENT                  0x7A
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR4_THERMAL_CONTROL_PERCENT                  0x7B
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR_ERR2_TIMEOUT                              0x7C
#define IPMI_SENSOR_NUMBER_OEM_INTEL_IERR_RECOVERY_DUMP_INFO                             0x7D
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTERNAL_ERROR                                      0x80
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR_POPULATION_FAULT                          0x82
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR1_DTS_THERMAL_MARGIN                       0x83
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR2_DTS_THERMAL_MARGIN                       0x84
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR3_DTS_THERMAL_MARGIN                       0x85
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR4_DTS_THERMAL_MARGIN                       0x86
#define IPMI_SENSOR_NUMBER_OEM_INTEL_AUTO_CONFIG_STATUS                                  0x87
#define IPMI_SENSOR_NUMBER_OEM_INTEL_VRD_OVER_TEMPERATURE                                0x90
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY1_FAN_TACHOMETER1                       0xA0
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY1_FAN_TACHOMETER2                       0xA1
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_STATUS1                  0xA2
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_STATUS2                  0xA3
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY2_FAN_TACHOMETER1                       0xA4
#define IPMI_SENSOR_NUMBER_OEM_INTEL_POWER_SUPPLY2_FAN_TACHOMETER2                       0xA5
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_STATUS3                  0xA6
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_STATUS4                  0xA7
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR1_DIMM_AGGREGATE_THERMAL_MARGIN1           0xB0
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR1_DIMM_AGGREGATE_THERMAL_MARGIN2           0xB1
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR2_DIMM_AGGREGATE_THERMAL_MARGIN1           0xB2
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR2_DIMM_AGGREGATE_THERMAL_MARGIN2           0xB3
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR3_DIMM_AGGREGATE_THERMAL_MARGIN1           0xB4
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR3_DIMM_AGGREGATE_THERMAL_MARGIN2           0xB5
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR4_DIMM_AGGREGATE_THERMAL_MARGIN1           0xB6
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR4_DIMM_AGGREGATE_THERMAL_MARGIN2           0xB7
#define IPMI_SENSOR_NUMBER_OEM_INTEL_NODE_AUTO_SHUTDOWN_SENSOR                           0xB8
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FAN_TACHOMETER_SENSORS2_MIN                         0xBA
#define IPMI_SENSOR_NUMBER_OEM_INTEL_FAN_TACHOMETER_SENSORS2_MAX                         0xBF
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR1_THERMAL_TRIP                             0xC0
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR2_THERMAL_TRIP                             0xC1
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR3_THERMAL_TRIP                             0xC2
#define IPMI_SENSOR_NUMBER_OEM_INTEL_PROCESSOR4_THERMAL_TRIP                             0xC3
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_THERMAL_MARGIN1          0xC4
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_THERMAL_MARGIN2          0xC5
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_THERMAL_MARGIN3          0xC6
#define IPMI_SENSOR_NUMBER_OEM_INTEL_INTEL_XEON_PHI_COPROCESSOR_THERMAL_MARGIN4          0xC7
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN1                0xC8
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN2                0xC9
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN3                0xCA
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN4                0xCB
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN5                0xCC
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN6                0xCD
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN7                0xCE
#define IPMI_SENSOR_NUMBER_OEM_INTEL_GLOBAL_AGGREGATE_TEMPERATURE_MARGIN8                0xCF
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_12V                                       0xD0
#define IPMI_SENSOR_NUMBER_OEM_INTEL_VOLTAGE_FAULT                                       0xD1
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE7                              0xD5
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_TEMPERATURE8                              0xD6
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BASEBOARD_CMOS_BATTERY                              0xDE
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HOT_SWAP_BACKPLANE4_TEMPERATURE                     0xE0
#define IPMI_SENSOR_NUMBER_OEM_INTEL_REAR_HARD_DISK_DRIVE0_STATUS                        0xE2
#define IPMI_SENSOR_NUMBER_OEM_INTEL_REAR_HARD_DISK_DRIVE1_STATUS                        0xE3
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE0_STATUS                             0xF0
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE1_STATUS                             0xF1
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE2_STATUS                             0xF2
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE3_STATUS                             0xF3
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE4_STATUS                             0xF4
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE5_STATUS                             0xF5
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE6_STATUS                             0xF6
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE7_STATUS                             0xF7
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE8_STATUS                             0xF8
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE9_STATUS                             0xF9
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE10_STATUS                            0xFA
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE11_STATUS                            0xFB
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE12_STATUS                            0xFC
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE13_STATUS                            0xFD
#define IPMI_SENSOR_NUMBER_OEM_INTEL_HARD_DISK_DRIVE14_STATUS                            0xFE

/* BIOS POST owned sensors (GID = 0001h) */
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_POST_MEMORY_RAS_CONFIGURATION_STATUS               0x02
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_POST_POST_ERROR                                    0x06
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_POST_INTEL_QUICK_PATH_INTERFACE_LINK_WIDTH_REDUCED 0x09
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_POST_MEMORY_RAS_MODE_SELECT                        0x12
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_POST_SYSTEM_EVENT                                  0x83

/* BIOS SMI Handler owned sensors (GID = 0033h) */
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_MIRRORING_REDUNDANCY_STATE                   0x01
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_MEMORY_ECC_ERROR                             0x02
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_LEGACY_PCI_ERROR                             0x03
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_PCI_EXPRESS_FATAL_ERROR                      0x04
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_PCI_EXPRESS_CORRECTABLE_ERROR                0x05
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_INTEL_QUICK_PATH_INTERFACE_CORRECTABLE_ERROR 0x06
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_INTEL_QUICK_PATH_INTERFACE_FATAL_ERROR       0x07
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_SPARING_REDUNDANCY_STATE                     0x11
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_MEMORY_PARITY_ERROR                          0x13
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_PCI_EXPRESS_FATAL_ERROR2                     0x14
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_BIOS_RECOVERY                                0x15
#define IPMI_SENSOR_NUMBER_OEM_INTEL_BIOS_SMI_INTEL_QUICKPATH_INTERFACE_FATAL_ERROR2       0x17

#ifdef __cplusplus
}
#endif

#endif /* IPMI_SENSOR_NUMBERS_OEM_INTEL_SPEC_H */
