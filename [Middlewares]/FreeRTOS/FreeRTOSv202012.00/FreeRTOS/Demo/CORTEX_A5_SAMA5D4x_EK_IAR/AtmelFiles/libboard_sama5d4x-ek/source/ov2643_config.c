<<<<<<< HEAD
/* ----------------------------------------------------------------------------
 *         SAM Software Package License 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2013, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 */

/*------------------------------------------------------------------------------
 *         Headers
 *------------------------------------------------------------------------------*/

#include "board.h"

/*
 * ID
 */
#define MANUFACTURER_ID    0x7FA2


/*------------------------------------------------------------------------------
 *         Local Variables
 *------------------------------------------------------------------------------*/

const struct ov_reg ov2643_yuv_uxga[]= {
    {0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb7},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    {0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0},
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},

    {0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb4},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    {0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0},
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},
    {0xFF, 0xFF}
};

const struct ov_reg ov2643_yuv_swvga[]= {
{0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb4},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    {0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0},
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},

    {0x3d, 0x48},
    {0x0e, 0xb8},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x21, 0x98},
    {0x22, 0x00},
    {0x23, 0x06},
    {0x24, 0x32},
    {0x25, 0x04},
    {0x26, 0x25},
    {0x27, 0x84},
    {0x28, 0x40},
    {0x29, 0x04},
    {0x2a, 0xce},
    {0x2b, 0x02},
    {0x2c, 0x8a},
    {0x12, 0x09},
    {0x39, 0xd0},
    {0xcd, 0x13},
    {0xde, 0x7c},
    {0x3d, 0x08},
    {0x15, 0x42},
    {0xde, 0x7c},
    {0x0f, 0x24},
    {0xFF, 0xFF}
};

const struct ov_reg ov2643_yuv_vga[]= {
    {0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb7},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    //{0x43, 0xC0},
	{0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0}, 
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},

    {0x13, 0x00},
    {0x3d, 0x48}, 
    {0x0e, 0xb8}, 
    {0x20, 0x02},  
    {0x21, 0x18}, 
    {0x22, 0x00}, 
    {0x23, 0x42},
    {0x24, 0x28}, 
    {0x25, 0x04},
    {0x26, 0x1e}, 
    {0x27, 0x04},
    {0x28, 0x40},
    {0x29, 0x04},
    {0x2a, 0xce},
    {0x2b, 0x02},
    {0x2c, 0x8a},
	//YUV
    {0x12, 0x09},
	//RGB
    //{0x12, 0x05},
	
	
    {0x39, 0xd0},
    {0xcd, 0x13},
    {0xde, 0x7c},
    {0x3d, 0x08},
    {0x13, 0xff},
    {0x15, 0x42},
    {0xFF, 0xFF}
};
=======
/* ----------------------------------------------------------------------------
 *         SAM Software Package License 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2013, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 */

/*------------------------------------------------------------------------------
 *         Headers
 *------------------------------------------------------------------------------*/

#include "board.h"

/*
 * ID
 */
#define MANUFACTURER_ID    0x7FA2


/*------------------------------------------------------------------------------
 *         Local Variables
 *------------------------------------------------------------------------------*/

const struct ov_reg ov2643_yuv_uxga[]= {
    {0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb7},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    {0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0},
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},

    {0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb4},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    {0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0},
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},
    {0xFF, 0xFF}
};

const struct ov_reg ov2643_yuv_swvga[]= {
{0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb4},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    {0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0},
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},

    {0x3d, 0x48},
    {0x0e, 0xb8},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x20, 0x01},
    {0x21, 0x98},
    {0x22, 0x00},
    {0x23, 0x06},
    {0x24, 0x32},
    {0x25, 0x04},
    {0x26, 0x25},
    {0x27, 0x84},
    {0x28, 0x40},
    {0x29, 0x04},
    {0x2a, 0xce},
    {0x2b, 0x02},
    {0x2c, 0x8a},
    {0x12, 0x09},
    {0x39, 0xd0},
    {0xcd, 0x13},
    {0xde, 0x7c},
    {0x3d, 0x08},
    {0x15, 0x42},
    {0xde, 0x7c},
    {0x0f, 0x24},
    {0xFF, 0xFF}
};

const struct ov_reg ov2643_yuv_vga[]= {
    {0x12, 0x80},
    {0xc3, 0x1f},
    {0xc4, 0xff},
    {0x3d, 0x48},
    {0xdd, 0xa5},
    {0x0e, 0xb7},
    {0x10, 0x0a},
    {0x11, 0x00},
    {0x0f, 0x14},
    {0x21, 0x25},
    {0x23, 0x0c},
    {0x12, 0x08},
    {0x39, 0x10},
    {0xcd, 0x12},
    {0x13, 0xff},
    {0x14, 0xa7},
    {0x15, 0x42},
    {0x3c, 0xa4},
    {0x18, 0x60},
    {0x19, 0x50},
    {0x1a, 0xe2},
    {0x37, 0xe8},
    {0x16, 0x90},
    //{0x43, 0xC0},
	{0x43, 0x00},
    {0x40, 0xfb},
    {0xa9, 0x44},
    {0x2f, 0xec},
    {0x35, 0x10},
    {0x36, 0x10},
    {0x0c, 0x00},
    {0x0d, 0x00},
    {0xd0, 0x93},
    {0xdc, 0x2b},
    {0xd9, 0x41},
    {0xd3, 0x02},
    {0x3d, 0x08},
    {0x0c, 0x00},
    {0x18, 0x2c},
    {0x19, 0x24},
    {0x1a, 0x71},
    {0x9b, 0x69},
    {0x9c, 0x7d},
    {0x9d, 0x7d},
    {0x9e, 0x69},
    {0x35, 0x04},
    {0x36, 0x04},
    {0x65, 0x12},
    {0x66, 0x20},
    {0x67, 0x39},
    {0x68, 0x4e},
    {0x69, 0x62},
    {0x6a, 0x74},
    {0x6b, 0x85},
    {0x6c, 0x92},
    {0x6d, 0x9e},
    {0x6e, 0xb2},
    {0x6f, 0xc0},
    {0x70, 0xcc},
    {0x71, 0xe0},
    {0x72, 0xee},
    {0x73, 0xf6},
    {0x74, 0x11},
    {0xab, 0x20},
    {0xac, 0x5b},
    {0xad, 0x05},
    {0xae, 0x1b},
    {0xaf, 0x76},
    {0xb0, 0x90},
    {0xb1, 0x90},
    {0xb2, 0x8c},
    {0xb3, 0x04},
    {0xb4, 0x98},
    {0x4c, 0x03},
    {0x4d, 0x30},
    {0x4e, 0x02},
    {0x4f, 0x5c},
    {0x50, 0x56},
    {0x51, 0x00},
    {0x52, 0x66},
    {0x53, 0x03},
    {0x54, 0x30},
    {0x55, 0x02},
    {0x56, 0x5c},
    {0x57, 0x40},
    {0x58, 0x00},
    {0x59, 0x66},
    {0x5a, 0x03},
    {0x5b, 0x20},
    {0x5c, 0x02},
    {0x5d, 0x5c},
    {0x5e, 0x3a},
    {0x5f, 0x00},
    {0x60, 0x66},
    {0x41, 0x1f},
    {0xb5, 0x01},
    {0xb6, 0x02},
    {0xb9, 0x40},
    {0xba, 0x28},
    {0xbf, 0x0c},
    {0xc0, 0x3e},
    {0xa3, 0x0a},
    {0xa4, 0x0f},
    {0xa5, 0x09},
    {0xa6, 0x16},
    {0x9f, 0x0a},
    {0xa0, 0x0f},
    {0xa7, 0x0a},
    {0xa8, 0x0f},
    {0xa1, 0x10},
    {0xa2, 0x04},
    {0xa9, 0x04},
    {0xaa, 0xa6},
    {0x75, 0x6a},
    {0x76, 0x11},
    {0x77, 0x92},
    {0x78, 0x21},
    {0x79, 0xe1},
    {0x7a, 0x02},
    {0x7c, 0x05},
    {0x7d, 0x08},
    {0x7e, 0x08},
    {0x7f, 0x7c},
    {0x80, 0x58},
    {0x81, 0x2a},
    {0x82, 0xc5},
    {0x83, 0x46},
    {0x84, 0x3a},
    {0x85, 0x54},
    {0x86, 0x44},
    {0x87, 0xf8},
    {0x88, 0x08},
    {0x89, 0x70},
    {0x8a, 0xf0},
    {0x8b, 0xf0}, 
    {0x90, 0xe3},
    {0x93, 0x10},
    {0x94, 0x20},
    {0x95, 0x10},
    {0x96, 0x18},
    {0x0f, 0x34},

    {0x13, 0x00},
    {0x3d, 0x48}, 
    {0x0e, 0xb8}, 
    {0x20, 0x02},  
    {0x21, 0x18}, 
    {0x22, 0x00}, 
    {0x23, 0x42},
    {0x24, 0x28}, 
    {0x25, 0x04},
    {0x26, 0x1e}, 
    {0x27, 0x04},
    {0x28, 0x40},
    {0x29, 0x04},
    {0x2a, 0xce},
    {0x2b, 0x02},
    {0x2c, 0x8a},
	//YUV
    {0x12, 0x09},
	//RGB
    //{0x12, 0x05},
	
	
    {0x39, 0xd0},
    {0xcd, 0x13},
    {0xde, 0x7c},
    {0x3d, 0x08},
    {0x13, 0xff},
    {0x15, 0x42},
    {0xFF, 0xFF}
};
>>>>>>> 16c66438 (Upload from PC.)
