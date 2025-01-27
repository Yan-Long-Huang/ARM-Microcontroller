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

#ifndef _SAM3XA_PDC_COMPONENT_
#define _SAM3XA_PDC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Peripheral DMA Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_PDC Peripheral DMA Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief Pdc hardware registers */
typedef struct {
  RwReg PERIPH_RPR;  /**< \brief (Pdc Offset: 0x0) Receive Pointer Register */
  RwReg PERIPH_RCR;  /**< \brief (Pdc Offset: 0x4) Receive Counter Register */
  RwReg PERIPH_TPR;  /**< \brief (Pdc Offset: 0x8) Transmit Pointer Register */
  RwReg PERIPH_TCR;  /**< \brief (Pdc Offset: 0xC) Transmit Counter Register */
  RwReg PERIPH_RNPR; /**< \brief (Pdc Offset: 0x10) Receive Next Pointer Register */
  RwReg PERIPH_RNCR; /**< \brief (Pdc Offset: 0x14) Receive Next Counter Register */
  RwReg PERIPH_TNPR; /**< \brief (Pdc Offset: 0x18) Transmit Next Pointer Register */
  RwReg PERIPH_TNCR; /**< \brief (Pdc Offset: 0x1C) Transmit Next Counter Register */
  WoReg PERIPH_PTCR; /**< \brief (Pdc Offset: 0x20) Transfer Control Register */
  RoReg PERIPH_PTSR; /**< \brief (Pdc Offset: 0x24) Transfer Status Register */
} Pdc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- PERIPH_RPR : (PDC Offset: 0x0) Receive Pointer Register -------- */
#define PERIPH_RPR_RXPTR_Pos 0
#define PERIPH_RPR_RXPTR_Msk (0xffffffffu << PERIPH_RPR_RXPTR_Pos) /**< \brief (PERIPH_RPR) Receive Pointer Register */
#define PERIPH_RPR_RXPTR(value) ((PERIPH_RPR_RXPTR_Msk & ((value) << PERIPH_RPR_RXPTR_Pos)))
/* -------- PERIPH_RCR : (PDC Offset: 0x4) Receive Counter Register -------- */
#define PERIPH_RCR_RXCTR_Pos 0
#define PERIPH_RCR_RXCTR_Msk (0xffffu << PERIPH_RCR_RXCTR_Pos) /**< \brief (PERIPH_RCR) Receive Counter Register */
#define PERIPH_RCR_RXCTR(value) ((PERIPH_RCR_RXCTR_Msk & ((value) << PERIPH_RCR_RXCTR_Pos)))
/* -------- PERIPH_TPR : (PDC Offset: 0x8) Transmit Pointer Register -------- */
#define PERIPH_TPR_TXPTR_Pos 0
#define PERIPH_TPR_TXPTR_Msk (0xffffffffu << PERIPH_TPR_TXPTR_Pos) /**< \brief (PERIPH_TPR) Transmit Counter Register */
#define PERIPH_TPR_TXPTR(value) ((PERIPH_TPR_TXPTR_Msk & ((value) << PERIPH_TPR_TXPTR_Pos)))
/* -------- PERIPH_TCR : (PDC Offset: 0xC) Transmit Counter Register -------- */
#define PERIPH_TCR_TXCTR_Pos 0
#define PERIPH_TCR_TXCTR_Msk (0xffffu << PERIPH_TCR_TXCTR_Pos) /**< \brief (PERIPH_TCR) Transmit Counter Register */
#define PERIPH_TCR_TXCTR(value) ((PERIPH_TCR_TXCTR_Msk & ((value) << PERIPH_TCR_TXCTR_Pos)))
/* -------- PERIPH_RNPR : (PDC Offset: 0x10) Receive Next Pointer Register -------- */
#define PERIPH_RNPR_RXNPTR_Pos 0
#define PERIPH_RNPR_RXNPTR_Msk (0xffffffffu << PERIPH_RNPR_RXNPTR_Pos) /**< \brief (PERIPH_RNPR) Receive Next Pointer */
#define PERIPH_RNPR_RXNPTR(value) ((PERIPH_RNPR_RXNPTR_Msk & ((value) << PERIPH_RNPR_RXNPTR_Pos)))
/* -------- PERIPH_RNCR : (PDC Offset: 0x14) Receive Next Counter Register -------- */
#define PERIPH_RNCR_RXNCTR_Pos 0
#define PERIPH_RNCR_RXNCTR_Msk (0xffffu << PERIPH_RNCR_RXNCTR_Pos) /**< \brief (PERIPH_RNCR) Receive Next Counter */
#define PERIPH_RNCR_RXNCTR(value) ((PERIPH_RNCR_RXNCTR_Msk & ((value) << PERIPH_RNCR_RXNCTR_Pos)))
/* -------- PERIPH_TNPR : (PDC Offset: 0x18) Transmit Next Pointer Register -------- */
#define PERIPH_TNPR_TXNPTR_Pos 0
#define PERIPH_TNPR_TXNPTR_Msk (0xffffffffu << PERIPH_TNPR_TXNPTR_Pos) /**< \brief (PERIPH_TNPR) Transmit Next Pointer */
#define PERIPH_TNPR_TXNPTR(value) ((PERIPH_TNPR_TXNPTR_Msk & ((value) << PERIPH_TNPR_TXNPTR_Pos)))
/* -------- PERIPH_TNCR : (PDC Offset: 0x1C) Transmit Next Counter Register -------- */
#define PERIPH_TNCR_TXNCTR_Pos 0
#define PERIPH_TNCR_TXNCTR_Msk (0xffffu << PERIPH_TNCR_TXNCTR_Pos) /**< \brief (PERIPH_TNCR) Transmit Counter Next */
#define PERIPH_TNCR_TXNCTR(value) ((PERIPH_TNCR_TXNCTR_Msk & ((value) << PERIPH_TNCR_TXNCTR_Pos)))
/* -------- PERIPH_PTCR : (PDC Offset: 0x20) Transfer Control Register -------- */
#define PERIPH_PTCR_RXTEN (0x1u << 0) /**< \brief (PERIPH_PTCR) Receiver Transfer Enable */
#define PERIPH_PTCR_RXTDIS (0x1u << 1) /**< \brief (PERIPH_PTCR) Receiver Transfer Disable */
#define PERIPH_PTCR_TXTEN (0x1u << 8) /**< \brief (PERIPH_PTCR) Transmitter Transfer Enable */
#define PERIPH_PTCR_TXTDIS (0x1u << 9) /**< \brief (PERIPH_PTCR) Transmitter Transfer Disable */
/* -------- PERIPH_PTSR : (PDC Offset: 0x24) Transfer Status Register -------- */
#define PERIPH_PTSR_RXTEN (0x1u << 0) /**< \brief (PERIPH_PTSR) Receiver Transfer Enable */
#define PERIPH_PTSR_TXTEN (0x1u << 8) /**< \brief (PERIPH_PTSR) Transmitter Transfer Enable */

/*@}*/


#endif /* _SAM3XA_PDC_COMPONENT_ */
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

#ifndef _SAM3XA_PDC_COMPONENT_
#define _SAM3XA_PDC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Peripheral DMA Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_PDC Peripheral DMA Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief Pdc hardware registers */
typedef struct {
  RwReg PERIPH_RPR;  /**< \brief (Pdc Offset: 0x0) Receive Pointer Register */
  RwReg PERIPH_RCR;  /**< \brief (Pdc Offset: 0x4) Receive Counter Register */
  RwReg PERIPH_TPR;  /**< \brief (Pdc Offset: 0x8) Transmit Pointer Register */
  RwReg PERIPH_TCR;  /**< \brief (Pdc Offset: 0xC) Transmit Counter Register */
  RwReg PERIPH_RNPR; /**< \brief (Pdc Offset: 0x10) Receive Next Pointer Register */
  RwReg PERIPH_RNCR; /**< \brief (Pdc Offset: 0x14) Receive Next Counter Register */
  RwReg PERIPH_TNPR; /**< \brief (Pdc Offset: 0x18) Transmit Next Pointer Register */
  RwReg PERIPH_TNCR; /**< \brief (Pdc Offset: 0x1C) Transmit Next Counter Register */
  WoReg PERIPH_PTCR; /**< \brief (Pdc Offset: 0x20) Transfer Control Register */
  RoReg PERIPH_PTSR; /**< \brief (Pdc Offset: 0x24) Transfer Status Register */
} Pdc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- PERIPH_RPR : (PDC Offset: 0x0) Receive Pointer Register -------- */
#define PERIPH_RPR_RXPTR_Pos 0
#define PERIPH_RPR_RXPTR_Msk (0xffffffffu << PERIPH_RPR_RXPTR_Pos) /**< \brief (PERIPH_RPR) Receive Pointer Register */
#define PERIPH_RPR_RXPTR(value) ((PERIPH_RPR_RXPTR_Msk & ((value) << PERIPH_RPR_RXPTR_Pos)))
/* -------- PERIPH_RCR : (PDC Offset: 0x4) Receive Counter Register -------- */
#define PERIPH_RCR_RXCTR_Pos 0
#define PERIPH_RCR_RXCTR_Msk (0xffffu << PERIPH_RCR_RXCTR_Pos) /**< \brief (PERIPH_RCR) Receive Counter Register */
#define PERIPH_RCR_RXCTR(value) ((PERIPH_RCR_RXCTR_Msk & ((value) << PERIPH_RCR_RXCTR_Pos)))
/* -------- PERIPH_TPR : (PDC Offset: 0x8) Transmit Pointer Register -------- */
#define PERIPH_TPR_TXPTR_Pos 0
#define PERIPH_TPR_TXPTR_Msk (0xffffffffu << PERIPH_TPR_TXPTR_Pos) /**< \brief (PERIPH_TPR) Transmit Counter Register */
#define PERIPH_TPR_TXPTR(value) ((PERIPH_TPR_TXPTR_Msk & ((value) << PERIPH_TPR_TXPTR_Pos)))
/* -------- PERIPH_TCR : (PDC Offset: 0xC) Transmit Counter Register -------- */
#define PERIPH_TCR_TXCTR_Pos 0
#define PERIPH_TCR_TXCTR_Msk (0xffffu << PERIPH_TCR_TXCTR_Pos) /**< \brief (PERIPH_TCR) Transmit Counter Register */
#define PERIPH_TCR_TXCTR(value) ((PERIPH_TCR_TXCTR_Msk & ((value) << PERIPH_TCR_TXCTR_Pos)))
/* -------- PERIPH_RNPR : (PDC Offset: 0x10) Receive Next Pointer Register -------- */
#define PERIPH_RNPR_RXNPTR_Pos 0
#define PERIPH_RNPR_RXNPTR_Msk (0xffffffffu << PERIPH_RNPR_RXNPTR_Pos) /**< \brief (PERIPH_RNPR) Receive Next Pointer */
#define PERIPH_RNPR_RXNPTR(value) ((PERIPH_RNPR_RXNPTR_Msk & ((value) << PERIPH_RNPR_RXNPTR_Pos)))
/* -------- PERIPH_RNCR : (PDC Offset: 0x14) Receive Next Counter Register -------- */
#define PERIPH_RNCR_RXNCTR_Pos 0
#define PERIPH_RNCR_RXNCTR_Msk (0xffffu << PERIPH_RNCR_RXNCTR_Pos) /**< \brief (PERIPH_RNCR) Receive Next Counter */
#define PERIPH_RNCR_RXNCTR(value) ((PERIPH_RNCR_RXNCTR_Msk & ((value) << PERIPH_RNCR_RXNCTR_Pos)))
/* -------- PERIPH_TNPR : (PDC Offset: 0x18) Transmit Next Pointer Register -------- */
#define PERIPH_TNPR_TXNPTR_Pos 0
#define PERIPH_TNPR_TXNPTR_Msk (0xffffffffu << PERIPH_TNPR_TXNPTR_Pos) /**< \brief (PERIPH_TNPR) Transmit Next Pointer */
#define PERIPH_TNPR_TXNPTR(value) ((PERIPH_TNPR_TXNPTR_Msk & ((value) << PERIPH_TNPR_TXNPTR_Pos)))
/* -------- PERIPH_TNCR : (PDC Offset: 0x1C) Transmit Next Counter Register -------- */
#define PERIPH_TNCR_TXNCTR_Pos 0
#define PERIPH_TNCR_TXNCTR_Msk (0xffffu << PERIPH_TNCR_TXNCTR_Pos) /**< \brief (PERIPH_TNCR) Transmit Counter Next */
#define PERIPH_TNCR_TXNCTR(value) ((PERIPH_TNCR_TXNCTR_Msk & ((value) << PERIPH_TNCR_TXNCTR_Pos)))
/* -------- PERIPH_PTCR : (PDC Offset: 0x20) Transfer Control Register -------- */
#define PERIPH_PTCR_RXTEN (0x1u << 0) /**< \brief (PERIPH_PTCR) Receiver Transfer Enable */
#define PERIPH_PTCR_RXTDIS (0x1u << 1) /**< \brief (PERIPH_PTCR) Receiver Transfer Disable */
#define PERIPH_PTCR_TXTEN (0x1u << 8) /**< \brief (PERIPH_PTCR) Transmitter Transfer Enable */
#define PERIPH_PTCR_TXTDIS (0x1u << 9) /**< \brief (PERIPH_PTCR) Transmitter Transfer Disable */
/* -------- PERIPH_PTSR : (PDC Offset: 0x24) Transfer Status Register -------- */
#define PERIPH_PTSR_RXTEN (0x1u << 0) /**< \brief (PERIPH_PTSR) Receiver Transfer Enable */
#define PERIPH_PTSR_TXTEN (0x1u << 8) /**< \brief (PERIPH_PTSR) Transmitter Transfer Enable */

/*@}*/


#endif /* _SAM3XA_PDC_COMPONENT_ */
>>>>>>> 16c66438 (Upload from PC.)
