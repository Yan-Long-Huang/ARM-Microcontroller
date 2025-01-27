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

#ifndef _SAM3XA_PIOA_INSTANCE_
#define _SAM3XA_PIOA_INSTANCE_

/* ========== Register definition for PIOA peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_PIOA_PER             (0x400E0E00U) /**< \brief (PIOA) PIO Enable Register */
#define REG_PIOA_PDR             (0x400E0E04U) /**< \brief (PIOA) PIO Disable Register */
#define REG_PIOA_PSR             (0x400E0E08U) /**< \brief (PIOA) PIO Status Register */
#define REG_PIOA_OER             (0x400E0E10U) /**< \brief (PIOA) Output Enable Register */
#define REG_PIOA_ODR             (0x400E0E14U) /**< \brief (PIOA) Output Disable Register */
#define REG_PIOA_OSR             (0x400E0E18U) /**< \brief (PIOA) Output Status Register */
#define REG_PIOA_IFER            (0x400E0E20U) /**< \brief (PIOA) Glitch Input Filter Enable Register */
#define REG_PIOA_IFDR            (0x400E0E24U) /**< \brief (PIOA) Glitch Input Filter Disable Register */
#define REG_PIOA_IFSR            (0x400E0E28U) /**< \brief (PIOA) Glitch Input Filter Status Register */
#define REG_PIOA_SODR            (0x400E0E30U) /**< \brief (PIOA) Set Output Data Register */
#define REG_PIOA_CODR            (0x400E0E34U) /**< \brief (PIOA) Clear Output Data Register */
#define REG_PIOA_ODSR            (0x400E0E38U) /**< \brief (PIOA) Output Data Status Register */
#define REG_PIOA_PDSR            (0x400E0E3CU) /**< \brief (PIOA) Pin Data Status Register */
#define REG_PIOA_IER             (0x400E0E40U) /**< \brief (PIOA) Interrupt Enable Register */
#define REG_PIOA_IDR             (0x400E0E44U) /**< \brief (PIOA) Interrupt Disable Register */
#define REG_PIOA_IMR             (0x400E0E48U) /**< \brief (PIOA) Interrupt Mask Register */
#define REG_PIOA_ISR             (0x400E0E4CU) /**< \brief (PIOA) Interrupt Status Register */
#define REG_PIOA_MDER            (0x400E0E50U) /**< \brief (PIOA) Multi-driver Enable Register */
#define REG_PIOA_MDDR            (0x400E0E54U) /**< \brief (PIOA) Multi-driver Disable Register */
#define REG_PIOA_MDSR            (0x400E0E58U) /**< \brief (PIOA) Multi-driver Status Register */
#define REG_PIOA_PUDR            (0x400E0E60U) /**< \brief (PIOA) Pull-up Disable Register */
#define REG_PIOA_PUER            (0x400E0E64U) /**< \brief (PIOA) Pull-up Enable Register */
#define REG_PIOA_PUSR            (0x400E0E68U) /**< \brief (PIOA) Pad Pull-up Status Register */
#define REG_PIOA_ABSR            (0x400E0E70U) /**< \brief (PIOA) Peripheral AB Select Register */
#define REG_PIOA_SCIFSR          (0x400E0E80U) /**< \brief (PIOA) System Clock Glitch Input Filter Select Register */
#define REG_PIOA_DIFSR           (0x400E0E84U) /**< \brief (PIOA) Debouncing Input Filter Select Register */
#define REG_PIOA_IFDGSR          (0x400E0E88U) /**< \brief (PIOA) Glitch or Debouncing Input Filter Clock Selection Status Register */
#define REG_PIOA_SCDR            (0x400E0E8CU) /**< \brief (PIOA) Slow Clock Divider Debouncing Register */
#define REG_PIOA_OWER            (0x400E0EA0U) /**< \brief (PIOA) Output Write Enable */
#define REG_PIOA_OWDR            (0x400E0EA4U) /**< \brief (PIOA) Output Write Disable */
#define REG_PIOA_OWSR            (0x400E0EA8U) /**< \brief (PIOA) Output Write Status Register */
#define REG_PIOA_AIMER           (0x400E0EB0U) /**< \brief (PIOA) Additional Interrupt Modes Enable Register */
#define REG_PIOA_AIMDR           (0x400E0EB4U) /**< \brief (PIOA) Additional Interrupt Modes Disables Register */
#define REG_PIOA_AIMMR           (0x400E0EB8U) /**< \brief (PIOA) Additional Interrupt Modes Mask Register */
#define REG_PIOA_ESR             (0x400E0EC0U) /**< \brief (PIOA) Edge Select Register */
#define REG_PIOA_LSR             (0x400E0EC4U) /**< \brief (PIOA) Level Select Register */
#define REG_PIOA_ELSR            (0x400E0EC8U) /**< \brief (PIOA) Edge/Level Status Register */
#define REG_PIOA_FELLSR          (0x400E0ED0U) /**< \brief (PIOA) Falling Edge/Low Level Select Register */
#define REG_PIOA_REHLSR          (0x400E0ED4U) /**< \brief (PIOA) Rising Edge/ High Level Select Register */
#define REG_PIOA_FRLHSR          (0x400E0ED8U) /**< \brief (PIOA) Fall/Rise - Low/High Status Register */
#define REG_PIOA_LOCKSR          (0x400E0EE0U) /**< \brief (PIOA) Lock Status */
#define REG_PIOA_WPMR            (0x400E0EE4U) /**< \brief (PIOA) Write Protect Mode Register */
#define REG_PIOA_WPSR            (0x400E0EE8U) /**< \brief (PIOA) Write Protect Status Register */
#else
#define REG_PIOA_PER    (*(WoReg*)0x400E0E00U) /**< \brief (PIOA) PIO Enable Register */
#define REG_PIOA_PDR    (*(WoReg*)0x400E0E04U) /**< \brief (PIOA) PIO Disable Register */
#define REG_PIOA_PSR    (*(RoReg*)0x400E0E08U) /**< \brief (PIOA) PIO Status Register */
#define REG_PIOA_OER    (*(WoReg*)0x400E0E10U) /**< \brief (PIOA) Output Enable Register */
#define REG_PIOA_ODR    (*(WoReg*)0x400E0E14U) /**< \brief (PIOA) Output Disable Register */
#define REG_PIOA_OSR    (*(RoReg*)0x400E0E18U) /**< \brief (PIOA) Output Status Register */
#define REG_PIOA_IFER   (*(WoReg*)0x400E0E20U) /**< \brief (PIOA) Glitch Input Filter Enable Register */
#define REG_PIOA_IFDR   (*(WoReg*)0x400E0E24U) /**< \brief (PIOA) Glitch Input Filter Disable Register */
#define REG_PIOA_IFSR   (*(RoReg*)0x400E0E28U) /**< \brief (PIOA) Glitch Input Filter Status Register */
#define REG_PIOA_SODR   (*(WoReg*)0x400E0E30U) /**< \brief (PIOA) Set Output Data Register */
#define REG_PIOA_CODR   (*(WoReg*)0x400E0E34U) /**< \brief (PIOA) Clear Output Data Register */
#define REG_PIOA_ODSR   (*(RwReg*)0x400E0E38U) /**< \brief (PIOA) Output Data Status Register */
#define REG_PIOA_PDSR   (*(RoReg*)0x400E0E3CU) /**< \brief (PIOA) Pin Data Status Register */
#define REG_PIOA_IER    (*(WoReg*)0x400E0E40U) /**< \brief (PIOA) Interrupt Enable Register */
#define REG_PIOA_IDR    (*(WoReg*)0x400E0E44U) /**< \brief (PIOA) Interrupt Disable Register */
#define REG_PIOA_IMR    (*(RoReg*)0x400E0E48U) /**< \brief (PIOA) Interrupt Mask Register */
#define REG_PIOA_ISR    (*(RoReg*)0x400E0E4CU) /**< \brief (PIOA) Interrupt Status Register */
#define REG_PIOA_MDER   (*(WoReg*)0x400E0E50U) /**< \brief (PIOA) Multi-driver Enable Register */
#define REG_PIOA_MDDR   (*(WoReg*)0x400E0E54U) /**< \brief (PIOA) Multi-driver Disable Register */
#define REG_PIOA_MDSR   (*(RoReg*)0x400E0E58U) /**< \brief (PIOA) Multi-driver Status Register */
#define REG_PIOA_PUDR   (*(WoReg*)0x400E0E60U) /**< \brief (PIOA) Pull-up Disable Register */
#define REG_PIOA_PUER   (*(WoReg*)0x400E0E64U) /**< \brief (PIOA) Pull-up Enable Register */
#define REG_PIOA_PUSR   (*(RoReg*)0x400E0E68U) /**< \brief (PIOA) Pad Pull-up Status Register */
#define REG_PIOA_ABSR   (*(RwReg*)0x400E0E70U) /**< \brief (PIOA) Peripheral AB Select Register */
#define REG_PIOA_SCIFSR (*(WoReg*)0x400E0E80U) /**< \brief (PIOA) System Clock Glitch Input Filter Select Register */
#define REG_PIOA_DIFSR  (*(WoReg*)0x400E0E84U) /**< \brief (PIOA) Debouncing Input Filter Select Register */
#define REG_PIOA_IFDGSR (*(RoReg*)0x400E0E88U) /**< \brief (PIOA) Glitch or Debouncing Input Filter Clock Selection Status Register */
#define REG_PIOA_SCDR   (*(RwReg*)0x400E0E8CU) /**< \brief (PIOA) Slow Clock Divider Debouncing Register */
#define REG_PIOA_OWER   (*(WoReg*)0x400E0EA0U) /**< \brief (PIOA) Output Write Enable */
#define REG_PIOA_OWDR   (*(WoReg*)0x400E0EA4U) /**< \brief (PIOA) Output Write Disable */
#define REG_PIOA_OWSR   (*(RoReg*)0x400E0EA8U) /**< \brief (PIOA) Output Write Status Register */
#define REG_PIOA_AIMER  (*(WoReg*)0x400E0EB0U) /**< \brief (PIOA) Additional Interrupt Modes Enable Register */
#define REG_PIOA_AIMDR  (*(WoReg*)0x400E0EB4U) /**< \brief (PIOA) Additional Interrupt Modes Disables Register */
#define REG_PIOA_AIMMR  (*(RoReg*)0x400E0EB8U) /**< \brief (PIOA) Additional Interrupt Modes Mask Register */
#define REG_PIOA_ESR    (*(WoReg*)0x400E0EC0U) /**< \brief (PIOA) Edge Select Register */
#define REG_PIOA_LSR    (*(WoReg*)0x400E0EC4U) /**< \brief (PIOA) Level Select Register */
#define REG_PIOA_ELSR   (*(RoReg*)0x400E0EC8U) /**< \brief (PIOA) Edge/Level Status Register */
#define REG_PIOA_FELLSR (*(WoReg*)0x400E0ED0U) /**< \brief (PIOA) Falling Edge/Low Level Select Register */
#define REG_PIOA_REHLSR (*(WoReg*)0x400E0ED4U) /**< \brief (PIOA) Rising Edge/ High Level Select Register */
#define REG_PIOA_FRLHSR (*(RoReg*)0x400E0ED8U) /**< \brief (PIOA) Fall/Rise - Low/High Status Register */
#define REG_PIOA_LOCKSR (*(RoReg*)0x400E0EE0U) /**< \brief (PIOA) Lock Status */
#define REG_PIOA_WPMR   (*(RwReg*)0x400E0EE4U) /**< \brief (PIOA) Write Protect Mode Register */
#define REG_PIOA_WPSR   (*(RoReg*)0x400E0EE8U) /**< \brief (PIOA) Write Protect Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3XA_PIOA_INSTANCE_ */
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

#ifndef _SAM3XA_PIOA_INSTANCE_
#define _SAM3XA_PIOA_INSTANCE_

/* ========== Register definition for PIOA peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_PIOA_PER             (0x400E0E00U) /**< \brief (PIOA) PIO Enable Register */
#define REG_PIOA_PDR             (0x400E0E04U) /**< \brief (PIOA) PIO Disable Register */
#define REG_PIOA_PSR             (0x400E0E08U) /**< \brief (PIOA) PIO Status Register */
#define REG_PIOA_OER             (0x400E0E10U) /**< \brief (PIOA) Output Enable Register */
#define REG_PIOA_ODR             (0x400E0E14U) /**< \brief (PIOA) Output Disable Register */
#define REG_PIOA_OSR             (0x400E0E18U) /**< \brief (PIOA) Output Status Register */
#define REG_PIOA_IFER            (0x400E0E20U) /**< \brief (PIOA) Glitch Input Filter Enable Register */
#define REG_PIOA_IFDR            (0x400E0E24U) /**< \brief (PIOA) Glitch Input Filter Disable Register */
#define REG_PIOA_IFSR            (0x400E0E28U) /**< \brief (PIOA) Glitch Input Filter Status Register */
#define REG_PIOA_SODR            (0x400E0E30U) /**< \brief (PIOA) Set Output Data Register */
#define REG_PIOA_CODR            (0x400E0E34U) /**< \brief (PIOA) Clear Output Data Register */
#define REG_PIOA_ODSR            (0x400E0E38U) /**< \brief (PIOA) Output Data Status Register */
#define REG_PIOA_PDSR            (0x400E0E3CU) /**< \brief (PIOA) Pin Data Status Register */
#define REG_PIOA_IER             (0x400E0E40U) /**< \brief (PIOA) Interrupt Enable Register */
#define REG_PIOA_IDR             (0x400E0E44U) /**< \brief (PIOA) Interrupt Disable Register */
#define REG_PIOA_IMR             (0x400E0E48U) /**< \brief (PIOA) Interrupt Mask Register */
#define REG_PIOA_ISR             (0x400E0E4CU) /**< \brief (PIOA) Interrupt Status Register */
#define REG_PIOA_MDER            (0x400E0E50U) /**< \brief (PIOA) Multi-driver Enable Register */
#define REG_PIOA_MDDR            (0x400E0E54U) /**< \brief (PIOA) Multi-driver Disable Register */
#define REG_PIOA_MDSR            (0x400E0E58U) /**< \brief (PIOA) Multi-driver Status Register */
#define REG_PIOA_PUDR            (0x400E0E60U) /**< \brief (PIOA) Pull-up Disable Register */
#define REG_PIOA_PUER            (0x400E0E64U) /**< \brief (PIOA) Pull-up Enable Register */
#define REG_PIOA_PUSR            (0x400E0E68U) /**< \brief (PIOA) Pad Pull-up Status Register */
#define REG_PIOA_ABSR            (0x400E0E70U) /**< \brief (PIOA) Peripheral AB Select Register */
#define REG_PIOA_SCIFSR          (0x400E0E80U) /**< \brief (PIOA) System Clock Glitch Input Filter Select Register */
#define REG_PIOA_DIFSR           (0x400E0E84U) /**< \brief (PIOA) Debouncing Input Filter Select Register */
#define REG_PIOA_IFDGSR          (0x400E0E88U) /**< \brief (PIOA) Glitch or Debouncing Input Filter Clock Selection Status Register */
#define REG_PIOA_SCDR            (0x400E0E8CU) /**< \brief (PIOA) Slow Clock Divider Debouncing Register */
#define REG_PIOA_OWER            (0x400E0EA0U) /**< \brief (PIOA) Output Write Enable */
#define REG_PIOA_OWDR            (0x400E0EA4U) /**< \brief (PIOA) Output Write Disable */
#define REG_PIOA_OWSR            (0x400E0EA8U) /**< \brief (PIOA) Output Write Status Register */
#define REG_PIOA_AIMER           (0x400E0EB0U) /**< \brief (PIOA) Additional Interrupt Modes Enable Register */
#define REG_PIOA_AIMDR           (0x400E0EB4U) /**< \brief (PIOA) Additional Interrupt Modes Disables Register */
#define REG_PIOA_AIMMR           (0x400E0EB8U) /**< \brief (PIOA) Additional Interrupt Modes Mask Register */
#define REG_PIOA_ESR             (0x400E0EC0U) /**< \brief (PIOA) Edge Select Register */
#define REG_PIOA_LSR             (0x400E0EC4U) /**< \brief (PIOA) Level Select Register */
#define REG_PIOA_ELSR            (0x400E0EC8U) /**< \brief (PIOA) Edge/Level Status Register */
#define REG_PIOA_FELLSR          (0x400E0ED0U) /**< \brief (PIOA) Falling Edge/Low Level Select Register */
#define REG_PIOA_REHLSR          (0x400E0ED4U) /**< \brief (PIOA) Rising Edge/ High Level Select Register */
#define REG_PIOA_FRLHSR          (0x400E0ED8U) /**< \brief (PIOA) Fall/Rise - Low/High Status Register */
#define REG_PIOA_LOCKSR          (0x400E0EE0U) /**< \brief (PIOA) Lock Status */
#define REG_PIOA_WPMR            (0x400E0EE4U) /**< \brief (PIOA) Write Protect Mode Register */
#define REG_PIOA_WPSR            (0x400E0EE8U) /**< \brief (PIOA) Write Protect Status Register */
#else
#define REG_PIOA_PER    (*(WoReg*)0x400E0E00U) /**< \brief (PIOA) PIO Enable Register */
#define REG_PIOA_PDR    (*(WoReg*)0x400E0E04U) /**< \brief (PIOA) PIO Disable Register */
#define REG_PIOA_PSR    (*(RoReg*)0x400E0E08U) /**< \brief (PIOA) PIO Status Register */
#define REG_PIOA_OER    (*(WoReg*)0x400E0E10U) /**< \brief (PIOA) Output Enable Register */
#define REG_PIOA_ODR    (*(WoReg*)0x400E0E14U) /**< \brief (PIOA) Output Disable Register */
#define REG_PIOA_OSR    (*(RoReg*)0x400E0E18U) /**< \brief (PIOA) Output Status Register */
#define REG_PIOA_IFER   (*(WoReg*)0x400E0E20U) /**< \brief (PIOA) Glitch Input Filter Enable Register */
#define REG_PIOA_IFDR   (*(WoReg*)0x400E0E24U) /**< \brief (PIOA) Glitch Input Filter Disable Register */
#define REG_PIOA_IFSR   (*(RoReg*)0x400E0E28U) /**< \brief (PIOA) Glitch Input Filter Status Register */
#define REG_PIOA_SODR   (*(WoReg*)0x400E0E30U) /**< \brief (PIOA) Set Output Data Register */
#define REG_PIOA_CODR   (*(WoReg*)0x400E0E34U) /**< \brief (PIOA) Clear Output Data Register */
#define REG_PIOA_ODSR   (*(RwReg*)0x400E0E38U) /**< \brief (PIOA) Output Data Status Register */
#define REG_PIOA_PDSR   (*(RoReg*)0x400E0E3CU) /**< \brief (PIOA) Pin Data Status Register */
#define REG_PIOA_IER    (*(WoReg*)0x400E0E40U) /**< \brief (PIOA) Interrupt Enable Register */
#define REG_PIOA_IDR    (*(WoReg*)0x400E0E44U) /**< \brief (PIOA) Interrupt Disable Register */
#define REG_PIOA_IMR    (*(RoReg*)0x400E0E48U) /**< \brief (PIOA) Interrupt Mask Register */
#define REG_PIOA_ISR    (*(RoReg*)0x400E0E4CU) /**< \brief (PIOA) Interrupt Status Register */
#define REG_PIOA_MDER   (*(WoReg*)0x400E0E50U) /**< \brief (PIOA) Multi-driver Enable Register */
#define REG_PIOA_MDDR   (*(WoReg*)0x400E0E54U) /**< \brief (PIOA) Multi-driver Disable Register */
#define REG_PIOA_MDSR   (*(RoReg*)0x400E0E58U) /**< \brief (PIOA) Multi-driver Status Register */
#define REG_PIOA_PUDR   (*(WoReg*)0x400E0E60U) /**< \brief (PIOA) Pull-up Disable Register */
#define REG_PIOA_PUER   (*(WoReg*)0x400E0E64U) /**< \brief (PIOA) Pull-up Enable Register */
#define REG_PIOA_PUSR   (*(RoReg*)0x400E0E68U) /**< \brief (PIOA) Pad Pull-up Status Register */
#define REG_PIOA_ABSR   (*(RwReg*)0x400E0E70U) /**< \brief (PIOA) Peripheral AB Select Register */
#define REG_PIOA_SCIFSR (*(WoReg*)0x400E0E80U) /**< \brief (PIOA) System Clock Glitch Input Filter Select Register */
#define REG_PIOA_DIFSR  (*(WoReg*)0x400E0E84U) /**< \brief (PIOA) Debouncing Input Filter Select Register */
#define REG_PIOA_IFDGSR (*(RoReg*)0x400E0E88U) /**< \brief (PIOA) Glitch or Debouncing Input Filter Clock Selection Status Register */
#define REG_PIOA_SCDR   (*(RwReg*)0x400E0E8CU) /**< \brief (PIOA) Slow Clock Divider Debouncing Register */
#define REG_PIOA_OWER   (*(WoReg*)0x400E0EA0U) /**< \brief (PIOA) Output Write Enable */
#define REG_PIOA_OWDR   (*(WoReg*)0x400E0EA4U) /**< \brief (PIOA) Output Write Disable */
#define REG_PIOA_OWSR   (*(RoReg*)0x400E0EA8U) /**< \brief (PIOA) Output Write Status Register */
#define REG_PIOA_AIMER  (*(WoReg*)0x400E0EB0U) /**< \brief (PIOA) Additional Interrupt Modes Enable Register */
#define REG_PIOA_AIMDR  (*(WoReg*)0x400E0EB4U) /**< \brief (PIOA) Additional Interrupt Modes Disables Register */
#define REG_PIOA_AIMMR  (*(RoReg*)0x400E0EB8U) /**< \brief (PIOA) Additional Interrupt Modes Mask Register */
#define REG_PIOA_ESR    (*(WoReg*)0x400E0EC0U) /**< \brief (PIOA) Edge Select Register */
#define REG_PIOA_LSR    (*(WoReg*)0x400E0EC4U) /**< \brief (PIOA) Level Select Register */
#define REG_PIOA_ELSR   (*(RoReg*)0x400E0EC8U) /**< \brief (PIOA) Edge/Level Status Register */
#define REG_PIOA_FELLSR (*(WoReg*)0x400E0ED0U) /**< \brief (PIOA) Falling Edge/Low Level Select Register */
#define REG_PIOA_REHLSR (*(WoReg*)0x400E0ED4U) /**< \brief (PIOA) Rising Edge/ High Level Select Register */
#define REG_PIOA_FRLHSR (*(RoReg*)0x400E0ED8U) /**< \brief (PIOA) Fall/Rise - Low/High Status Register */
#define REG_PIOA_LOCKSR (*(RoReg*)0x400E0EE0U) /**< \brief (PIOA) Lock Status */
#define REG_PIOA_WPMR   (*(RwReg*)0x400E0EE4U) /**< \brief (PIOA) Write Protect Mode Register */
#define REG_PIOA_WPSR   (*(RoReg*)0x400E0EE8U) /**< \brief (PIOA) Write Protect Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3XA_PIOA_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)
