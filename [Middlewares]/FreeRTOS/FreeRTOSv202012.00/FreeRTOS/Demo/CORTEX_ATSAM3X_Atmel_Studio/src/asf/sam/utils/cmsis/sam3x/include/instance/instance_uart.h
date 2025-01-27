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

#ifndef _SAM3XA_UART_INSTANCE_
#define _SAM3XA_UART_INSTANCE_

/* ========== Register definition for UART peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_UART_CR            (0x400E0800U) /**< \brief (UART) Control Register */
#define REG_UART_MR            (0x400E0804U) /**< \brief (UART) Mode Register */
#define REG_UART_IER           (0x400E0808U) /**< \brief (UART) Interrupt Enable Register */
#define REG_UART_IDR           (0x400E080CU) /**< \brief (UART) Interrupt Disable Register */
#define REG_UART_IMR           (0x400E0810U) /**< \brief (UART) Interrupt Mask Register */
#define REG_UART_SR            (0x400E0814U) /**< \brief (UART) Status Register */
#define REG_UART_RHR           (0x400E0818U) /**< \brief (UART) Receive Holding Register */
#define REG_UART_THR           (0x400E081CU) /**< \brief (UART) Transmit Holding Register */
#define REG_UART_BRGR          (0x400E0820U) /**< \brief (UART) Baud Rate Generator Register */
#define REG_UART_RPR           (0x400E0900U) /**< \brief (UART) Receive Pointer Register */
#define REG_UART_RCR           (0x400E0904U) /**< \brief (UART) Receive Counter Register */
#define REG_UART_TPR           (0x400E0908U) /**< \brief (UART) Transmit Pointer Register */
#define REG_UART_TCR           (0x400E090CU) /**< \brief (UART) Transmit Counter Register */
#define REG_UART_RNPR          (0x400E0910U) /**< \brief (UART) Receive Next Pointer Register */
#define REG_UART_RNCR          (0x400E0914U) /**< \brief (UART) Receive Next Counter Register */
#define REG_UART_TNPR          (0x400E0918U) /**< \brief (UART) Transmit Next Pointer Register */
#define REG_UART_TNCR          (0x400E091CU) /**< \brief (UART) Transmit Next Counter Register */
#define REG_UART_PTCR          (0x400E0920U) /**< \brief (UART) Transfer Control Register */
#define REG_UART_PTSR          (0x400E0924U) /**< \brief (UART) Transfer Status Register */
#else
#define REG_UART_CR   (*(WoReg*)0x400E0800U) /**< \brief (UART) Control Register */
#define REG_UART_MR   (*(RwReg*)0x400E0804U) /**< \brief (UART) Mode Register */
#define REG_UART_IER  (*(WoReg*)0x400E0808U) /**< \brief (UART) Interrupt Enable Register */
#define REG_UART_IDR  (*(WoReg*)0x400E080CU) /**< \brief (UART) Interrupt Disable Register */
#define REG_UART_IMR  (*(RoReg*)0x400E0810U) /**< \brief (UART) Interrupt Mask Register */
#define REG_UART_SR   (*(RoReg*)0x400E0814U) /**< \brief (UART) Status Register */
#define REG_UART_RHR  (*(RoReg*)0x400E0818U) /**< \brief (UART) Receive Holding Register */
#define REG_UART_THR  (*(WoReg*)0x400E081CU) /**< \brief (UART) Transmit Holding Register */
#define REG_UART_BRGR (*(RwReg*)0x400E0820U) /**< \brief (UART) Baud Rate Generator Register */
#define REG_UART_RPR  (*(RwReg*)0x400E0900U) /**< \brief (UART) Receive Pointer Register */
#define REG_UART_RCR  (*(RwReg*)0x400E0904U) /**< \brief (UART) Receive Counter Register */
#define REG_UART_TPR  (*(RwReg*)0x400E0908U) /**< \brief (UART) Transmit Pointer Register */
#define REG_UART_TCR  (*(RwReg*)0x400E090CU) /**< \brief (UART) Transmit Counter Register */
#define REG_UART_RNPR (*(RwReg*)0x400E0910U) /**< \brief (UART) Receive Next Pointer Register */
#define REG_UART_RNCR (*(RwReg*)0x400E0914U) /**< \brief (UART) Receive Next Counter Register */
#define REG_UART_TNPR (*(RwReg*)0x400E0918U) /**< \brief (UART) Transmit Next Pointer Register */
#define REG_UART_TNCR (*(RwReg*)0x400E091CU) /**< \brief (UART) Transmit Next Counter Register */
#define REG_UART_PTCR (*(WoReg*)0x400E0920U) /**< \brief (UART) Transfer Control Register */
#define REG_UART_PTSR (*(RoReg*)0x400E0924U) /**< \brief (UART) Transfer Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3XA_UART_INSTANCE_ */
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

#ifndef _SAM3XA_UART_INSTANCE_
#define _SAM3XA_UART_INSTANCE_

/* ========== Register definition for UART peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_UART_CR            (0x400E0800U) /**< \brief (UART) Control Register */
#define REG_UART_MR            (0x400E0804U) /**< \brief (UART) Mode Register */
#define REG_UART_IER           (0x400E0808U) /**< \brief (UART) Interrupt Enable Register */
#define REG_UART_IDR           (0x400E080CU) /**< \brief (UART) Interrupt Disable Register */
#define REG_UART_IMR           (0x400E0810U) /**< \brief (UART) Interrupt Mask Register */
#define REG_UART_SR            (0x400E0814U) /**< \brief (UART) Status Register */
#define REG_UART_RHR           (0x400E0818U) /**< \brief (UART) Receive Holding Register */
#define REG_UART_THR           (0x400E081CU) /**< \brief (UART) Transmit Holding Register */
#define REG_UART_BRGR          (0x400E0820U) /**< \brief (UART) Baud Rate Generator Register */
#define REG_UART_RPR           (0x400E0900U) /**< \brief (UART) Receive Pointer Register */
#define REG_UART_RCR           (0x400E0904U) /**< \brief (UART) Receive Counter Register */
#define REG_UART_TPR           (0x400E0908U) /**< \brief (UART) Transmit Pointer Register */
#define REG_UART_TCR           (0x400E090CU) /**< \brief (UART) Transmit Counter Register */
#define REG_UART_RNPR          (0x400E0910U) /**< \brief (UART) Receive Next Pointer Register */
#define REG_UART_RNCR          (0x400E0914U) /**< \brief (UART) Receive Next Counter Register */
#define REG_UART_TNPR          (0x400E0918U) /**< \brief (UART) Transmit Next Pointer Register */
#define REG_UART_TNCR          (0x400E091CU) /**< \brief (UART) Transmit Next Counter Register */
#define REG_UART_PTCR          (0x400E0920U) /**< \brief (UART) Transfer Control Register */
#define REG_UART_PTSR          (0x400E0924U) /**< \brief (UART) Transfer Status Register */
#else
#define REG_UART_CR   (*(WoReg*)0x400E0800U) /**< \brief (UART) Control Register */
#define REG_UART_MR   (*(RwReg*)0x400E0804U) /**< \brief (UART) Mode Register */
#define REG_UART_IER  (*(WoReg*)0x400E0808U) /**< \brief (UART) Interrupt Enable Register */
#define REG_UART_IDR  (*(WoReg*)0x400E080CU) /**< \brief (UART) Interrupt Disable Register */
#define REG_UART_IMR  (*(RoReg*)0x400E0810U) /**< \brief (UART) Interrupt Mask Register */
#define REG_UART_SR   (*(RoReg*)0x400E0814U) /**< \brief (UART) Status Register */
#define REG_UART_RHR  (*(RoReg*)0x400E0818U) /**< \brief (UART) Receive Holding Register */
#define REG_UART_THR  (*(WoReg*)0x400E081CU) /**< \brief (UART) Transmit Holding Register */
#define REG_UART_BRGR (*(RwReg*)0x400E0820U) /**< \brief (UART) Baud Rate Generator Register */
#define REG_UART_RPR  (*(RwReg*)0x400E0900U) /**< \brief (UART) Receive Pointer Register */
#define REG_UART_RCR  (*(RwReg*)0x400E0904U) /**< \brief (UART) Receive Counter Register */
#define REG_UART_TPR  (*(RwReg*)0x400E0908U) /**< \brief (UART) Transmit Pointer Register */
#define REG_UART_TCR  (*(RwReg*)0x400E090CU) /**< \brief (UART) Transmit Counter Register */
#define REG_UART_RNPR (*(RwReg*)0x400E0910U) /**< \brief (UART) Receive Next Pointer Register */
#define REG_UART_RNCR (*(RwReg*)0x400E0914U) /**< \brief (UART) Receive Next Counter Register */
#define REG_UART_TNPR (*(RwReg*)0x400E0918U) /**< \brief (UART) Transmit Next Pointer Register */
#define REG_UART_TNCR (*(RwReg*)0x400E091CU) /**< \brief (UART) Transmit Next Counter Register */
#define REG_UART_PTCR (*(WoReg*)0x400E0920U) /**< \brief (UART) Transfer Control Register */
#define REG_UART_PTSR (*(RoReg*)0x400E0924U) /**< \brief (UART) Transfer Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3XA_UART_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)
