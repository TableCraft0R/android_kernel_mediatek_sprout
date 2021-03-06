/*
* Copyright (C) 2011-2014 MediaTek Inc.
* 
* This program is free software: you can redistribute it and/or modify it under the terms of the 
* GNU General Public License version 2 as published by the Free Software Foundation.
* 
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _CUST_SEC_H
#define _CUST_SEC_H

/**************************************************************************
 * RSA PKCS01 CONTROL
 **************************************************************************/
#define RSA_KEY_LEN_2048                    (0)
#define RSA_KEY_LEN_1024                    (1)

/**************************************************************************
 * RSA PKCS01 CHECKING
 **************************************************************************/
#if RSA_KEY_LEN_2048
#if RSA_KEY_LEN_1024
#error "RSA_KEY_LEN_1024 should be disabled"
#endif
#endif

#if RSA_KEY_LEN_1024
#if RSA_KEY_LEN_2048
#error "RSA_KEY_LEN_2048 should be disabled"
#endif
#endif

/**************************************************************************
 * RSA PKCS01 CONFIGURATION
 **************************************************************************/
#define RSA_KEY_MAX_LEN                     (128) // bytes
#define RSA_E_KEY_LEN                       (5) // bytes

#if RSA_KEY_LEN_2048
#define RSA_KEY_LEN                         (256) // bytes
#define HASH_LEN                            (32)  // bytes

#elif RSA_KEY_LEN_1024
#define RSA_KEY_LEN                         (128) // bytes
#define HASH_LEN                            (20)  // bytes

#else
#error "RSA_KEY_LEN is not defined"

#endif

/**************************************************************************
 *  CUSTOMER INTERFACE
 **************************************************************************/
typedef struct _CUST_SEC_INTER
{
    /* key to sign image patch */
    unsigned char                   key_rsa_n[RSA_KEY_MAX_LEN*2]; // string. number base = 16
    unsigned char                   key_rsa_d[RSA_KEY_MAX_LEN*2]; // string. number base = 16
    unsigned char                   key_rsa_e[RSA_E_KEY_LEN]; // string. number base = 16
} CUST_SEC_INTER;

#endif   /*_CUST_SEC_H*/
