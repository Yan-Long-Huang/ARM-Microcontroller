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

#ifndef _SAM3S8_SPI_INSTANCE_
#define _SAM3S8_SPI_INSTANCE_

/* ========== Register definition for SPI peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_SPI_CR              (0x40008000U) /**< \brief (SPI) Control Register */
#define REG_SPI_MR              (0x40008004U) /**< \brief (SPI) Mode Register */
#define REG_SPI_RDR             (0x40008008U) /**< \brief (SPI) Receive Data Register */
#define REG_SPI_TDR             (0x4000800CU) /**< \brief (SPI) Transmit Data Register */
#define REG_SPI_SR              (0x40008010U) /**< \brief (SPI) Status Register */
#define REG_SPI_IER             (0x40008014U) /**< \brief (SPI) Interrupt Enable Register */
#define REG_SPI_IDR             (0x40008018U) /**< \brief (SPI) Interrupt Disable Register */
#define REG_SPI_IMR             (0x4000801CU) /**< \brief (SPI) Interrupt Mask Register */
#define REG_SPI_CSR             (0x40008030U) /**< \brief (SPI) Chip Select Register */
#define REG_SPI_WPMR            (0x400080E4U) /**< \brief (SPI) Write Protection Control Register */
#define REG_SPI_WPSR            (0x400080E8U) /**< \brief (SPI) Write Protection Status Register */
#define REG_SPI_RPR             (0x40008100U) /**< \brief (SPI) Receive Pointer Register */
#define REG_SPI_RCR             (0x40008104U) /**< \brief (SPI) Receive Counter Register */
#define REG_SPI_TPR             (0x40008108U) /**< \brief (SPI) Transmit Pointer Register */
#define REG_SPI_TCR             (0x4000810CU) /**< \brief (SPI) Transmit Counter Register */
#define REG_SPI_RNPR            (0x40008110U) /**< \brief (SPI) Receive Next Pointer Register */
#define REG_SPI_RNCR            (0x40008114U) /**< \brief (SPI) Receive Next Counter Register */
#define REG_SPI_TNPR            (0x40008118U) /**< \brief (SPI) Transmit Next Pointer Register */
#define REG_SPI_TNCR            (0x4000811CU) /**< \brief (SPI) Transmit Next Counter Register */
#define REG_SPI_PTCR            (0x40008120U) /**< \brief (SPI) Transfer Control Register */
#define REG_SPI_PTSR            (0x40008124U) /**< \brief (SPI) Transfer Status Register */
#else
#define REG_SPI_CR     (*(WoReg*)0x40008000U) /**< \brief (SPI) Control Register */
#define REG_SPI_MR     (*(RwReg*)0x40008004U) /**< \brief (SPI) Mode Register */
#define REG_SPI_RDR    (*(RoReg*)0x40008008U) /**< \brief (SPI) Receive Data Register */
#define REG_SPI_TDR    (*(WoReg*)0x4000800CU) /**< \brief (SPI) Transmit Data Register */
#define REG_SPI_SR     (*(RoReg*)0x40008010U) /**< \brief (SPI) Status Register */
#define REG_SPI_IER    (*(WoReg*)0x40008014U) /**< \brief (SPI) Interrupt Enable Register */
#define REG_SPI_IDR    (*(WoReg*)0x40008018U) /**< \brief (SPI) Interrupt Disable Register */
#define REG_SPI_IMR    (*(RoReg*)0x4000801CU) /**< \brief (SPI) Interrupt Mask Register */
#define REG_SPI_CSR    (*(RwReg*)0x40008030U) /**< \brief (SPI) Chip Select Register */
#define REG_SPI_WPMR   (*(RwReg*)0x400080E4U) /**< \brief (SPI) Write Protection Control Register */
#define REG_SPI_WPSR   (*(RoReg*)0x400080E8U) /**< \brief (SPI) Write Protection Status Register */
#define REG_SPI_RPR    (*(RwReg*)0x40008100U) /**< \brief (SPI) Receive Pointer Register */
#define REG_SPI_RCR    (*(RwReg*)0x40008104U) /**< \brief (SPI) Receive Counter Register */
#define REG_SPI_TPR    (*(RwReg*)0x40008108U) /**< \brief (SPI) Transmit Pointer Register */
#define REG_SPI_TCR    (*(RwReg*)0x4000810CU) /**< \brief (SPI) Transmit Counter Register */
#define REG_SPI_RNPR   (*(RwReg*)0x40008110U) /**< \brief (SPI) Receive Next Pointer Register */
#define REG_SPI_RNCR   (*(RwReg*)0x40008114U) /**< \brief (SPI) Receive Next Counter Register */
#define REG_SPI_TNPR   (*(RwReg*)0x40008118U) /**< \brief (SPI) Transmit Next Pointer Register */
#define REG_SPI_TNCR   (*(RwReg*)0x4000811CU) /**< \brief (SPI) Transmit Next Counter Register */
#define REG_SPI_PTCR   (*(WoReg*)0x40008120U) /**< \brief (SPI) Transfer Control Register */
#define REG_SPI_PTSR   (*(RoReg*)0x40008124U) /**< \brief (SPI) Transfer Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S8_SPI_INSTANCE_ */
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

#ifndef _SAM3S8_SPI_INSTANCE_
#define _SAM3S8_SPI_INSTANCE_

/* ========== Register definition for SPI peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_SPI_CR              (0x40008000U) /**< \brief (SPI) Control Register */
#define REG_SPI_MR              (0x40008004U) /**< \brief (SPI) Mode Register */
#define REG_SPI_RDR             (0x40008008U) /**< \brief (SPI) Receive Data Register */
#define REG_SPI_TDR             (0x4000800CU) /**< \brief (SPI) Transmit Data Register */
#define REG_SPI_SR              (0x40008010U) /**< \brief (SPI) Status Register */
#define REG_SPI_IER             (0x40008014U) /**< \brief (SPI) Interrupt Enable Register */
#define REG_SPI_IDR             (0x40008018U) /**< \brief (SPI) Interrupt Disable Register */
#define REG_SPI_IMR             (0x4000801CU) /**< \brief (SPI) Interrupt Mask Register */
#define REG_SPI_CSR             (0x40008030U) /**< \brief (SPI) Chip Select Register */
#define REG_SPI_WPMR            (0x400080E4U) /**< \brief (SPI) Write Protection Control Register */
#define REG_SPI_WPSR            (0x400080E8U) /**< \brief (SPI) Write Protection Status Register */
#define REG_SPI_RPR             (0x40008100U) /**< \brief (SPI) Receive Pointer Register */
#define REG_SPI_RCR             (0x40008104U) /**< \brief (SPI) Receive Counter Register */
#define REG_SPI_TPR             (0x40008108U) /**< \brief (SPI) Transmit Pointer Register */
#define REG_SPI_TCR             (0x4000810CU) /**< \brief (SPI) Transmit Counter Register */
#define REG_SPI_RNPR            (0x40008110U) /**< \brief (SPI) Receive Next Pointer Register */
#define REG_SPI_RNCR            (0x40008114U) /**< \brief (SPI) Receive Next Counter Register */
#define REG_SPI_TNPR            (0x40008118U) /**< \brief (SPI) Transmit Next Pointer Register */
#define REG_SPI_TNCR            (0x4000811CU) /**< \brief (SPI) Transmit Next Counter Register */
#define REG_SPI_PTCR            (0x40008120U) /**< \brief (SPI) Transfer Control Register */
#define REG_SPI_PTSR            (0x40008124U) /**< \brief (SPI) Transfer Status Register */
#else
#define REG_SPI_CR     (*(WoReg*)0x40008000U) /**< \brief (SPI) Control Register */
#define REG_SPI_MR     (*(RwReg*)0x40008004U) /**< \brief (SPI) Mode Register */
#define REG_SPI_RDR    (*(RoReg*)0x40008008U) /**< \brief (SPI) Receive Data Register */
#define REG_SPI_TDR    (*(WoReg*)0x4000800CU) /**< \brief (SPI) Transmit Data Register */
#define REG_SPI_SR     (*(RoReg*)0x40008010U) /**< \brief (SPI) Status Register */
#define REG_SPI_IER    (*(WoReg*)0x40008014U) /**< \brief (SPI) Interrupt Enable Register */
#define REG_SPI_IDR    (*(WoReg*)0x40008018U) /**< \brief (SPI) Interrupt Disable Register */
#define REG_SPI_IMR    (*(RoReg*)0x4000801CU) /**< \brief (SPI) Interrupt Mask Register */
#define REG_SPI_CSR    (*(RwReg*)0x40008030U) /**< \brief (SPI) Chip Select Register */
#define REG_SPI_WPMR   (*(RwReg*)0x400080E4U) /**< \brief (SPI) Write Protection Control Register */
#define REG_SPI_WPSR   (*(RoReg*)0x400080E8U) /**< \brief (SPI) Write Protection Status Register */
#define REG_SPI_RPR    (*(RwReg*)0x40008100U) /**< \brief (SPI) Receive Pointer Register */
#define REG_SPI_RCR    (*(RwReg*)0x40008104U) /**< \brief (SPI) Receive Counter Register */
#define REG_SPI_TPR    (*(RwReg*)0x40008108U) /**< \brief (SPI) Transmit Pointer Register */
#define REG_SPI_TCR    (*(RwReg*)0x4000810CU) /**< \brief (SPI) Transmit Counter Register */
#define REG_SPI_RNPR   (*(RwReg*)0x40008110U) /**< \brief (SPI) Receive Next Pointer Register */
#define REG_SPI_RNCR   (*(RwReg*)0x40008114U) /**< \brief (SPI) Receive Next Counter Register */
#define REG_SPI_TNPR   (*(RwReg*)0x40008118U) /**< \brief (SPI) Transmit Next Pointer Register */
#define REG_SPI_TNCR   (*(RwReg*)0x4000811CU) /**< \brief (SPI) Transmit Next Counter Register */
#define REG_SPI_PTCR   (*(WoReg*)0x40008120U) /**< \brief (SPI) Transfer Control Register */
#define REG_SPI_PTSR   (*(RoReg*)0x40008124U) /**< \brief (SPI) Transfer Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S8_SPI_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)
