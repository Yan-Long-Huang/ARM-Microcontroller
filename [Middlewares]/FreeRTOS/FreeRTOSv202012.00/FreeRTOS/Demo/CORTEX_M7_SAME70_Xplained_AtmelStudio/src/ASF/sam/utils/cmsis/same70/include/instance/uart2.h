<<<<<<< HEAD
/**
 * \file
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _SAME70_UART2_INSTANCE_
#define _SAME70_UART2_INSTANCE_

/* ========== Register definition for UART2 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_UART2_CR                    (0x400E1A00U) /**< \brief (UART2) Control Register */
  #define REG_UART2_MR                    (0x400E1A04U) /**< \brief (UART2) Mode Register */
  #define REG_UART2_IER                   (0x400E1A08U) /**< \brief (UART2) Interrupt Enable Register */
  #define REG_UART2_IDR                   (0x400E1A0CU) /**< \brief (UART2) Interrupt Disable Register */
  #define REG_UART2_IMR                   (0x400E1A10U) /**< \brief (UART2) Interrupt Mask Register */
  #define REG_UART2_SR                    (0x400E1A14U) /**< \brief (UART2) Status Register */
  #define REG_UART2_RHR                   (0x400E1A18U) /**< \brief (UART2) Receive Holding Register */
  #define REG_UART2_THR                   (0x400E1A1CU) /**< \brief (UART2) Transmit Holding Register */
  #define REG_UART2_BRGR                  (0x400E1A20U) /**< \brief (UART2) Baud Rate Generator Register */
  #define REG_UART2_CMPR                  (0x400E1A24U) /**< \brief (UART2) Comparison Register */
  #define REG_UART2_WPMR                  (0x400E1AE4U) /**< \brief (UART2) Write Protection Mode Register */
#else
  #define REG_UART2_CR   (*(__O  uint32_t*)0x400E1A00U) /**< \brief (UART2) Control Register */
  #define REG_UART2_MR   (*(__IO uint32_t*)0x400E1A04U) /**< \brief (UART2) Mode Register */
  #define REG_UART2_IER  (*(__O  uint32_t*)0x400E1A08U) /**< \brief (UART2) Interrupt Enable Register */
  #define REG_UART2_IDR  (*(__O  uint32_t*)0x400E1A0CU) /**< \brief (UART2) Interrupt Disable Register */
  #define REG_UART2_IMR  (*(__I  uint32_t*)0x400E1A10U) /**< \brief (UART2) Interrupt Mask Register */
  #define REG_UART2_SR   (*(__I  uint32_t*)0x400E1A14U) /**< \brief (UART2) Status Register */
  #define REG_UART2_RHR  (*(__I  uint32_t*)0x400E1A18U) /**< \brief (UART2) Receive Holding Register */
  #define REG_UART2_THR  (*(__O  uint32_t*)0x400E1A1CU) /**< \brief (UART2) Transmit Holding Register */
  #define REG_UART2_BRGR (*(__IO uint32_t*)0x400E1A20U) /**< \brief (UART2) Baud Rate Generator Register */
  #define REG_UART2_CMPR (*(__IO uint32_t*)0x400E1A24U) /**< \brief (UART2) Comparison Register */
  #define REG_UART2_WPMR (*(__IO uint32_t*)0x400E1AE4U) /**< \brief (UART2) Write Protection Mode Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAME70_UART2_INSTANCE_ */
=======
/**
 * \file
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _SAME70_UART2_INSTANCE_
#define _SAME70_UART2_INSTANCE_

/* ========== Register definition for UART2 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_UART2_CR                    (0x400E1A00U) /**< \brief (UART2) Control Register */
  #define REG_UART2_MR                    (0x400E1A04U) /**< \brief (UART2) Mode Register */
  #define REG_UART2_IER                   (0x400E1A08U) /**< \brief (UART2) Interrupt Enable Register */
  #define REG_UART2_IDR                   (0x400E1A0CU) /**< \brief (UART2) Interrupt Disable Register */
  #define REG_UART2_IMR                   (0x400E1A10U) /**< \brief (UART2) Interrupt Mask Register */
  #define REG_UART2_SR                    (0x400E1A14U) /**< \brief (UART2) Status Register */
  #define REG_UART2_RHR                   (0x400E1A18U) /**< \brief (UART2) Receive Holding Register */
  #define REG_UART2_THR                   (0x400E1A1CU) /**< \brief (UART2) Transmit Holding Register */
  #define REG_UART2_BRGR                  (0x400E1A20U) /**< \brief (UART2) Baud Rate Generator Register */
  #define REG_UART2_CMPR                  (0x400E1A24U) /**< \brief (UART2) Comparison Register */
  #define REG_UART2_WPMR                  (0x400E1AE4U) /**< \brief (UART2) Write Protection Mode Register */
#else
  #define REG_UART2_CR   (*(__O  uint32_t*)0x400E1A00U) /**< \brief (UART2) Control Register */
  #define REG_UART2_MR   (*(__IO uint32_t*)0x400E1A04U) /**< \brief (UART2) Mode Register */
  #define REG_UART2_IER  (*(__O  uint32_t*)0x400E1A08U) /**< \brief (UART2) Interrupt Enable Register */
  #define REG_UART2_IDR  (*(__O  uint32_t*)0x400E1A0CU) /**< \brief (UART2) Interrupt Disable Register */
  #define REG_UART2_IMR  (*(__I  uint32_t*)0x400E1A10U) /**< \brief (UART2) Interrupt Mask Register */
  #define REG_UART2_SR   (*(__I  uint32_t*)0x400E1A14U) /**< \brief (UART2) Status Register */
  #define REG_UART2_RHR  (*(__I  uint32_t*)0x400E1A18U) /**< \brief (UART2) Receive Holding Register */
  #define REG_UART2_THR  (*(__O  uint32_t*)0x400E1A1CU) /**< \brief (UART2) Transmit Holding Register */
  #define REG_UART2_BRGR (*(__IO uint32_t*)0x400E1A20U) /**< \brief (UART2) Baud Rate Generator Register */
  #define REG_UART2_CMPR (*(__IO uint32_t*)0x400E1A24U) /**< \brief (UART2) Comparison Register */
  #define REG_UART2_WPMR (*(__IO uint32_t*)0x400E1AE4U) /**< \brief (UART2) Write Protection Mode Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAME70_UART2_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)
