/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Configuration.h
 *
 * Basic settings such as:
 *
 * - Type of electronics
 * - Type of temperature sensor
 * - Printer geometry
 * - Endstop configuration
 * - LCD controller
 * - Extra features
 *
 * Advanced settings can be found in Configuration_adv.h
 */
#define CONFIGURATION_H_VERSION 02010205

// Uncomment next line and use EasyConfig.h file for an easy configuration of Anet ET series models
#define ET_EASY_CONFIG

//===========================================================================
//============================= Getting Started =============================
//===========================================================================

/**
 * Here are some useful links to help get your machine configured and calibrated:
 *
 * Example Configs:     https://github.com/MarlinFirmware/Configurations/branches/all
 *
 * Průša Calculator:    https://blog.prusa3d.com/calculator_3416/
 *
 * Calibration Guides:  https://reprap.org/wiki/Calibration
 *                      https://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 *                      https://web.archive.org/web/20220907014303/https://sites.google.com/site/repraplogphase/calibration-of-your-reprap
 *                      https://youtu.be/wAL9d7FgInk
 *                      https://teachingtechyt.github.io/calibration.html
 *
 * Calibration Objects: https://www.thingiverse.com/thing:5573
 *                      https://www.thingiverse.com/thing:1278865
 */

// @section info

// Author info of this build printed to the host during boot and M115
#define STRING_CONFIG_H_AUTHOR "(Santiis2010, ET5)" // Who made the changes.
//#define CUSTOM_VERSION_FILE Version.h // Path from the root directory (no quotes)

// @section machine

// Choose the name from boards.h that matches your setup
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_ANET_ET4
#endif

/**
 * Select the serial port on the board to use for communication with the host.
 * This allows the connection of wireless adapters (for instance) to non-default port pins.
 * Serial port -1 is the USB emulated serial port, if available.
 * Note: The first serial port (-1 or 0) will always be used by the Arduino bootloader.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT 1

/**
 * Serial Port Baud Rate
 * This is the default communication speed for all serial ports.
 * Set the baud rate defaults for additional serial ports below.
 *
 * 250000 works in most cases, but you might try a lower speed if
 * you commonly experience drop-outs during host printing.
 * You may try up to 1000000 to speed up SD file transfer.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

#define BAUD_RATE_GCODE     // Enable G-code M575 to set the baud rate

/**
 * Select a secondary serial port on the board to use for communication with the host.
 * Currently Ethernet (-2) is only supported on Teensy 4.1 boards.
 * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_2 -1
//#define BAUDRATE_2 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE

/**
 * Select a third serial port on the board to use for communication with the host.
 * Currently only supported for AVR, DUE, LPC1768/9 and STM32/STM32F1
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_3 1
//#define BAUDRATE_3 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE

// Enable the Bluetooth serial interface on AT90USB devices
//#define BLUETOOTH

// Name displayed in the LCD "Ready" message and Info menu
#define CUSTOM_MACHINE_NAME "Anet ET5 Pro"

// Printer's unique ID, used by some programs to differentiate between machines.
// Choose your own or use a service like https://www.uuidgenerator.net/version4
//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"

// @section stepper drivers

/**
 * Stepper Drivers
 */
#define X_DRIVER_TYPE  TMC2208_STANDALONE
#define Y_DRIVER_TYPE  TMC2208_STANDALONE
#define Z_DRIVER_TYPE  TMC2208_STANDALONE
#define E0_DRIVER_TYPE TMC2208_STANDALONE

// @section extruder

#define EXTRUDERS 1
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

//===========================================================================
//============================= Thermal Settings ============================
//===========================================================================

#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#define TEMP_SENSOR_PROBE 0
#define TEMP_SENSOR_CHAMBER 0
#define TEMP_SENSOR_COOLER 0
#define TEMP_SENSOR_BOARD 0
#define TEMP_SENSOR_SOC 0
#define TEMP_SENSOR_REDUNDANT 0

#define DUMMY_THERMISTOR_998_VALUE  25
#define DUMMY_THERMISTOR_999_VALUE 100

#if HAS_E_TEMP_SENSOR
  #define TEMP_RESIDENCY_TIME         10
  #define TEMP_WINDOW                  3
  #define TEMP_HYSTERESIS              5
#endif

#if TEMP_SENSOR_BED
  #define TEMP_BED_RESIDENCY_TIME     10
  #define TEMP_BED_WINDOW              3
  #define TEMP_BED_HYSTERESIS          5
#endif

#define HEATER_0_MINTEMP   5
#define BED_MINTEMP        5
#define HEATER_0_MAXTEMP 275
#define BED_MAXTEMP      100

#define HOTEND_OVERSHOOT 15
#define BED_OVERSHOOT    10

//===========================================================================
//============================= PID Settings ================================
//===========================================================================

#define PIDTEMP
#define PID_MAX  255
#define PID_K1     0.95
#if ENABLED(PIDTEMP)
  // ET4 Autotune PID results
  #define DEFAULT_Kp 24.17
  #define DEFAULT_Ki 1.97
  #define DEFAULT_Kd 73.96
#else
  #define BANG_MAX 255
#endif

#define MAX_BED_POWER 255
//#define PIDTEMPBED
#if ENABLED(PIDTEMPBED)
  #define DEFAULT_bedKp 102.91
  #define DEFAULT_bedKi 20.42
  #define DEFAULT_bedKd 345.78
#endif

#if ANY(PIDTEMP, PIDTEMPBED)
  #define PID_FUNCTIONAL_RANGE 10
  #define PID_EDIT_MENU
  #define PID_AUTOTUNE_MENU
#endif

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 350

#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

//===========================================================================
//============================= Mechanical Settings =========================
//===========================================================================

// Endstops
#define ENDSTOPPULLUPS

#define X_MIN_ENDSTOP_HIT_STATE LOW
#define Y_MIN_ENDSTOP_HIT_STATE LOW
#define Z_MIN_ENDSTOP_HIT_STATE LOW
#define X_MAX_ENDSTOP_HIT_STATE HIGH
#define Y_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MAX_ENDSTOP_HIT_STATE LOW
#define Z_MIN_PROBE_ENDSTOP_HIT_STATE LOW

// Movement
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMAX_PLUG

#define DEFAULT_AXIS_STEPS_PER_UNIT   { 78.60, 79.10, 389.00, 420.00 }
#define EDITABLE_STEPS_PER_UNIT
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 10, 35 }
#define DEFAULT_MAX_ACCELERATION      { 1500, 1200, 100, 5000 }
#define DEFAULT_ACCELERATION           700
#define DEFAULT_RETRACT_ACCELERATION  1000
#define DEFAULT_TRAVEL_ACCELERATION   1000

//#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3
#endif

// Aseguramos DEFAULT_EJERK siempre definido
#define DEFAULT_EJERK 5.0

#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.016
  #define JD_HANDLE_SMALL_SEGMENTS
#endif

#define S_CURVE_ACCELERATION

// Z Probe
// Force the use of the probe for Z-axis homing
#define USE_PROBE_FOR_Z_HOMING
#define FIX_MOUNTED_PROBE
#define NOZZLE_TO_PROBE_OFFSET { -22, -7, -0.52 }
#define PROBING_TOOL 0
#define PROBING_MARGIN 25
#define XY_PROBE_FEEDRATE (133*60)
#define Z_PROBE_FEEDRATE_FAST (8*60)
#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2)
#define MULTIPLE_PROBING 2
#define Z_CLEARANCE_DEPLOY_PROBE   10
#define Z_CLEARANCE_BETWEEN_PROBES  5
#define Z_CLEARANCE_MULTI_PROBE     5
#define Z_PROBE_ERROR_TOLERANCE     3
#define Z_PROBE_LOW_POINT          -2
#define PROBE_OFFSET_ZMIN -20
#define PROBE_OFFSET_ZMAX  20
#define Z_PROBE_OFFSET_RANGE_MIN PROBE_OFFSET_ZMIN
#define Z_PROBE_OFFSET_RANGE_MAX PROBE_OFFSET_ZMAX
//#define PROBE_MANUALLY
#define MANUAL_PROBE_START_Z 0.2

// Steppers
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

#define INVERT_X_DIR true
#define INVERT_Y_DIR false
#define INVERT_Z_DIR true

#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

// Compatibilidad (algunas macros antiguas usadas por módulos internos)
#define X_MIN_ENDSTOP_INVERTING (X_MIN_ENDSTOP_HIT_STATE == LOW)
#define Y_MIN_ENDSTOP_INVERTING (Y_MIN_ENDSTOP_HIT_STATE == LOW)
#define Z_MAX_ENDSTOP_INVERTING (Z_MAX_ENDSTOP_HIT_STATE == LOW)
#define Z_MIN_PROBE_ENDSTOP_INVERTING (Z_MIN_PROBE_ENDSTOP_HIT_STATE == LOW)
#define MINIMUM_PLANNER_SPEED 0.05f

// Homing
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR  -1
#define Z_SAFE_HOMING
#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT X_CENTER
  #define Z_SAFE_HOMING_Y_POINT Y_CENTER
#endif
#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (8*60) }
#define VALIDATE_HOMING_ENDSTOPS

// Geometry
#define X_BED_SIZE 300
#define Y_BED_SIZE 300
#define X_MIN_POS 0
#define Y_MIN_POS -15
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 400

// Software Endstops
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

//===========================================================================
//=============================== Runout Sensor ==============================
//===========================================================================

#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define FIL_RUNOUT_ENABLED_DEFAULT true   // Sensor habilitado al arrancar
  #define NUM_RUNOUT_SENSORS   1           // Solo E0
  #define FIL_RUNOUT_STATE     LOW         // ET4/ET5: microswitch NO -> LOW = sin filamento
  #define FIL_RUNOUT_PULLUP                // Pull-up interno para estabilidad
  //#define FIL_RUNOUT_PULLDOWN

  // Ejecutar al detectar runout
  #define FILAMENT_RUNOUT_SCRIPT "M600"    // Requiere ADVANCED_PAUSE_FEATURE en Configuration_adv.h

  // Si el sensor está lejos del hotend podés usar distancia de “cola”
  //#define FILAMENT_RUNOUT_DISTANCE_MM 25
#endif

//===========================================================================
//=============================== Bed Leveling ===============================
//===========================================================================

#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28

#if ANY(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
  //#define PROBE_Y_FIRST
#endif

#define ENABLE_LEVELING_FADE_HEIGHT
#if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
  #define DEFAULT_LEVELING_FADE_HEIGHT 10.0
#endif

#define SEGMENT_LEVELED_MOVES
#define LEVELED_SEGMENT_LENGTH 5.0

#define G26_MESH_VALIDATION
#if ENABLED(G26_MESH_VALIDATION)
  #define MESH_TEST_NOZZLE_SIZE    0.4
  #define MESH_TEST_LAYER_HEIGHT   0.2
  #define MESH_TEST_HOTEND_TEMP  205
  #define MESH_TEST_BED_TEMP      60
  #define G26_XY_FEEDRATE         20
  #define G26_XY_FEEDRATE_TRAVEL 100
  #define G26_RETRACT_MULTIPLIER   1.0
#endif

// LCD Bed Tramming helper
#define LCD_BED_TRAMMING
#if ENABLED(LCD_BED_TRAMMING)
  #define BED_TRAMMING_INSET_LFRB { 20, 20, 20, 20 }
  #define BED_TRAMMING_HEIGHT      0.0
  #define BED_TRAMMING_Z_HOP       6.0
  #define BED_TRAMMING_INCLUDE_CENTER
#endif

// EEPROM
#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT
#define EEPROM_BOOT_SILENT
#if ENABLED(EEPROM_SETTINGS)
  #define EEPROM_AUTO_INIT
#endif

// Host Keepalive
#define HOST_KEEPALIVE_FEATURE
#define DEFAULT_KEEPALIVE_INTERVAL 2
#define BUSY_WHILE_HEATING

// Preheats
#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     70
#define PREHEAT_1_TEMP_CHAMBER 35
#define PREHEAT_1_FAN_SPEED     0

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_TEMP_CHAMBER 35
#define PREHEAT_2_FAN_SPEED     0

// Nozzle Park & Clean
#define NOZZLE_PARK_FEATURE
#if ENABLED(NOZZLE_PARK_FEATURE)
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_MOVE          0
  #define NOZZLE_PARK_Z_RAISE_MIN   2
  #define NOZZLE_PARK_XY_FEEDRATE 100
  #define NOZZLE_PARK_Z_FEEDRATE    5
#endif

#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_PATTERN_LINE
  #define NOZZLE_CLEAN_PATTERN_ZIGZAG
  #define NOZZLE_CLEAN_PATTERN_CIRCLE

  #define NOZZLE_CLEAN_DEFAULT_PATTERN 0
  #define NOZZLE_CLEAN_STROKES 12
  #define NOZZLE_CLEAN_TRIANGLES 3   // <-- Déjalo SIEMPRE definido aquí

  // puntos de inicio/fin y círculo como ya los tenías...
  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT

  #define NOZZLE_CLEAN_GOBACK
  #define NOZZLE_CLEAN_MIN_TEMP 170
#endif
// Print Job Timer
#define PRINTJOB_TIMER_AUTOSTART

//-----------------------------------------------------------------------------
// LCD / SD / TFT
//-----------------------------------------------------------------------------
#define LCD_LANGUAGE es
#define DISPLAY_CHARSET_HD44780 WESTERN
#define SDSUPPORT
#define SD_CHECK_AND_RETRY

#define INDIVIDUAL_AXIS_HOMING_MENU

// TFT
#define ANET_ET5_TFT35
#define TFT_COLOR_UI
#if ENABLED(TFT_COLOR_UI)
  #define TFT_FONT NOTOSANS
  #define TFT_THEME ANET_BLACK
  #define COMPACT_MARLIN_BOOT_LOGO
#endif

#define TOUCH_SCREEN
#if ENABLED(TOUCH_SCREEN)
  #define BUTTON_DELAY_EDIT      50
  #define BUTTON_DELAY_MENU     250
  #define TOUCH_SCREEN_CALIBRATION
  #if ALL(TOUCH_SCREEN_CALIBRATION, EEPROM_SETTINGS)
    #define TOUCH_CALIBRATION_AUTO_SAVE
  #endif
  #if ENABLED(TFT_COLOR_UI)
    #define SINGLE_TOUCH_NAVIGATION
  #endif
#endif

// Fans / PWM
#define FAN_SOFT_PWM
#define SOFT_PWM_SCALE 0

// Servos
#define SERVO_DELAY { 300 }

