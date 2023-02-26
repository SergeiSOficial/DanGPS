/*!
 * @file      smtc_hal_flash.h
 *
 * @brief     Board specific package FLASH API definition.
 *
 * Revised BSD License
 * Copyright Semtech Corporation 2020. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Semtech corporation nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL SEMTECH CORPORATION BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SMTC_HAL_FLASH_H
#define SMTC_HAL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * -----------------------------------------------------------------------------
 * --- DEPENDENCIES ------------------------------------------------------------
 */

#include <stdint.h>

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC MACROS -----------------------------------------------------------
 */

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC CONSTANTS --------------------------------------------------------
 */

#define ADDR_FLASH_PAGE_SIZE ( ( uint32_t ) 0x00001000 ) /* Size of Page = 4 Kbytes */

#define FLASH_BYTE_EMPTY_CONTENT ( ( uint8_t ) 0xFF )
#define FLASH_PAGE_EMPTY_CONTENT ( ( uint64_t ) 0xFFFFFFFFFFFFFFFF )

#define FLASH_USER_START_PAGE ( 0 ) /* Start nb page of user Flash area, 8 because of the bootloader */

#define FLASH_USER_END_ADDR ( ADDR_FLASH_PAGE_48 + ADDR_FLASH_PAGE_SIZE - 1 ) /* End @ of user Flash area */
#define FLASH_USER_END_PAGE ( 48 )                                            /* End nb page of user Flash area */

#define FLASH_USER_INTERNAL_LOG_CTX_START_ADDR ADDR_FLASH_PAGE_49
#define FLASH_USER_INTERNAL_LOG_CTX_END_ADDR \
    ( ADDR_FLASH_PAGE_49 + ADDR_FLASH_PAGE_SIZE - 1 ) /* End @ of user ctx Flash area */

#define FLASH_USER_TRACKER_CTX_START_ADDR ADDR_FLASH_PAGE_56
#define FLASH_USER_TRACKER_CTX_END_ADDR \
    ( ADDR_FLASH_PAGE_56 + ADDR_FLASH_PAGE_SIZE - 1 ) /* End @ of user tracker ctx Flash area */

/* Base address of the Flash s */
#define ADDR_FLASH_PAGE_0 ( ( uint32_t ) 0x08000000 )   /* Base @ of Page 0, 4 Kbytes */
#define ADDR_FLASH_PAGE_1 ( ( uint32_t ) 0x08001000 )   /* Base @ of Page 1, 4 Kbytes */
#define ADDR_FLASH_PAGE_2 ( ( uint32_t ) 0x08002000 )   /* Base @ of Page 2, 4 Kbytes */
#define ADDR_FLASH_PAGE_3 ( ( uint32_t ) 0x08003000 )   /* Base @ of Page 3, 4 Kbytes */
#define ADDR_FLASH_PAGE_4 ( ( uint32_t ) 0x08004000 )   /* Base @ of Page 4, 4 Kbytes */
#define ADDR_FLASH_PAGE_5 ( ( uint32_t ) 0x08005000 )   /* Base @ of Page 5, 4 Kbytes */
#define ADDR_FLASH_PAGE_6 ( ( uint32_t ) 0x08006000 )   /* Base @ of Page 6, 4 Kbytes */
#define ADDR_FLASH_PAGE_7 ( ( uint32_t ) 0x08007000 )   /* Base @ of Page 7, 4 Kbytes */
#define ADDR_FLASH_PAGE_8 ( ( uint32_t ) 0x08008000 )   /* Base @ of Page 8, 4 Kbytes */
#define ADDR_FLASH_PAGE_9 ( ( uint32_t ) 0x08009000 )   /* Base @ of Page 9, 4 Kbytes */
#define ADDR_FLASH_PAGE_10 ( ( uint32_t ) 0x0800A000 )  /* Base @ of Page 10, 4 Kbytes */
#define ADDR_FLASH_PAGE_11 ( ( uint32_t ) 0x0800B000 )  /* Base @ of Page 11, 4 Kbytes */
#define ADDR_FLASH_PAGE_12 ( ( uint32_t ) 0x0800C000 )  /* Base @ of Page 12, 4 Kbytes */
#define ADDR_FLASH_PAGE_13 ( ( uint32_t ) 0x0800D000 )  /* Base @ of Page 13, 4 Kbytes */
#define ADDR_FLASH_PAGE_14 ( ( uint32_t ) 0x0800E000 )  /* Base @ of Page 14, 4 Kbytes */
#define ADDR_FLASH_PAGE_15 ( ( uint32_t ) 0x0800F000 )  /* Base @ of Page 15, 4 Kbytes */
#define ADDR_FLASH_PAGE_16 ( ( uint32_t ) 0x08010000 )  /* Base @ of Page 16, 4 Kbytes */
#define ADDR_FLASH_PAGE_17 ( ( uint32_t ) 0x08011000 )  /* Base @ of Page 17, 4 Kbytes */
#define ADDR_FLASH_PAGE_18 ( ( uint32_t ) 0x08012000 )  /* Base @ of Page 18, 4 Kbytes */
#define ADDR_FLASH_PAGE_19 ( ( uint32_t ) 0x08013000 )  /* Base @ of Page 19, 4 Kbytes */
#define ADDR_FLASH_PAGE_20 ( ( uint32_t ) 0x08014000 )  /* Base @ of Page 20, 4 Kbytes */
#define ADDR_FLASH_PAGE_21 ( ( uint32_t ) 0x08015000 )  /* Base @ of Page 21, 4 Kbytes */
#define ADDR_FLASH_PAGE_22 ( ( uint32_t ) 0x08016000 )  /* Base @ of Page 22, 4 Kbytes */
#define ADDR_FLASH_PAGE_23 ( ( uint32_t ) 0x08017000 )  /* Base @ of Page 23, 4 Kbytes */
#define ADDR_FLASH_PAGE_24 ( ( uint32_t ) 0x08018000 )  /* Base @ of Page 24, 4 Kbytes */
#define ADDR_FLASH_PAGE_25 ( ( uint32_t ) 0x08019000 )  /* Base @ of Page 25, 4 Kbytes */
#define ADDR_FLASH_PAGE_26 ( ( uint32_t ) 0x0801A000 )  /* Base @ of Page 26, 4 Kbytes */
#define ADDR_FLASH_PAGE_27 ( ( uint32_t ) 0x0801B000 )  /* Base @ of Page 27, 4 Kbytes */
#define ADDR_FLASH_PAGE_28 ( ( uint32_t ) 0x0801C000 )  /* Base @ of Page 28, 4 Kbytes */
#define ADDR_FLASH_PAGE_29 ( ( uint32_t ) 0x0801D000 )  /* Base @ of Page 29, 4 Kbytes */
#define ADDR_FLASH_PAGE_30 ( ( uint32_t ) 0x0801E000 )  /* Base @ of Page 30, 4 Kbytes */
#define ADDR_FLASH_PAGE_31 ( ( uint32_t ) 0x0801F000 )  /* Base @ of Page 31, 4 Kbytes */
#define ADDR_FLASH_PAGE_32 ( ( uint32_t ) 0x08020000 )  /* Base @ of Page 32, 4 Kbytes */
#define ADDR_FLASH_PAGE_33 ( ( uint32_t ) 0x08021000 )  /* Base @ of Page 33, 4 Kbytes */
#define ADDR_FLASH_PAGE_34 ( ( uint32_t ) 0x08022000 )  /* Base @ of Page 34, 4 Kbytes */
#define ADDR_FLASH_PAGE_35 ( ( uint32_t ) 0x08023000 )  /* Base @ of Page 35, 4 Kbytes */
#define ADDR_FLASH_PAGE_36 ( ( uint32_t ) 0x08024000 )  /* Base @ of Page 36, 4 Kbytes */
#define ADDR_FLASH_PAGE_37 ( ( uint32_t ) 0x08025000 )  /* Base @ of Page 37, 4 Kbytes */
#define ADDR_FLASH_PAGE_38 ( ( uint32_t ) 0x08026000 )  /* Base @ of Page 38, 4 Kbytes */
#define ADDR_FLASH_PAGE_39 ( ( uint32_t ) 0x08027000 )  /* Base @ of Page 39, 4 Kbytes */
#define ADDR_FLASH_PAGE_40 ( ( uint32_t ) 0x08028000 )  /* Base @ of Page 40, 4 Kbytes */
#define ADDR_FLASH_PAGE_41 ( ( uint32_t ) 0x08029000 )  /* Base @ of Page 41, 4 Kbytes */
#define ADDR_FLASH_PAGE_42 ( ( uint32_t ) 0x0802A000 )  /* Base @ of Page 42, 4 Kbytes */
#define ADDR_FLASH_PAGE_43 ( ( uint32_t ) 0x0802B000 )  /* Base @ of Page 43, 4 Kbytes */
#define ADDR_FLASH_PAGE_44 ( ( uint32_t ) 0x0802C000 )  /* Base @ of Page 44, 4 Kbytes */
#define ADDR_FLASH_PAGE_45 ( ( uint32_t ) 0x0802D000 )  /* Base @ of Page 45, 4 Kbytes */
#define ADDR_FLASH_PAGE_46 ( ( uint32_t ) 0x0802E000 )  /* Base @ of Page 46, 4 Kbytes */
#define ADDR_FLASH_PAGE_47 ( ( uint32_t ) 0x0802F000 )  /* Base @ of Page 47, 4 Kbytes */
#define ADDR_FLASH_PAGE_48 ( ( uint32_t ) 0x08030000 )  /* Base @ of Page 48, 4 Kbytes */
#define ADDR_FLASH_PAGE_49 ( ( uint32_t ) 0x08031000 )  /* Base @ of Page 49, 4 Kbytes */
#define ADDR_FLASH_PAGE_50 ( ( uint32_t ) 0x08032000 )  /* Base @ of Page 50, 4 Kbytes */
#define ADDR_FLASH_PAGE_51 ( ( uint32_t ) 0x08033000 )  /* Base @ of Page 51, 4 Kbytes */
#define ADDR_FLASH_PAGE_52 ( ( uint32_t ) 0x08034000 )  /* Base @ of Page 52, 4 Kbytes */
#define ADDR_FLASH_PAGE_53 ( ( uint32_t ) 0x08035000 )  /* Base @ of Page 53, 4 Kbytes */
#define ADDR_FLASH_PAGE_54 ( ( uint32_t ) 0x08036000 )  /* Base @ of Page 54, 4 Kbytes */
#define ADDR_FLASH_PAGE_55 ( ( uint32_t ) 0x08037000 )  /* Base @ of Page 55, 4 Kbytes */
#define ADDR_FLASH_PAGE_56 ( ( uint32_t ) 0x08038000 )  /* Base @ of Page 56, 4 Kbytes */
#define ADDR_FLASH_PAGE_57 ( ( uint32_t ) 0x08039000 )  /* Base @ of Page 57, 4 Kbytes */
#define ADDR_FLASH_PAGE_58 ( ( uint32_t ) 0x0803A000 )  /* Base @ of Page 58, 4 Kbytes */
#define ADDR_FLASH_PAGE_59 ( ( uint32_t ) 0x0803B000 )  /* Base @ of Page 59, 4 Kbytes */
#define ADDR_FLASH_PAGE_60 ( ( uint32_t ) 0x0803C000 )  /* Base @ of Page 60, 4 Kbytes */
#define ADDR_FLASH_PAGE_61 ( ( uint32_t ) 0x0803D000 )  /* Base @ of Page 61, 4 Kbytes */
#define ADDR_FLASH_PAGE_62 ( ( uint32_t ) 0x0803E000 )  /* Base @ of Page 62, 4 Kbytes */
#define ADDR_FLASH_PAGE_63 ( ( uint32_t ) 0x0803F000 )  /* Base @ of Page 63, 4 Kbytes */
#define ADDR_FLASH_PAGE_64 ( ( uint32_t ) 0x08040000 )  /* Base @ of Page 64, 4 Kbytes */
#define ADDR_FLASH_PAGE_65 ( ( uint32_t ) 0x08041000 )  /* Base @ of Page 65, 4 Kbytes */
#define ADDR_FLASH_PAGE_66 ( ( uint32_t ) 0x08042000 )  /* Base @ of Page 66, 4 Kbytes */
#define ADDR_FLASH_PAGE_67 ( ( uint32_t ) 0x08043000 )  /* Base @ of Page 67, 4 Kbytes */
#define ADDR_FLASH_PAGE_68 ( ( uint32_t ) 0x08044000 )  /* Base @ of Page 68, 4 Kbytes */
#define ADDR_FLASH_PAGE_69 ( ( uint32_t ) 0x08045000 )  /* Base @ of Page 69, 4 Kbytes */
#define ADDR_FLASH_PAGE_70 ( ( uint32_t ) 0x08046000 )  /* Base @ of Page 70, 4 Kbytes */
#define ADDR_FLASH_PAGE_71 ( ( uint32_t ) 0x08047000 )  /* Base @ of Page 71, 4 Kbytes */
#define ADDR_FLASH_PAGE_72 ( ( uint32_t ) 0x08048000 )  /* Base @ of Page 72, 4 Kbytes */
#define ADDR_FLASH_PAGE_73 ( ( uint32_t ) 0x08049000 )  /* Base @ of Page 73, 4 Kbytes */
#define ADDR_FLASH_PAGE_74 ( ( uint32_t ) 0x0804A000 )  /* Base @ of Page 74, 4 Kbytes */
#define ADDR_FLASH_PAGE_75 ( ( uint32_t ) 0x0804B000 )  /* Base @ of Page 75, 4 Kbytes */
#define ADDR_FLASH_PAGE_76 ( ( uint32_t ) 0x0804C000 )  /* Base @ of Page 76, 4 Kbytes */
#define ADDR_FLASH_PAGE_77 ( ( uint32_t ) 0x0804D000 )  /* Base @ of Page 77, 4 Kbytes */
#define ADDR_FLASH_PAGE_78 ( ( uint32_t ) 0x0804E000 )  /* Base @ of Page 78, 4 Kbytes */
#define ADDR_FLASH_PAGE_79 ( ( uint32_t ) 0x0804F000 )  /* Base @ of Page 79, 4 Kbytes */
#define ADDR_FLASH_PAGE_80 ( ( uint32_t ) 0x08050000 )  /* Base @ of Page 80, 4 Kbytes */

#define FLASH_OPERATION_MAX_RETRY 4

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC TYPES ------------------------------------------------------------
 */

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC FUNCTIONS PROTOTYPES ---------------------------------------------
 */

/*!
 * @brief Initializes the FLASH module and find the first empty page.
 *
 * @returns User flash start address
 */
uint32_t flash_init( void );

/*!
 * @brief Erase a given nb page to the FLASH at the specified address.
 *
 * @param [in] addr FLASH address to start the erase
 * @param [in] nb_page the number of page to erase.
 * @returns status [SUCCESS, FAIL]
 */
uint8_t flash_erase_page( uint32_t addr, uint8_t nb_page );

/*!
 * @brief Force erasing of a given nb page to the FLASH at the specified address.
 *
 * @param [in] addr FLASH address to start the erase
 * @param [in] nb_page the number of page to erase.
 * @returns status [SUCCESS, FAIL]
 */
uint8_t flash_force_erase_page( uint32_t addr, uint8_t nb_page );

/*!
 * @brief Writes the given buffer to the FLASH at the specified address.
 *
 * @param [in] addr FLASH address to write to
 * @param [in] buffer Pointer to the buffer to be written.
 * @param [in] size Size of the buffer to be written.
 * @returns status [Real_size_written, FAIL]
 */
uint32_t flash_write_buffer( uint32_t addr, uint8_t* buffer, uint32_t size );

/*!
 * @brief Reads the FLASH at the specified address to the given buffer.
 *
 * @param [in] addr FLASH address to read from
 * @param [out] buffer Pointer to the buffer to be written with read data.
 * @param [in] size Size of the buffer to be read.
 * @returns status [SUCCESS, FAIL]
 */
void flash_read_buffer( uint32_t addr, uint8_t* buffer, uint32_t size );

/*!
 * @brief Reads the FLASH at the specified address to the given buffer.
 *
 * @returns User flash start address.
 */
uint32_t flash_get_user_start_addr( void );

/*!
 * @brief Set the FLASH user start addr.
 *
 * @param [in] addr User flash start address.
 */
void flash_set_user_start_addr( uint32_t addr );

#ifdef __cplusplus
}
#endif

#endif  // SMTC_HAL_FLASH_H

/* --- EOF ------------------------------------------------------------------ */
