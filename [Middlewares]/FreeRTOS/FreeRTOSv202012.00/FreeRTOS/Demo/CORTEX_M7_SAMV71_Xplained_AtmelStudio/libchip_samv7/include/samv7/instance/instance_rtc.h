<<<<<<< HEAD
/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2014, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#ifndef _SAMV71_RTC_INSTANCE_
#define _SAMV71_RTC_INSTANCE_

/* ========== Register definition for RTC peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_RTC_CR                      (0x400E1860U) /**< \brief (RTC) Control Register */
  #define REG_RTC_MR                      (0x400E1864U) /**< \brief (RTC) Mode Register */
  #define REG_RTC_TIMR                    (0x400E1868U) /**< \brief (RTC) Time Register */
  #define REG_RTC_CALR                    (0x400E186CU) /**< \brief (RTC) Calendar Register */
  #define REG_RTC_TIMALR                  (0x400E1870U) /**< \brief (RTC) Time Alarm Register */
  #define REG_RTC_CALALR                  (0x400E1874U) /**< \brief (RTC) Calendar Alarm Register */
  #define REG_RTC_SR                      (0x400E1878U) /**< \brief (RTC) Status Register */
  #define REG_RTC_SCCR                    (0x400E187CU) /**< \brief (RTC) Status Clear Command Register */
  #define REG_RTC_IER                     (0x400E1880U) /**< \brief (RTC) Interrupt Enable Register */
  #define REG_RTC_IDR                     (0x400E1884U) /**< \brief (RTC) Interrupt Disable Register */
  #define REG_RTC_IMR                     (0x400E1888U) /**< \brief (RTC) Interrupt Mask Register */
  #define REG_RTC_VER                     (0x400E188CU) /**< \brief (RTC) Valid Entry Register */
#else
  #define REG_RTC_CR     (*(__IO uint32_t*)0x400E1860U) /**< \brief (RTC) Control Register */
  #define REG_RTC_MR     (*(__IO uint32_t*)0x400E1864U) /**< \brief (RTC) Mode Register */
  #define REG_RTC_TIMR   (*(__IO uint32_t*)0x400E1868U) /**< \brief (RTC) Time Register */
  #define REG_RTC_CALR   (*(__IO uint32_t*)0x400E186CU) /**< \brief (RTC) Calendar Register */
  #define REG_RTC_TIMALR (*(__IO uint32_t*)0x400E1870U) /**< \brief (RTC) Time Alarm Register */
  #define REG_RTC_CALALR (*(__IO uint32_t*)0x400E1874U) /**< \brief (RTC) Calendar Alarm Register */
  #define REG_RTC_SR     (*(__I  uint32_t*)0x400E1878U) /**< \brief (RTC) Status Register */
  #define REG_RTC_SCCR   (*(__O  uint32_t*)0x400E187CU) /**< \brief (RTC) Status Clear Command Register */
  #define REG_RTC_IER    (*(__O  uint32_t*)0x400E1880U) /**< \brief (RTC) Interrupt Enable Register */
  #define REG_RTC_IDR    (*(__O  uint32_t*)0x400E1884U) /**< \brief (RTC) Interrupt Disable Register */
  #define REG_RTC_IMR    (*(__I  uint32_t*)0x400E1888U) /**< \brief (RTC) Interrupt Mask Register */
  #define REG_RTC_VER    (*(__I  uint32_t*)0x400E188CU) /**< \brief (RTC) Valid Entry Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMV71_RTC_INSTANCE_ */
=======
/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2014, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#ifndef _SAMV71_RTC_INSTANCE_
#define _SAMV71_RTC_INSTANCE_

/* ========== Register definition for RTC peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_RTC_CR                      (0x400E1860U) /**< \brief (RTC) Control Register */
  #define REG_RTC_MR                      (0x400E1864U) /**< \brief (RTC) Mode Register */
  #define REG_RTC_TIMR                    (0x400E1868U) /**< \brief (RTC) Time Register */
  #define REG_RTC_CALR                    (0x400E186CU) /**< \brief (RTC) Calendar Register */
  #define REG_RTC_TIMALR                  (0x400E1870U) /**< \brief (RTC) Time Alarm Register */
  #define REG_RTC_CALALR                  (0x400E1874U) /**< \brief (RTC) Calendar Alarm Register */
  #define REG_RTC_SR                      (0x400E1878U) /**< \brief (RTC) Status Register */
  #define REG_RTC_SCCR                    (0x400E187CU) /**< \brief (RTC) Status Clear Command Register */
  #define REG_RTC_IER                     (0x400E1880U) /**< \brief (RTC) Interrupt Enable Register */
  #define REG_RTC_IDR                     (0x400E1884U) /**< \brief (RTC) Interrupt Disable Register */
  #define REG_RTC_IMR                     (0x400E1888U) /**< \brief (RTC) Interrupt Mask Register */
  #define REG_RTC_VER                     (0x400E188CU) /**< \brief (RTC) Valid Entry Register */
#else
  #define REG_RTC_CR     (*(__IO uint32_t*)0x400E1860U) /**< \brief (RTC) Control Register */
  #define REG_RTC_MR     (*(__IO uint32_t*)0x400E1864U) /**< \brief (RTC) Mode Register */
  #define REG_RTC_TIMR   (*(__IO uint32_t*)0x400E1868U) /**< \brief (RTC) Time Register */
  #define REG_RTC_CALR   (*(__IO uint32_t*)0x400E186CU) /**< \brief (RTC) Calendar Register */
  #define REG_RTC_TIMALR (*(__IO uint32_t*)0x400E1870U) /**< \brief (RTC) Time Alarm Register */
  #define REG_RTC_CALALR (*(__IO uint32_t*)0x400E1874U) /**< \brief (RTC) Calendar Alarm Register */
  #define REG_RTC_SR     (*(__I  uint32_t*)0x400E1878U) /**< \brief (RTC) Status Register */
  #define REG_RTC_SCCR   (*(__O  uint32_t*)0x400E187CU) /**< \brief (RTC) Status Clear Command Register */
  #define REG_RTC_IER    (*(__O  uint32_t*)0x400E1880U) /**< \brief (RTC) Interrupt Enable Register */
  #define REG_RTC_IDR    (*(__O  uint32_t*)0x400E1884U) /**< \brief (RTC) Interrupt Disable Register */
  #define REG_RTC_IMR    (*(__I  uint32_t*)0x400E1888U) /**< \brief (RTC) Interrupt Mask Register */
  #define REG_RTC_VER    (*(__I  uint32_t*)0x400E188CU) /**< \brief (RTC) Valid Entry Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMV71_RTC_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)
