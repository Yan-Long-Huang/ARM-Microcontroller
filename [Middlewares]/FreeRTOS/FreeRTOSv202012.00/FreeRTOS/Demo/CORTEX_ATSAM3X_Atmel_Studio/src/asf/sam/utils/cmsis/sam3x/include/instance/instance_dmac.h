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

#ifndef _SAM3XA_DMAC_INSTANCE_
#define _SAM3XA_DMAC_INSTANCE_

/* ========== Register definition for DMAC peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_DMAC_GCFG            (0x400C4000U) /**< \brief (DMAC) DMAC Global Configuration Register */
#define REG_DMAC_EN              (0x400C4004U) /**< \brief (DMAC) DMAC Enable Register */
#define REG_DMAC_SREQ            (0x400C4008U) /**< \brief (DMAC) DMAC Software Single Request Register */
#define REG_DMAC_CREQ            (0x400C400CU) /**< \brief (DMAC) DMAC Software Chunk Transfer Request Register */
#define REG_DMAC_LAST            (0x400C4010U) /**< \brief (DMAC) DMAC Software Last Transfer Flag Register */
#define REG_DMAC_EBCIER          (0x400C4018U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Enable register. */
#define REG_DMAC_EBCIDR          (0x400C401CU) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Disable register. */
#define REG_DMAC_EBCIMR          (0x400C4020U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Mask Register. */
#define REG_DMAC_EBCISR          (0x400C4024U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Status Register. */
#define REG_DMAC_CHER            (0x400C4028U) /**< \brief (DMAC) DMAC Channel Handler Enable Register */
#define REG_DMAC_CHDR            (0x400C402CU) /**< \brief (DMAC) DMAC Channel Handler Disable Register */
#define REG_DMAC_CHSR            (0x400C4030U) /**< \brief (DMAC) DMAC Channel Handler Status Register */
#define REG_DMAC_SADDR0          (0x400C403CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 0) */
#define REG_DMAC_DADDR0          (0x400C4040U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 0) */
#define REG_DMAC_DSCR0           (0x400C4044U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 0) */
#define REG_DMAC_CTRLA0          (0x400C4048U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 0) */
#define REG_DMAC_CTRLB0          (0x400C404CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 0) */
#define REG_DMAC_CFG0            (0x400C4050U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 0) */
#define REG_DMAC_SADDR1          (0x400C4064U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 1) */
#define REG_DMAC_DADDR1          (0x400C4068U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 1) */
#define REG_DMAC_DSCR1           (0x400C406CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 1) */
#define REG_DMAC_CTRLA1          (0x400C4070U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 1) */
#define REG_DMAC_CTRLB1          (0x400C4074U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 1) */
#define REG_DMAC_CFG1            (0x400C4078U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 1) */
#define REG_DMAC_SADDR2          (0x400C408CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 2) */
#define REG_DMAC_DADDR2          (0x400C4090U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 2) */
#define REG_DMAC_DSCR2           (0x400C4094U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 2) */
#define REG_DMAC_CTRLA2          (0x400C4098U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 2) */
#define REG_DMAC_CTRLB2          (0x400C409CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 2) */
#define REG_DMAC_CFG2            (0x400C40A0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 2) */
#define REG_DMAC_SADDR3          (0x400C40B4U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 3) */
#define REG_DMAC_DADDR3          (0x400C40B8U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 3) */
#define REG_DMAC_DSCR3           (0x400C40BCU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 3) */
#define REG_DMAC_CTRLA3          (0x400C40C0U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 3) */
#define REG_DMAC_CTRLB3          (0x400C40C4U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 3) */
#define REG_DMAC_CFG3            (0x400C40C8U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 3) */
#define REG_DMAC_SADDR4          (0x400C40DCU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 4) */
#define REG_DMAC_DADDR4          (0x400C40E0U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 4) */
#define REG_DMAC_DSCR4           (0x400C40E4U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 4) */
#define REG_DMAC_CTRLA4          (0x400C40E8U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 4) */
#define REG_DMAC_CTRLB4          (0x400C40ECU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 4) */
#define REG_DMAC_CFG4            (0x400C40F0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 4) */
#define REG_DMAC_SADDR5          (0x400C4104U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 5) */
#define REG_DMAC_DADDR5          (0x400C4108U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 5) */
#define REG_DMAC_DSCR5           (0x400C410CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 5) */
#define REG_DMAC_CTRLA5          (0x400C4110U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 5) */
#define REG_DMAC_CTRLB5          (0x400C4114U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 5) */
#define REG_DMAC_CFG5            (0x400C4118U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 5) */
#define REG_DMAC_WPMR            (0x400C41E4U) /**< \brief (DMAC) DMAC Write Protect Mode Register */
#define REG_DMAC_WPSR            (0x400C41E8U) /**< \brief (DMAC) DMAC Write Protect Status Register */
#else
#define REG_DMAC_GCFG   (*(RwReg*)0x400C4000U) /**< \brief (DMAC) DMAC Global Configuration Register */
#define REG_DMAC_EN     (*(RwReg*)0x400C4004U) /**< \brief (DMAC) DMAC Enable Register */
#define REG_DMAC_SREQ   (*(RwReg*)0x400C4008U) /**< \brief (DMAC) DMAC Software Single Request Register */
#define REG_DMAC_CREQ   (*(RwReg*)0x400C400CU) /**< \brief (DMAC) DMAC Software Chunk Transfer Request Register */
#define REG_DMAC_LAST   (*(RwReg*)0x400C4010U) /**< \brief (DMAC) DMAC Software Last Transfer Flag Register */
#define REG_DMAC_EBCIER (*(WoReg*)0x400C4018U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Enable register. */
#define REG_DMAC_EBCIDR (*(WoReg*)0x400C401CU) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Disable register. */
#define REG_DMAC_EBCIMR (*(RoReg*)0x400C4020U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Mask Register. */
#define REG_DMAC_EBCISR (*(RoReg*)0x400C4024U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Status Register. */
#define REG_DMAC_CHER   (*(WoReg*)0x400C4028U) /**< \brief (DMAC) DMAC Channel Handler Enable Register */
#define REG_DMAC_CHDR   (*(WoReg*)0x400C402CU) /**< \brief (DMAC) DMAC Channel Handler Disable Register */
#define REG_DMAC_CHSR   (*(RoReg*)0x400C4030U) /**< \brief (DMAC) DMAC Channel Handler Status Register */
#define REG_DMAC_SADDR0 (*(RwReg*)0x400C403CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 0) */
#define REG_DMAC_DADDR0 (*(RwReg*)0x400C4040U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 0) */
#define REG_DMAC_DSCR0  (*(RwReg*)0x400C4044U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 0) */
#define REG_DMAC_CTRLA0 (*(RwReg*)0x400C4048U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 0) */
#define REG_DMAC_CTRLB0 (*(RwReg*)0x400C404CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 0) */
#define REG_DMAC_CFG0   (*(RwReg*)0x400C4050U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 0) */
#define REG_DMAC_SADDR1 (*(RwReg*)0x400C4064U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 1) */
#define REG_DMAC_DADDR1 (*(RwReg*)0x400C4068U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 1) */
#define REG_DMAC_DSCR1  (*(RwReg*)0x400C406CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 1) */
#define REG_DMAC_CTRLA1 (*(RwReg*)0x400C4070U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 1) */
#define REG_DMAC_CTRLB1 (*(RwReg*)0x400C4074U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 1) */
#define REG_DMAC_CFG1   (*(RwReg*)0x400C4078U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 1) */
#define REG_DMAC_SADDR2 (*(RwReg*)0x400C408CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 2) */
#define REG_DMAC_DADDR2 (*(RwReg*)0x400C4090U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 2) */
#define REG_DMAC_DSCR2  (*(RwReg*)0x400C4094U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 2) */
#define REG_DMAC_CTRLA2 (*(RwReg*)0x400C4098U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 2) */
#define REG_DMAC_CTRLB2 (*(RwReg*)0x400C409CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 2) */
#define REG_DMAC_CFG2   (*(RwReg*)0x400C40A0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 2) */
#define REG_DMAC_SADDR3 (*(RwReg*)0x400C40B4U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 3) */
#define REG_DMAC_DADDR3 (*(RwReg*)0x400C40B8U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 3) */
#define REG_DMAC_DSCR3  (*(RwReg*)0x400C40BCU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 3) */
#define REG_DMAC_CTRLA3 (*(RwReg*)0x400C40C0U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 3) */
#define REG_DMAC_CTRLB3 (*(RwReg*)0x400C40C4U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 3) */
#define REG_DMAC_CFG3   (*(RwReg*)0x400C40C8U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 3) */
#define REG_DMAC_SADDR4 (*(RwReg*)0x400C40DCU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 4) */
#define REG_DMAC_DADDR4 (*(RwReg*)0x400C40E0U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 4) */
#define REG_DMAC_DSCR4  (*(RwReg*)0x400C40E4U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 4) */
#define REG_DMAC_CTRLA4 (*(RwReg*)0x400C40E8U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 4) */
#define REG_DMAC_CTRLB4 (*(RwReg*)0x400C40ECU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 4) */
#define REG_DMAC_CFG4   (*(RwReg*)0x400C40F0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 4) */
#define REG_DMAC_SADDR5 (*(RwReg*)0x400C4104U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 5) */
#define REG_DMAC_DADDR5 (*(RwReg*)0x400C4108U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 5) */
#define REG_DMAC_DSCR5  (*(RwReg*)0x400C410CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 5) */
#define REG_DMAC_CTRLA5 (*(RwReg*)0x400C4110U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 5) */
#define REG_DMAC_CTRLB5 (*(RwReg*)0x400C4114U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 5) */
#define REG_DMAC_CFG5   (*(RwReg*)0x400C4118U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 5) */
#define REG_DMAC_WPMR   (*(RwReg*)0x400C41E4U) /**< \brief (DMAC) DMAC Write Protect Mode Register */
#define REG_DMAC_WPSR   (*(RoReg*)0x400C41E8U) /**< \brief (DMAC) DMAC Write Protect Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3XA_DMAC_INSTANCE_ */
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

#ifndef _SAM3XA_DMAC_INSTANCE_
#define _SAM3XA_DMAC_INSTANCE_

/* ========== Register definition for DMAC peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_DMAC_GCFG            (0x400C4000U) /**< \brief (DMAC) DMAC Global Configuration Register */
#define REG_DMAC_EN              (0x400C4004U) /**< \brief (DMAC) DMAC Enable Register */
#define REG_DMAC_SREQ            (0x400C4008U) /**< \brief (DMAC) DMAC Software Single Request Register */
#define REG_DMAC_CREQ            (0x400C400CU) /**< \brief (DMAC) DMAC Software Chunk Transfer Request Register */
#define REG_DMAC_LAST            (0x400C4010U) /**< \brief (DMAC) DMAC Software Last Transfer Flag Register */
#define REG_DMAC_EBCIER          (0x400C4018U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Enable register. */
#define REG_DMAC_EBCIDR          (0x400C401CU) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Disable register. */
#define REG_DMAC_EBCIMR          (0x400C4020U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Mask Register. */
#define REG_DMAC_EBCISR          (0x400C4024U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Status Register. */
#define REG_DMAC_CHER            (0x400C4028U) /**< \brief (DMAC) DMAC Channel Handler Enable Register */
#define REG_DMAC_CHDR            (0x400C402CU) /**< \brief (DMAC) DMAC Channel Handler Disable Register */
#define REG_DMAC_CHSR            (0x400C4030U) /**< \brief (DMAC) DMAC Channel Handler Status Register */
#define REG_DMAC_SADDR0          (0x400C403CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 0) */
#define REG_DMAC_DADDR0          (0x400C4040U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 0) */
#define REG_DMAC_DSCR0           (0x400C4044U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 0) */
#define REG_DMAC_CTRLA0          (0x400C4048U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 0) */
#define REG_DMAC_CTRLB0          (0x400C404CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 0) */
#define REG_DMAC_CFG0            (0x400C4050U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 0) */
#define REG_DMAC_SADDR1          (0x400C4064U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 1) */
#define REG_DMAC_DADDR1          (0x400C4068U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 1) */
#define REG_DMAC_DSCR1           (0x400C406CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 1) */
#define REG_DMAC_CTRLA1          (0x400C4070U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 1) */
#define REG_DMAC_CTRLB1          (0x400C4074U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 1) */
#define REG_DMAC_CFG1            (0x400C4078U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 1) */
#define REG_DMAC_SADDR2          (0x400C408CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 2) */
#define REG_DMAC_DADDR2          (0x400C4090U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 2) */
#define REG_DMAC_DSCR2           (0x400C4094U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 2) */
#define REG_DMAC_CTRLA2          (0x400C4098U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 2) */
#define REG_DMAC_CTRLB2          (0x400C409CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 2) */
#define REG_DMAC_CFG2            (0x400C40A0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 2) */
#define REG_DMAC_SADDR3          (0x400C40B4U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 3) */
#define REG_DMAC_DADDR3          (0x400C40B8U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 3) */
#define REG_DMAC_DSCR3           (0x400C40BCU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 3) */
#define REG_DMAC_CTRLA3          (0x400C40C0U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 3) */
#define REG_DMAC_CTRLB3          (0x400C40C4U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 3) */
#define REG_DMAC_CFG3            (0x400C40C8U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 3) */
#define REG_DMAC_SADDR4          (0x400C40DCU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 4) */
#define REG_DMAC_DADDR4          (0x400C40E0U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 4) */
#define REG_DMAC_DSCR4           (0x400C40E4U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 4) */
#define REG_DMAC_CTRLA4          (0x400C40E8U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 4) */
#define REG_DMAC_CTRLB4          (0x400C40ECU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 4) */
#define REG_DMAC_CFG4            (0x400C40F0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 4) */
#define REG_DMAC_SADDR5          (0x400C4104U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 5) */
#define REG_DMAC_DADDR5          (0x400C4108U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 5) */
#define REG_DMAC_DSCR5           (0x400C410CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 5) */
#define REG_DMAC_CTRLA5          (0x400C4110U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 5) */
#define REG_DMAC_CTRLB5          (0x400C4114U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 5) */
#define REG_DMAC_CFG5            (0x400C4118U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 5) */
#define REG_DMAC_WPMR            (0x400C41E4U) /**< \brief (DMAC) DMAC Write Protect Mode Register */
#define REG_DMAC_WPSR            (0x400C41E8U) /**< \brief (DMAC) DMAC Write Protect Status Register */
#else
#define REG_DMAC_GCFG   (*(RwReg*)0x400C4000U) /**< \brief (DMAC) DMAC Global Configuration Register */
#define REG_DMAC_EN     (*(RwReg*)0x400C4004U) /**< \brief (DMAC) DMAC Enable Register */
#define REG_DMAC_SREQ   (*(RwReg*)0x400C4008U) /**< \brief (DMAC) DMAC Software Single Request Register */
#define REG_DMAC_CREQ   (*(RwReg*)0x400C400CU) /**< \brief (DMAC) DMAC Software Chunk Transfer Request Register */
#define REG_DMAC_LAST   (*(RwReg*)0x400C4010U) /**< \brief (DMAC) DMAC Software Last Transfer Flag Register */
#define REG_DMAC_EBCIER (*(WoReg*)0x400C4018U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Enable register. */
#define REG_DMAC_EBCIDR (*(WoReg*)0x400C401CU) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Disable register. */
#define REG_DMAC_EBCIMR (*(RoReg*)0x400C4020U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Mask Register. */
#define REG_DMAC_EBCISR (*(RoReg*)0x400C4024U) /**< \brief (DMAC) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Status Register. */
#define REG_DMAC_CHER   (*(WoReg*)0x400C4028U) /**< \brief (DMAC) DMAC Channel Handler Enable Register */
#define REG_DMAC_CHDR   (*(WoReg*)0x400C402CU) /**< \brief (DMAC) DMAC Channel Handler Disable Register */
#define REG_DMAC_CHSR   (*(RoReg*)0x400C4030U) /**< \brief (DMAC) DMAC Channel Handler Status Register */
#define REG_DMAC_SADDR0 (*(RwReg*)0x400C403CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 0) */
#define REG_DMAC_DADDR0 (*(RwReg*)0x400C4040U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 0) */
#define REG_DMAC_DSCR0  (*(RwReg*)0x400C4044U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 0) */
#define REG_DMAC_CTRLA0 (*(RwReg*)0x400C4048U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 0) */
#define REG_DMAC_CTRLB0 (*(RwReg*)0x400C404CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 0) */
#define REG_DMAC_CFG0   (*(RwReg*)0x400C4050U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 0) */
#define REG_DMAC_SADDR1 (*(RwReg*)0x400C4064U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 1) */
#define REG_DMAC_DADDR1 (*(RwReg*)0x400C4068U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 1) */
#define REG_DMAC_DSCR1  (*(RwReg*)0x400C406CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 1) */
#define REG_DMAC_CTRLA1 (*(RwReg*)0x400C4070U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 1) */
#define REG_DMAC_CTRLB1 (*(RwReg*)0x400C4074U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 1) */
#define REG_DMAC_CFG1   (*(RwReg*)0x400C4078U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 1) */
#define REG_DMAC_SADDR2 (*(RwReg*)0x400C408CU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 2) */
#define REG_DMAC_DADDR2 (*(RwReg*)0x400C4090U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 2) */
#define REG_DMAC_DSCR2  (*(RwReg*)0x400C4094U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 2) */
#define REG_DMAC_CTRLA2 (*(RwReg*)0x400C4098U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 2) */
#define REG_DMAC_CTRLB2 (*(RwReg*)0x400C409CU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 2) */
#define REG_DMAC_CFG2   (*(RwReg*)0x400C40A0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 2) */
#define REG_DMAC_SADDR3 (*(RwReg*)0x400C40B4U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 3) */
#define REG_DMAC_DADDR3 (*(RwReg*)0x400C40B8U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 3) */
#define REG_DMAC_DSCR3  (*(RwReg*)0x400C40BCU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 3) */
#define REG_DMAC_CTRLA3 (*(RwReg*)0x400C40C0U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 3) */
#define REG_DMAC_CTRLB3 (*(RwReg*)0x400C40C4U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 3) */
#define REG_DMAC_CFG3   (*(RwReg*)0x400C40C8U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 3) */
#define REG_DMAC_SADDR4 (*(RwReg*)0x400C40DCU) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 4) */
#define REG_DMAC_DADDR4 (*(RwReg*)0x400C40E0U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 4) */
#define REG_DMAC_DSCR4  (*(RwReg*)0x400C40E4U) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 4) */
#define REG_DMAC_CTRLA4 (*(RwReg*)0x400C40E8U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 4) */
#define REG_DMAC_CTRLB4 (*(RwReg*)0x400C40ECU) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 4) */
#define REG_DMAC_CFG4   (*(RwReg*)0x400C40F0U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 4) */
#define REG_DMAC_SADDR5 (*(RwReg*)0x400C4104U) /**< \brief (DMAC) DMAC Channel Source Address Register (ch_num = 5) */
#define REG_DMAC_DADDR5 (*(RwReg*)0x400C4108U) /**< \brief (DMAC) DMAC Channel Destination Address Register (ch_num = 5) */
#define REG_DMAC_DSCR5  (*(RwReg*)0x400C410CU) /**< \brief (DMAC) DMAC Channel Descriptor Address Register (ch_num = 5) */
#define REG_DMAC_CTRLA5 (*(RwReg*)0x400C4110U) /**< \brief (DMAC) DMAC Channel Control A Register (ch_num = 5) */
#define REG_DMAC_CTRLB5 (*(RwReg*)0x400C4114U) /**< \brief (DMAC) DMAC Channel Control B Register (ch_num = 5) */
#define REG_DMAC_CFG5   (*(RwReg*)0x400C4118U) /**< \brief (DMAC) DMAC Channel Configuration Register (ch_num = 5) */
#define REG_DMAC_WPMR   (*(RwReg*)0x400C41E4U) /**< \brief (DMAC) DMAC Write Protect Mode Register */
#define REG_DMAC_WPSR   (*(RoReg*)0x400C41E8U) /**< \brief (DMAC) DMAC Write Protect Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3XA_DMAC_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)
