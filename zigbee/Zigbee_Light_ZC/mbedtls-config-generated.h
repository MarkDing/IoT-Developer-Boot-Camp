/***************************************************************************//**
 * @file mbedtls-config-generated.h
 * @brief mbed TLS configuration file. This file is generated do not modify it directly. Please use the mbed TLS setup instead.
 *
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef MBEDTLS_CONFIG_GENERATED_H
#define MBEDTLS_CONFIG_GENERATED_H

#if !defined(EMBER_TEST)
#define MBEDTLS_NO_PLATFORM_ENTROPY

#else
// mbedtls/library/entropy_poll.c needs this,
// implicit declaration of function 'syscall' otherwise
#define _GNU_SOURCE
#endif

// Generated content that is coming from contributor plugins



#define MBEDTLS_AES_C


#if defined(MBEDTLS_ENTROPY_C)
// Enable RAIL radio as entropy source by default
// This is going to help on devices that does not have TRNG support by software
// (FR32XG13 (SDID_89) and EFR32XG14 (SDID_95))
#define MBEDTLS_ENTROPY_RAIL_C
#endif

// Inclusion of the Silabs specific device acceleration configuration file.
#if defined(MBEDTLS_DEVICE_ACCELERATION_CONFIG_FILE)
#include MBEDTLS_DEVICE_ACCELERATION_CONFIG_FILE
#endif

// Inclusion of the app specific device acceleration configuration file.
#if defined(MBEDTLS_DEVICE_ACCELERATION_CONFIG_APP_FILE)
#include MBEDTLS_DEVICE_ACCELERATION_CONFIG_APP_FILE
#endif

// Inclusion of the mbed TLS config_check.h header file.
#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_GENERATED_H */
