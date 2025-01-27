<<<<<<< HEAD
/**
 * \file
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAM3S8_CRCCU_INSTANCE_
#define _SAM3S8_CRCCU_INSTANCE_

/* ========== Register definition for CRCCU peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_CRCCU_DSCR             (0x40044000U) /**< \brief (CRCCU) CRCCU Descriptor Base Register */
#define REG_CRCCU_DMA_EN           (0x40044008U) /**< \brief (CRCCU) CRCCU DMA Enable Register */
#define REG_CRCCU_DMA_DIS          (0x4004400CU) /**< \brief (CRCCU) CRCCU DMA Disable Register */
#define REG_CRCCU_DMA_SR           (0x40044010U) /**< \brief (CRCCU) CRCCU DMA Status Register */
#define REG_CRCCU_DMA_IER          (0x40044014U) /**< \brief (CRCCU) CRCCU DMA Interrupt Enable Register */
#define REG_CRCCU_DMA_IDR          (0x40044018U) /**< \brief (CRCCU) CRCCU DMA Interrupt Disable Register */
#define REG_CRCCU_DMA_IMR          (0x4004401CU) /**< \brief (CRCCU) CRCCU DMA Interrupt Mask Register */
#define REG_CRCCU_DMA_ISR          (0x40044020U) /**< \brief (CRCCU) CRCCU DMA Interrupt Status Register */
#define REG_CRCCU_CR               (0x40044034U) /**< \brief (CRCCU) CRCCU Control Register */
#define REG_CRCCU_MR               (0x40044038U) /**< \brief (CRCCU) CRCCU Mode Register */
#define REG_CRCCU_SR               (0x4004403CU) /**< \brief (CRCCU) CRCCU Status Register */
#define REG_CRCCU_IER              (0x40044040U) /**< \brief (CRCCU) CRCCU Interrupt Enable Register */
#define REG_CRCCU_IDR              (0x40044044U) /**< \brief (CRCCU) CRCCU Interrupt Disable Register */
#define REG_CRCCU_IMR              (0x40044048U) /**< \brief (CRCCU) CRCCU Interrupt Mask Register */
#define REG_CRCCU_ISR              (0x4004404CU) /**< \brief (CRCCU) CRCCU Interrupt Status Register */
#else
#define REG_CRCCU_DSCR    (*(RwReg*)0x40044000U) /**< \brief (CRCCU) CRCCU Descriptor Base Register */
#define REG_CRCCU_DMA_EN  (*(WoReg*)0x40044008U) /**< \brief (CRCCU) CRCCU DMA Enable Register */
#define REG_CRCCU_DMA_DIS (*(WoReg*)0x4004400CU) /**< \brief (CRCCU) CRCCU DMA Disable Register */
#define REG_CRCCU_DMA_SR  (*(RoReg*)0x40044010U) /**< \brief (CRCCU) CRCCU DMA Status Register */
#define REG_CRCCU_DMA_IER (*(WoReg*)0x40044014U) /**< \brief (CRCCU) CRCCU DMA Interrupt Enable Register */
#define REG_CRCCU_DMA_IDR (*(WoReg*)0x40044018U) /**< \brief (CRCCU) CRCCU DMA Interrupt Disable Register */
#define REG_CRCCU_DMA_IMR (*(RoReg*)0x4004401CU) /**< \brief (CRCCU) CRCCU DMA Interrupt Mask Register */
#define REG_CRCCU_DMA_ISR (*(RoReg*)0x40044020U) /**< \brief (CRCCU) CRCCU DMA Interrupt Status Register */
#define REG_CRCCU_CR      (*(WoReg*)0x40044034U) /**< \brief (CRCCU) CRCCU Control Register */
#define REG_CRCCU_MR      (*(RwReg*)0x40044038U) /**< \brief (CRCCU) CRCCU Mode Register */
#define REG_CRCCU_SR      (*(RoReg*)0x4004403CU) /**< \brief (CRCCU) CRCCU Status Register */
#define REG_CRCCU_IER     (*(WoReg*)0x40044040U) /**< \brief (CRCCU) CRCCU Interrupt Enable Register */
#define REG_CRCCU_IDR     (*(WoReg*)0x40044044U) /**< \brief (CRCCU) CRCCU Interrupt Disable Register */
#define REG_CRCCU_IMR     (*(RoReg*)0x40044048U) /**< \brief (CRCCU) CRCCU Interrupt Mask Register */
#define REG_CRCCU_ISR     (*(RoReg*)0x4004404CU) /**< \brief (CRCCU) CRCCU Interrupt Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S8_CRCCU_INSTANCE_ */
=======
/**
 * \file
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAM3S8_CRCCU_INSTANCE_
#define _SAM3S8_CRCCU_INSTANCE_

/* ========== Register definition for CRCCU peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_CRCCU_DSCR             (0x40044000U) /**< \brief (CRCCU) CRCCU Descriptor Base Register */
#define REG_CRCCU_DMA_EN           (0x40044008U) /**< \brief (CRCCU) CRCCU DMA Enable Register */
#define REG_CRCCU_DMA_DIS          (0x4004400CU) /**< \brief (CRCCU) CRCCU DMA Disable Register */
#define REG_CRCCU_DMA_SR           (0x40044010U) /**< \brief (CRCCU) CRCCU DMA Status Register */
#define REG_CRCCU_DMA_IER          (0x40044014U) /**< \brief (CRCCU) CRCCU DMA Interrupt Enable Register */
#define REG_CRCCU_DMA_IDR          (0x40044018U) /**< \brief (CRCCU) CRCCU DMA Interrupt Disable Register */
#define REG_CRCCU_DMA_IMR          (0x4004401CU) /**< \brief (CRCCU) CRCCU DMA Interrupt Mask Register */
#define REG_CRCCU_DMA_ISR          (0x40044020U) /**< \brief (CRCCU) CRCCU DMA Interrupt Status Register */
#define REG_CRCCU_CR               (0x40044034U) /**< \brief (CRCCU) CRCCU Control Register */
#define REG_CRCCU_MR               (0x40044038U) /**< \brief (CRCCU) CRCCU Mode Register */
#define REG_CRCCU_SR               (0x4004403CU) /**< \brief (CRCCU) CRCCU Status Register */
#define REG_CRCCU_IER              (0x40044040U) /**< \brief (CRCCU) CRCCU Interrupt Enable Register */
#define REG_CRCCU_IDR              (0x40044044U) /**< \brief (CRCCU) CRCCU Interrupt Disable Register */
#define REG_CRCCU_IMR              (0x40044048U) /**< \brief (CRCCU) CRCCU Interrupt Mask Register */
#define REG_CRCCU_ISR              (0x4004404CU) /**< \brief (CRCCU) CRCCU Interrupt Status Register */
#else
#define REG_CRCCU_DSCR    (*(RwReg*)0x40044000U) /**< \brief (CRCCU) CRCCU Descriptor Base Register */
#define REG_CRCCU_DMA_EN  (*(WoReg*)0x40044008U) /**< \brief (CRCCU) CRCCU DMA Enable Register */
#define REG_CRCCU_DMA_DIS (*(WoReg*)0x4004400CU) /**< \brief (CRCCU) CRCCU DMA Disable Register */
#define REG_CRCCU_DMA_SR  (*(RoReg*)0x40044010U) /**< \brief (CRCCU) CRCCU DMA Status Register */
#define REG_CRCCU_DMA_IER (*(WoReg*)0x40044014U) /**< \brief (CRCCU) CRCCU DMA Interrupt Enable Register */
#define REG_CRCCU_DMA_IDR (*(WoReg*)0x40044018U) /**< \brief (CRCCU) CRCCU DMA Interrupt Disable Register */
#define REG_CRCCU_DMA_IMR (*(RoReg*)0x4004401CU) /**< \brief (CRCCU) CRCCU DMA Interrupt Mask Register */
#define REG_CRCCU_DMA_ISR (*(RoReg*)0x40044020U) /**< \brief (CRCCU) CRCCU DMA Interrupt Status Register */
#define REG_CRCCU_CR      (*(WoReg*)0x40044034U) /**< \brief (CRCCU) CRCCU Control Register */
#define REG_CRCCU_MR      (*(RwReg*)0x40044038U) /**< \brief (CRCCU) CRCCU Mode Register */
#define REG_CRCCU_SR      (*(RoReg*)0x4004403CU) /**< \brief (CRCCU) CRCCU Status Register */
#define REG_CRCCU_IER     (*(WoReg*)0x40044040U) /**< \brief (CRCCU) CRCCU Interrupt Enable Register */
#define REG_CRCCU_IDR     (*(WoReg*)0x40044044U) /**< \brief (CRCCU) CRCCU Interrupt Disable Register */
#define REG_CRCCU_IMR     (*(RoReg*)0x40044048U) /**< \brief (CRCCU) CRCCU Interrupt Mask Register */
#define REG_CRCCU_ISR     (*(RoReg*)0x4004404CU) /**< \brief (CRCCU) CRCCU Interrupt Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S8_CRCCU_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)
