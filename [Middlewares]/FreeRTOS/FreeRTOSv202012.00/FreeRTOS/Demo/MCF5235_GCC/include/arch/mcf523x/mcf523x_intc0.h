<<<<<<< HEAD
/*
 * These files are taken from the MCF523X source code example package
 * which is available on the Freescale website. Freescale explicitly 
 * grants the redistribution and modification of these source files.
 * The complete licensing information is available in the file 
 * LICENSE_FREESCALE.TXT.
 *
 * File:	mcf523x_intc0.h
 * Purpose:	Register and bit definitions for the MCF523X
 *
 * Notes:	
 *	
 */

#ifndef __MCF523X_INTC0_H__
#define __MCF523X_INTC0_H__

/*********************************************************************
*
* Interrupt Controller 0 (INTC0)
*
*********************************************************************/

/* Register read/write macros */
#define MCF_INTC0_IPRH         (*(vuint32*)(void*)(&__IPSBAR[0x000C00]))
#define MCF_INTC0_IPRL         (*(vuint32*)(void*)(&__IPSBAR[0x000C04]))
#define MCF_INTC0_IMRH         (*(vuint32*)(void*)(&__IPSBAR[0x000C08]))
#define MCF_INTC0_IMRL         (*(vuint32*)(void*)(&__IPSBAR[0x000C0C]))
#define MCF_INTC0_INTFRCH      (*(vuint32*)(void*)(&__IPSBAR[0x000C10]))
#define MCF_INTC0_INTFRCL      (*(vuint32*)(void*)(&__IPSBAR[0x000C14]))
#define MCF_INTC0_IRLR         (*(vuint8 *)(void*)(&__IPSBAR[0x000C18]))
#define MCF_INTC0_IACKLPR      (*(vuint8 *)(void*)(&__IPSBAR[0x000C19]))
#define MCF_INTC0_ICR0         (*(vuint8 *)(void*)(&__IPSBAR[0x000C40]))
#define MCF_INTC0_ICR1         (*(vuint8 *)(void*)(&__IPSBAR[0x000C41]))
#define MCF_INTC0_ICR2         (*(vuint8 *)(void*)(&__IPSBAR[0x000C42]))
#define MCF_INTC0_ICR3         (*(vuint8 *)(void*)(&__IPSBAR[0x000C43]))
#define MCF_INTC0_ICR4         (*(vuint8 *)(void*)(&__IPSBAR[0x000C44]))
#define MCF_INTC0_ICR5         (*(vuint8 *)(void*)(&__IPSBAR[0x000C45]))
#define MCF_INTC0_ICR6         (*(vuint8 *)(void*)(&__IPSBAR[0x000C46]))
#define MCF_INTC0_ICR7         (*(vuint8 *)(void*)(&__IPSBAR[0x000C47]))
#define MCF_INTC0_ICR8         (*(vuint8 *)(void*)(&__IPSBAR[0x000C48]))
#define MCF_INTC0_ICR9         (*(vuint8 *)(void*)(&__IPSBAR[0x000C49]))
#define MCF_INTC0_ICR10        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4A]))
#define MCF_INTC0_ICR11        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4B]))
#define MCF_INTC0_ICR12        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4C]))
#define MCF_INTC0_ICR13        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4D]))
#define MCF_INTC0_ICR14        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4E]))
#define MCF_INTC0_ICR15        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4F]))
#define MCF_INTC0_ICR16        (*(vuint8 *)(void*)(&__IPSBAR[0x000C50]))
#define MCF_INTC0_ICR17        (*(vuint8 *)(void*)(&__IPSBAR[0x000C51]))
#define MCF_INTC0_ICR18        (*(vuint8 *)(void*)(&__IPSBAR[0x000C52]))
#define MCF_INTC0_ICR19        (*(vuint8 *)(void*)(&__IPSBAR[0x000C53]))
#define MCF_INTC0_ICR20        (*(vuint8 *)(void*)(&__IPSBAR[0x000C54]))
#define MCF_INTC0_ICR21        (*(vuint8 *)(void*)(&__IPSBAR[0x000C55]))
#define MCF_INTC0_ICR22        (*(vuint8 *)(void*)(&__IPSBAR[0x000C56]))
#define MCF_INTC0_ICR23        (*(vuint8 *)(void*)(&__IPSBAR[0x000C57]))
#define MCF_INTC0_ICR24        (*(vuint8 *)(void*)(&__IPSBAR[0x000C58]))
#define MCF_INTC0_ICR25        (*(vuint8 *)(void*)(&__IPSBAR[0x000C59]))
#define MCF_INTC0_ICR26        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5A]))
#define MCF_INTC0_ICR27        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5B]))
#define MCF_INTC0_ICR28        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5C]))
#define MCF_INTC0_ICR29        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5D]))
#define MCF_INTC0_ICR30        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5E]))
#define MCF_INTC0_ICR31        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5F]))
#define MCF_INTC0_ICR32        (*(vuint8 *)(void*)(&__IPSBAR[0x000C60]))
#define MCF_INTC0_ICR33        (*(vuint8 *)(void*)(&__IPSBAR[0x000C61]))
#define MCF_INTC0_ICR34        (*(vuint8 *)(void*)(&__IPSBAR[0x000C62]))
#define MCF_INTC0_ICR35        (*(vuint8 *)(void*)(&__IPSBAR[0x000C63]))
#define MCF_INTC0_ICR36        (*(vuint8 *)(void*)(&__IPSBAR[0x000C64]))
#define MCF_INTC0_ICR37        (*(vuint8 *)(void*)(&__IPSBAR[0x000C65]))
#define MCF_INTC0_ICR38        (*(vuint8 *)(void*)(&__IPSBAR[0x000C66]))
#define MCF_INTC0_ICR39        (*(vuint8 *)(void*)(&__IPSBAR[0x000C67]))
#define MCF_INTC0_ICR40        (*(vuint8 *)(void*)(&__IPSBAR[0x000C68]))
#define MCF_INTC0_ICR41        (*(vuint8 *)(void*)(&__IPSBAR[0x000C69]))
#define MCF_INTC0_ICR42        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6A]))
#define MCF_INTC0_ICR43        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6B]))
#define MCF_INTC0_ICR44        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6C]))
#define MCF_INTC0_ICR45        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6D]))
#define MCF_INTC0_ICR46        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6E]))
#define MCF_INTC0_ICR47        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6F]))
#define MCF_INTC0_ICR48        (*(vuint8 *)(void*)(&__IPSBAR[0x000C70]))
#define MCF_INTC0_ICR49        (*(vuint8 *)(void*)(&__IPSBAR[0x000C71]))
#define MCF_INTC0_ICR50        (*(vuint8 *)(void*)(&__IPSBAR[0x000C72]))
#define MCF_INTC0_ICR51        (*(vuint8 *)(void*)(&__IPSBAR[0x000C73]))
#define MCF_INTC0_ICR52        (*(vuint8 *)(void*)(&__IPSBAR[0x000C74]))
#define MCF_INTC0_ICR53        (*(vuint8 *)(void*)(&__IPSBAR[0x000C75]))
#define MCF_INTC0_ICR54        (*(vuint8 *)(void*)(&__IPSBAR[0x000C76]))
#define MCF_INTC0_ICR55        (*(vuint8 *)(void*)(&__IPSBAR[0x000C77]))
#define MCF_INTC0_ICR56        (*(vuint8 *)(void*)(&__IPSBAR[0x000C78]))
#define MCF_INTC0_ICR57        (*(vuint8 *)(void*)(&__IPSBAR[0x000C79]))
#define MCF_INTC0_ICR58        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7A]))
#define MCF_INTC0_ICR59        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7B]))
#define MCF_INTC0_ICR60        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7C]))
#define MCF_INTC0_ICR61        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7D]))
#define MCF_INTC0_ICR62        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7E]))
#define MCF_INTC0_ICR63        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7F]))
#define MCF_INTC0_ICRn(x)      (*(vuint8 *)(void*)(&__IPSBAR[0x000C40+((x)*0x001)]))
#define MCF_INTC0_SWIACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CE0]))
#define MCF_INTC0_L1IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CE4]))
#define MCF_INTC0_L2IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CE8]))
#define MCF_INTC0_L3IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CEC]))
#define MCF_INTC0_L4IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CF0]))
#define MCF_INTC0_L5IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CF4]))
#define MCF_INTC0_L6IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CF8]))
#define MCF_INTC0_L7IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CFC]))
#define MCF_INTC0_LnIACK(x)    (*(vuint8 *)(void*)(&__IPSBAR[0x000CE4+((x)*0x004)]))

/* Bit definitions and macros for MCF_INTC0_IPRH */
#define MCF_INTC0_IPRH_INT32          (0x00000001)
#define MCF_INTC0_IPRH_INT33          (0x00000002)
#define MCF_INTC0_IPRH_INT34          (0x00000004)
#define MCF_INTC0_IPRH_INT35          (0x00000008)
#define MCF_INTC0_IPRH_INT36          (0x00000010)
#define MCF_INTC0_IPRH_INT37          (0x00000020)
#define MCF_INTC0_IPRH_INT38          (0x00000040)
#define MCF_INTC0_IPRH_INT39          (0x00000080)
#define MCF_INTC0_IPRH_INT40          (0x00000100)
#define MCF_INTC0_IPRH_INT41          (0x00000200)
#define MCF_INTC0_IPRH_INT42          (0x00000400)
#define MCF_INTC0_IPRH_INT43          (0x00000800)
#define MCF_INTC0_IPRH_INT44          (0x00001000)
#define MCF_INTC0_IPRH_INT45          (0x00002000)
#define MCF_INTC0_IPRH_INT46          (0x00004000)
#define MCF_INTC0_IPRH_INT47          (0x00008000)
#define MCF_INTC0_IPRH_INT48          (0x00010000)
#define MCF_INTC0_IPRH_INT49          (0x00020000)
#define MCF_INTC0_IPRH_INT50          (0x00040000)
#define MCF_INTC0_IPRH_INT51          (0x00080000)
#define MCF_INTC0_IPRH_INT52          (0x00100000)
#define MCF_INTC0_IPRH_INT53          (0x00200000)
#define MCF_INTC0_IPRH_INT54          (0x00400000)
#define MCF_INTC0_IPRH_INT55          (0x00800000)
#define MCF_INTC0_IPRH_INT56          (0x01000000)
#define MCF_INTC0_IPRH_INT57          (0x02000000)
#define MCF_INTC0_IPRH_INT58          (0x04000000)
#define MCF_INTC0_IPRH_INT59          (0x08000000)
#define MCF_INTC0_IPRH_INT60          (0x10000000)
#define MCF_INTC0_IPRH_INT61          (0x20000000)
#define MCF_INTC0_IPRH_INT62          (0x40000000)
#define MCF_INTC0_IPRH_INT63          (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IPRL */
#define MCF_INTC0_IPRL_INT1           (0x00000002)
#define MCF_INTC0_IPRL_INT2           (0x00000004)
#define MCF_INTC0_IPRL_INT3           (0x00000008)
#define MCF_INTC0_IPRL_INT4           (0x00000010)
#define MCF_INTC0_IPRL_INT5           (0x00000020)
#define MCF_INTC0_IPRL_INT6           (0x00000040)
#define MCF_INTC0_IPRL_INT7           (0x00000080)
#define MCF_INTC0_IPRL_INT8           (0x00000100)
#define MCF_INTC0_IPRL_INT9           (0x00000200)
#define MCF_INTC0_IPRL_INT10          (0x00000400)
#define MCF_INTC0_IPRL_INT11          (0x00000800)
#define MCF_INTC0_IPRL_INT12          (0x00001000)
#define MCF_INTC0_IPRL_INT13          (0x00002000)
#define MCF_INTC0_IPRL_INT14          (0x00004000)
#define MCF_INTC0_IPRL_INT15          (0x00008000)
#define MCF_INTC0_IPRL_INT16          (0x00010000)
#define MCF_INTC0_IPRL_INT17          (0x00020000)
#define MCF_INTC0_IPRL_INT18          (0x00040000)
#define MCF_INTC0_IPRL_INT19          (0x00080000)
#define MCF_INTC0_IPRL_INT20          (0x00100000)
#define MCF_INTC0_IPRL_INT21          (0x00200000)
#define MCF_INTC0_IPRL_INT22          (0x00400000)
#define MCF_INTC0_IPRL_INT23          (0x00800000)
#define MCF_INTC0_IPRL_INT24          (0x01000000)
#define MCF_INTC0_IPRL_INT25          (0x02000000)
#define MCF_INTC0_IPRL_INT26          (0x04000000)
#define MCF_INTC0_IPRL_INT27          (0x08000000)
#define MCF_INTC0_IPRL_INT28          (0x10000000)
#define MCF_INTC0_IPRL_INT29          (0x20000000)
#define MCF_INTC0_IPRL_INT30          (0x40000000)
#define MCF_INTC0_IPRL_INT31          (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IMRH */
#define MCF_INTC0_IMRH_INT_MASK32     (0x00000001)
#define MCF_INTC0_IMRH_INT_MASK33     (0x00000002)
#define MCF_INTC0_IMRH_INT_MASK34     (0x00000004)
#define MCF_INTC0_IMRH_INT_MASK35     (0x00000008)
#define MCF_INTC0_IMRH_INT_MASK36     (0x00000010)
#define MCF_INTC0_IMRH_INT_MASK37     (0x00000020)
#define MCF_INTC0_IMRH_INT_MASK38     (0x00000040)
#define MCF_INTC0_IMRH_INT_MASK39     (0x00000080)
#define MCF_INTC0_IMRH_INT_MASK40     (0x00000100)
#define MCF_INTC0_IMRH_INT_MASK41     (0x00000200)
#define MCF_INTC0_IMRH_INT_MASK42     (0x00000400)
#define MCF_INTC0_IMRH_INT_MASK43     (0x00000800)
#define MCF_INTC0_IMRH_INT_MASK44     (0x00001000)
#define MCF_INTC0_IMRH_INT_MASK45     (0x00002000)
#define MCF_INTC0_IMRH_INT_MASK46     (0x00004000)
#define MCF_INTC0_IMRH_INT_MASK47     (0x00008000)
#define MCF_INTC0_IMRH_INT_MASK48     (0x00010000)
#define MCF_INTC0_IMRH_INT_MASK49     (0x00020000)
#define MCF_INTC0_IMRH_INT_MASK50     (0x00040000)
#define MCF_INTC0_IMRH_INT_MASK51     (0x00080000)
#define MCF_INTC0_IMRH_INT_MASK52     (0x00100000)
#define MCF_INTC0_IMRH_INT_MASK53     (0x00200000)
#define MCF_INTC0_IMRH_INT_MASK54     (0x00400000)
#define MCF_INTC0_IMRH_INT_MASK55     (0x00800000)
#define MCF_INTC0_IMRH_INT_MASK56     (0x01000000)
#define MCF_INTC0_IMRH_INT_MASK57     (0x02000000)
#define MCF_INTC0_IMRH_INT_MASK58     (0x04000000)
#define MCF_INTC0_IMRH_INT_MASK59     (0x08000000)
#define MCF_INTC0_IMRH_INT_MASK60     (0x10000000)
#define MCF_INTC0_IMRH_INT_MASK61     (0x20000000)
#define MCF_INTC0_IMRH_INT_MASK62     (0x40000000)
#define MCF_INTC0_IMRH_INT_MASK63     (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IMRL */
#define MCF_INTC0_IMRL_MASKALL        (0x00000001)
#define MCF_INTC0_IMRL_INT_MASK1      (0x00000002)
#define MCF_INTC0_IMRL_INT_MASK2      (0x00000004)
#define MCF_INTC0_IMRL_INT_MASK3      (0x00000008)
#define MCF_INTC0_IMRL_INT_MASK4      (0x00000010)
#define MCF_INTC0_IMRL_INT_MASK5      (0x00000020)
#define MCF_INTC0_IMRL_INT_MASK6      (0x00000040)
#define MCF_INTC0_IMRL_INT_MASK7      (0x00000080)
#define MCF_INTC0_IMRL_INT_MASK8      (0x00000100)
#define MCF_INTC0_IMRL_INT_MASK9      (0x00000200)
#define MCF_INTC0_IMRL_INT_MASK10     (0x00000400)
#define MCF_INTC0_IMRL_INT_MASK11     (0x00000800)
#define MCF_INTC0_IMRL_INT_MASK12     (0x00001000)
#define MCF_INTC0_IMRL_INT_MASK13     (0x00002000)
#define MCF_INTC0_IMRL_INT_MASK14     (0x00004000)
#define MCF_INTC0_IMRL_INT_MASK15     (0x00008000)
#define MCF_INTC0_IMRL_INT_MASK16     (0x00010000)
#define MCF_INTC0_IMRL_INT_MASK17     (0x00020000)
#define MCF_INTC0_IMRL_INT_MASK18     (0x00040000)
#define MCF_INTC0_IMRL_INT_MASK19     (0x00080000)
#define MCF_INTC0_IMRL_INT_MASK20     (0x00100000)
#define MCF_INTC0_IMRL_INT_MASK21     (0x00200000)
#define MCF_INTC0_IMRL_INT_MASK22     (0x00400000)
#define MCF_INTC0_IMRL_INT_MASK23     (0x00800000)
#define MCF_INTC0_IMRL_INT_MASK24     (0x01000000)
#define MCF_INTC0_IMRL_INT_MASK25     (0x02000000)
#define MCF_INTC0_IMRL_INT_MASK26     (0x04000000)
#define MCF_INTC0_IMRL_INT_MASK27     (0x08000000)
#define MCF_INTC0_IMRL_INT_MASK28     (0x10000000)
#define MCF_INTC0_IMRL_INT_MASK29     (0x20000000)
#define MCF_INTC0_IMRL_INT_MASK30     (0x40000000)
#define MCF_INTC0_IMRL_INT_MASK31     (0x80000000)

/* Bit definitions and macros for MCF_INTC0_INTFRCH */
#define MCF_INTC0_INTFRCH_INTFRC32    (0x00000001)
#define MCF_INTC0_INTFRCH_INTFRC33    (0x00000002)
#define MCF_INTC0_INTFRCH_INTFRC34    (0x00000004)
#define MCF_INTC0_INTFRCH_INTFRC35    (0x00000008)
#define MCF_INTC0_INTFRCH_INTFRC36    (0x00000010)
#define MCF_INTC0_INTFRCH_INTFRC37    (0x00000020)
#define MCF_INTC0_INTFRCH_INTFRC38    (0x00000040)
#define MCF_INTC0_INTFRCH_INTFRC39    (0x00000080)
#define MCF_INTC0_INTFRCH_INTFRC40    (0x00000100)
#define MCF_INTC0_INTFRCH_INTFRC41    (0x00000200)
#define MCF_INTC0_INTFRCH_INTFRC42    (0x00000400)
#define MCF_INTC0_INTFRCH_INTFRC43    (0x00000800)
#define MCF_INTC0_INTFRCH_INTFRC44    (0x00001000)
#define MCF_INTC0_INTFRCH_INTFRC45    (0x00002000)
#define MCF_INTC0_INTFRCH_INTFRC46    (0x00004000)
#define MCF_INTC0_INTFRCH_INTFRC47    (0x00008000)
#define MCF_INTC0_INTFRCH_INTFRC48    (0x00010000)
#define MCF_INTC0_INTFRCH_INTFRC49    (0x00020000)
#define MCF_INTC0_INTFRCH_INTFRC50    (0x00040000)
#define MCF_INTC0_INTFRCH_INTFRC51    (0x00080000)
#define MCF_INTC0_INTFRCH_INTFRC52    (0x00100000)
#define MCF_INTC0_INTFRCH_INTFRC53    (0x00200000)
#define MCF_INTC0_INTFRCH_INTFRC54    (0x00400000)
#define MCF_INTC0_INTFRCH_INTFRC55    (0x00800000)
#define MCF_INTC0_INTFRCH_INTFRC56    (0x01000000)
#define MCF_INTC0_INTFRCH_INTFRC57    (0x02000000)
#define MCF_INTC0_INTFRCH_INTFRC58    (0x04000000)
#define MCF_INTC0_INTFRCH_INTFRC59    (0x08000000)
#define MCF_INTC0_INTFRCH_INTFRC60    (0x10000000)
#define MCF_INTC0_INTFRCH_INTFRC61    (0x20000000)
#define MCF_INTC0_INTFRCH_INTFRC62    (0x40000000)
#define MCF_INTC0_INTFRCH_INTFRC63    (0x80000000)

/* Bit definitions and macros for MCF_INTC0_INTFRCL */
#define MCF_INTC0_INTFRCL_INTFRC1     (0x00000002)
#define MCF_INTC0_INTFRCL_INTFRC2     (0x00000004)
#define MCF_INTC0_INTFRCL_INTFRC3     (0x00000008)
#define MCF_INTC0_INTFRCL_INTFRC4     (0x00000010)
#define MCF_INTC0_INTFRCL_INTFRC5     (0x00000020)
#define MCF_INTC0_INTFRCL_INT6        (0x00000040)
#define MCF_INTC0_INTFRCL_INT7        (0x00000080)
#define MCF_INTC0_INTFRCL_INT8        (0x00000100)
#define MCF_INTC0_INTFRCL_INT9        (0x00000200)
#define MCF_INTC0_INTFRCL_INT10       (0x00000400)
#define MCF_INTC0_INTFRCL_INTFRC11    (0x00000800)
#define MCF_INTC0_INTFRCL_INTFRC12    (0x00001000)
#define MCF_INTC0_INTFRCL_INTFRC13    (0x00002000)
#define MCF_INTC0_INTFRCL_INTFRC14    (0x00004000)
#define MCF_INTC0_INTFRCL_INT15       (0x00008000)
#define MCF_INTC0_INTFRCL_INTFRC16    (0x00010000)
#define MCF_INTC0_INTFRCL_INTFRC17    (0x00020000)
#define MCF_INTC0_INTFRCL_INTFRC18    (0x00040000)
#define MCF_INTC0_INTFRCL_INTFRC19    (0x00080000)
#define MCF_INTC0_INTFRCL_INTFRC20    (0x00100000)
#define MCF_INTC0_INTFRCL_INTFRC21    (0x00200000)
#define MCF_INTC0_INTFRCL_INTFRC22    (0x00400000)
#define MCF_INTC0_INTFRCL_INTFRC23    (0x00800000)
#define MCF_INTC0_INTFRCL_INTFRC24    (0x01000000)
#define MCF_INTC0_INTFRCL_INTFRC25    (0x02000000)
#define MCF_INTC0_INTFRCL_INTFRC26    (0x04000000)
#define MCF_INTC0_INTFRCL_INTFRC27    (0x08000000)
#define MCF_INTC0_INTFRCL_INTFRC28    (0x10000000)
#define MCF_INTC0_INTFRCL_INTFRC29    (0x20000000)
#define MCF_INTC0_INTFRCL_INTFRC30    (0x40000000)
#define MCF_INTC0_INTFRCL_INTFRC31    (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IRLR */
#define MCF_INTC0_IRLR_IRQ(x)         (((x)&0x7F)<<1)

/* Bit definitions and macros for MCF_INTC0_IACKLPR */
#define MCF_INTC0_IACKLPR_PRI(x)      (((x)&0x0F)<<0)
#define MCF_INTC0_IACKLPR_LEVEL(x)    (((x)&0x07)<<4)

/* Bit definitions and macros for MCF_INTC0_ICRn */
#define MCF_INTC0_ICRn_IP(x)          (((x)&0x07)<<0)
#define MCF_INTC0_ICRn_IL(x)          (((x)&0x07)<<3)

/********************************************************************/

#endif /* __MCF523X_INTC0_H__ */
=======
/*
 * These files are taken from the MCF523X source code example package
 * which is available on the Freescale website. Freescale explicitly 
 * grants the redistribution and modification of these source files.
 * The complete licensing information is available in the file 
 * LICENSE_FREESCALE.TXT.
 *
 * File:	mcf523x_intc0.h
 * Purpose:	Register and bit definitions for the MCF523X
 *
 * Notes:	
 *	
 */

#ifndef __MCF523X_INTC0_H__
#define __MCF523X_INTC0_H__

/*********************************************************************
*
* Interrupt Controller 0 (INTC0)
*
*********************************************************************/

/* Register read/write macros */
#define MCF_INTC0_IPRH         (*(vuint32*)(void*)(&__IPSBAR[0x000C00]))
#define MCF_INTC0_IPRL         (*(vuint32*)(void*)(&__IPSBAR[0x000C04]))
#define MCF_INTC0_IMRH         (*(vuint32*)(void*)(&__IPSBAR[0x000C08]))
#define MCF_INTC0_IMRL         (*(vuint32*)(void*)(&__IPSBAR[0x000C0C]))
#define MCF_INTC0_INTFRCH      (*(vuint32*)(void*)(&__IPSBAR[0x000C10]))
#define MCF_INTC0_INTFRCL      (*(vuint32*)(void*)(&__IPSBAR[0x000C14]))
#define MCF_INTC0_IRLR         (*(vuint8 *)(void*)(&__IPSBAR[0x000C18]))
#define MCF_INTC0_IACKLPR      (*(vuint8 *)(void*)(&__IPSBAR[0x000C19]))
#define MCF_INTC0_ICR0         (*(vuint8 *)(void*)(&__IPSBAR[0x000C40]))
#define MCF_INTC0_ICR1         (*(vuint8 *)(void*)(&__IPSBAR[0x000C41]))
#define MCF_INTC0_ICR2         (*(vuint8 *)(void*)(&__IPSBAR[0x000C42]))
#define MCF_INTC0_ICR3         (*(vuint8 *)(void*)(&__IPSBAR[0x000C43]))
#define MCF_INTC0_ICR4         (*(vuint8 *)(void*)(&__IPSBAR[0x000C44]))
#define MCF_INTC0_ICR5         (*(vuint8 *)(void*)(&__IPSBAR[0x000C45]))
#define MCF_INTC0_ICR6         (*(vuint8 *)(void*)(&__IPSBAR[0x000C46]))
#define MCF_INTC0_ICR7         (*(vuint8 *)(void*)(&__IPSBAR[0x000C47]))
#define MCF_INTC0_ICR8         (*(vuint8 *)(void*)(&__IPSBAR[0x000C48]))
#define MCF_INTC0_ICR9         (*(vuint8 *)(void*)(&__IPSBAR[0x000C49]))
#define MCF_INTC0_ICR10        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4A]))
#define MCF_INTC0_ICR11        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4B]))
#define MCF_INTC0_ICR12        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4C]))
#define MCF_INTC0_ICR13        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4D]))
#define MCF_INTC0_ICR14        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4E]))
#define MCF_INTC0_ICR15        (*(vuint8 *)(void*)(&__IPSBAR[0x000C4F]))
#define MCF_INTC0_ICR16        (*(vuint8 *)(void*)(&__IPSBAR[0x000C50]))
#define MCF_INTC0_ICR17        (*(vuint8 *)(void*)(&__IPSBAR[0x000C51]))
#define MCF_INTC0_ICR18        (*(vuint8 *)(void*)(&__IPSBAR[0x000C52]))
#define MCF_INTC0_ICR19        (*(vuint8 *)(void*)(&__IPSBAR[0x000C53]))
#define MCF_INTC0_ICR20        (*(vuint8 *)(void*)(&__IPSBAR[0x000C54]))
#define MCF_INTC0_ICR21        (*(vuint8 *)(void*)(&__IPSBAR[0x000C55]))
#define MCF_INTC0_ICR22        (*(vuint8 *)(void*)(&__IPSBAR[0x000C56]))
#define MCF_INTC0_ICR23        (*(vuint8 *)(void*)(&__IPSBAR[0x000C57]))
#define MCF_INTC0_ICR24        (*(vuint8 *)(void*)(&__IPSBAR[0x000C58]))
#define MCF_INTC0_ICR25        (*(vuint8 *)(void*)(&__IPSBAR[0x000C59]))
#define MCF_INTC0_ICR26        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5A]))
#define MCF_INTC0_ICR27        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5B]))
#define MCF_INTC0_ICR28        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5C]))
#define MCF_INTC0_ICR29        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5D]))
#define MCF_INTC0_ICR30        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5E]))
#define MCF_INTC0_ICR31        (*(vuint8 *)(void*)(&__IPSBAR[0x000C5F]))
#define MCF_INTC0_ICR32        (*(vuint8 *)(void*)(&__IPSBAR[0x000C60]))
#define MCF_INTC0_ICR33        (*(vuint8 *)(void*)(&__IPSBAR[0x000C61]))
#define MCF_INTC0_ICR34        (*(vuint8 *)(void*)(&__IPSBAR[0x000C62]))
#define MCF_INTC0_ICR35        (*(vuint8 *)(void*)(&__IPSBAR[0x000C63]))
#define MCF_INTC0_ICR36        (*(vuint8 *)(void*)(&__IPSBAR[0x000C64]))
#define MCF_INTC0_ICR37        (*(vuint8 *)(void*)(&__IPSBAR[0x000C65]))
#define MCF_INTC0_ICR38        (*(vuint8 *)(void*)(&__IPSBAR[0x000C66]))
#define MCF_INTC0_ICR39        (*(vuint8 *)(void*)(&__IPSBAR[0x000C67]))
#define MCF_INTC0_ICR40        (*(vuint8 *)(void*)(&__IPSBAR[0x000C68]))
#define MCF_INTC0_ICR41        (*(vuint8 *)(void*)(&__IPSBAR[0x000C69]))
#define MCF_INTC0_ICR42        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6A]))
#define MCF_INTC0_ICR43        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6B]))
#define MCF_INTC0_ICR44        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6C]))
#define MCF_INTC0_ICR45        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6D]))
#define MCF_INTC0_ICR46        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6E]))
#define MCF_INTC0_ICR47        (*(vuint8 *)(void*)(&__IPSBAR[0x000C6F]))
#define MCF_INTC0_ICR48        (*(vuint8 *)(void*)(&__IPSBAR[0x000C70]))
#define MCF_INTC0_ICR49        (*(vuint8 *)(void*)(&__IPSBAR[0x000C71]))
#define MCF_INTC0_ICR50        (*(vuint8 *)(void*)(&__IPSBAR[0x000C72]))
#define MCF_INTC0_ICR51        (*(vuint8 *)(void*)(&__IPSBAR[0x000C73]))
#define MCF_INTC0_ICR52        (*(vuint8 *)(void*)(&__IPSBAR[0x000C74]))
#define MCF_INTC0_ICR53        (*(vuint8 *)(void*)(&__IPSBAR[0x000C75]))
#define MCF_INTC0_ICR54        (*(vuint8 *)(void*)(&__IPSBAR[0x000C76]))
#define MCF_INTC0_ICR55        (*(vuint8 *)(void*)(&__IPSBAR[0x000C77]))
#define MCF_INTC0_ICR56        (*(vuint8 *)(void*)(&__IPSBAR[0x000C78]))
#define MCF_INTC0_ICR57        (*(vuint8 *)(void*)(&__IPSBAR[0x000C79]))
#define MCF_INTC0_ICR58        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7A]))
#define MCF_INTC0_ICR59        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7B]))
#define MCF_INTC0_ICR60        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7C]))
#define MCF_INTC0_ICR61        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7D]))
#define MCF_INTC0_ICR62        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7E]))
#define MCF_INTC0_ICR63        (*(vuint8 *)(void*)(&__IPSBAR[0x000C7F]))
#define MCF_INTC0_ICRn(x)      (*(vuint8 *)(void*)(&__IPSBAR[0x000C40+((x)*0x001)]))
#define MCF_INTC0_SWIACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CE0]))
#define MCF_INTC0_L1IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CE4]))
#define MCF_INTC0_L2IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CE8]))
#define MCF_INTC0_L3IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CEC]))
#define MCF_INTC0_L4IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CF0]))
#define MCF_INTC0_L5IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CF4]))
#define MCF_INTC0_L6IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CF8]))
#define MCF_INTC0_L7IACK       (*(vuint8 *)(void*)(&__IPSBAR[0x000CFC]))
#define MCF_INTC0_LnIACK(x)    (*(vuint8 *)(void*)(&__IPSBAR[0x000CE4+((x)*0x004)]))

/* Bit definitions and macros for MCF_INTC0_IPRH */
#define MCF_INTC0_IPRH_INT32          (0x00000001)
#define MCF_INTC0_IPRH_INT33          (0x00000002)
#define MCF_INTC0_IPRH_INT34          (0x00000004)
#define MCF_INTC0_IPRH_INT35          (0x00000008)
#define MCF_INTC0_IPRH_INT36          (0x00000010)
#define MCF_INTC0_IPRH_INT37          (0x00000020)
#define MCF_INTC0_IPRH_INT38          (0x00000040)
#define MCF_INTC0_IPRH_INT39          (0x00000080)
#define MCF_INTC0_IPRH_INT40          (0x00000100)
#define MCF_INTC0_IPRH_INT41          (0x00000200)
#define MCF_INTC0_IPRH_INT42          (0x00000400)
#define MCF_INTC0_IPRH_INT43          (0x00000800)
#define MCF_INTC0_IPRH_INT44          (0x00001000)
#define MCF_INTC0_IPRH_INT45          (0x00002000)
#define MCF_INTC0_IPRH_INT46          (0x00004000)
#define MCF_INTC0_IPRH_INT47          (0x00008000)
#define MCF_INTC0_IPRH_INT48          (0x00010000)
#define MCF_INTC0_IPRH_INT49          (0x00020000)
#define MCF_INTC0_IPRH_INT50          (0x00040000)
#define MCF_INTC0_IPRH_INT51          (0x00080000)
#define MCF_INTC0_IPRH_INT52          (0x00100000)
#define MCF_INTC0_IPRH_INT53          (0x00200000)
#define MCF_INTC0_IPRH_INT54          (0x00400000)
#define MCF_INTC0_IPRH_INT55          (0x00800000)
#define MCF_INTC0_IPRH_INT56          (0x01000000)
#define MCF_INTC0_IPRH_INT57          (0x02000000)
#define MCF_INTC0_IPRH_INT58          (0x04000000)
#define MCF_INTC0_IPRH_INT59          (0x08000000)
#define MCF_INTC0_IPRH_INT60          (0x10000000)
#define MCF_INTC0_IPRH_INT61          (0x20000000)
#define MCF_INTC0_IPRH_INT62          (0x40000000)
#define MCF_INTC0_IPRH_INT63          (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IPRL */
#define MCF_INTC0_IPRL_INT1           (0x00000002)
#define MCF_INTC0_IPRL_INT2           (0x00000004)
#define MCF_INTC0_IPRL_INT3           (0x00000008)
#define MCF_INTC0_IPRL_INT4           (0x00000010)
#define MCF_INTC0_IPRL_INT5           (0x00000020)
#define MCF_INTC0_IPRL_INT6           (0x00000040)
#define MCF_INTC0_IPRL_INT7           (0x00000080)
#define MCF_INTC0_IPRL_INT8           (0x00000100)
#define MCF_INTC0_IPRL_INT9           (0x00000200)
#define MCF_INTC0_IPRL_INT10          (0x00000400)
#define MCF_INTC0_IPRL_INT11          (0x00000800)
#define MCF_INTC0_IPRL_INT12          (0x00001000)
#define MCF_INTC0_IPRL_INT13          (0x00002000)
#define MCF_INTC0_IPRL_INT14          (0x00004000)
#define MCF_INTC0_IPRL_INT15          (0x00008000)
#define MCF_INTC0_IPRL_INT16          (0x00010000)
#define MCF_INTC0_IPRL_INT17          (0x00020000)
#define MCF_INTC0_IPRL_INT18          (0x00040000)
#define MCF_INTC0_IPRL_INT19          (0x00080000)
#define MCF_INTC0_IPRL_INT20          (0x00100000)
#define MCF_INTC0_IPRL_INT21          (0x00200000)
#define MCF_INTC0_IPRL_INT22          (0x00400000)
#define MCF_INTC0_IPRL_INT23          (0x00800000)
#define MCF_INTC0_IPRL_INT24          (0x01000000)
#define MCF_INTC0_IPRL_INT25          (0x02000000)
#define MCF_INTC0_IPRL_INT26          (0x04000000)
#define MCF_INTC0_IPRL_INT27          (0x08000000)
#define MCF_INTC0_IPRL_INT28          (0x10000000)
#define MCF_INTC0_IPRL_INT29          (0x20000000)
#define MCF_INTC0_IPRL_INT30          (0x40000000)
#define MCF_INTC0_IPRL_INT31          (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IMRH */
#define MCF_INTC0_IMRH_INT_MASK32     (0x00000001)
#define MCF_INTC0_IMRH_INT_MASK33     (0x00000002)
#define MCF_INTC0_IMRH_INT_MASK34     (0x00000004)
#define MCF_INTC0_IMRH_INT_MASK35     (0x00000008)
#define MCF_INTC0_IMRH_INT_MASK36     (0x00000010)
#define MCF_INTC0_IMRH_INT_MASK37     (0x00000020)
#define MCF_INTC0_IMRH_INT_MASK38     (0x00000040)
#define MCF_INTC0_IMRH_INT_MASK39     (0x00000080)
#define MCF_INTC0_IMRH_INT_MASK40     (0x00000100)
#define MCF_INTC0_IMRH_INT_MASK41     (0x00000200)
#define MCF_INTC0_IMRH_INT_MASK42     (0x00000400)
#define MCF_INTC0_IMRH_INT_MASK43     (0x00000800)
#define MCF_INTC0_IMRH_INT_MASK44     (0x00001000)
#define MCF_INTC0_IMRH_INT_MASK45     (0x00002000)
#define MCF_INTC0_IMRH_INT_MASK46     (0x00004000)
#define MCF_INTC0_IMRH_INT_MASK47     (0x00008000)
#define MCF_INTC0_IMRH_INT_MASK48     (0x00010000)
#define MCF_INTC0_IMRH_INT_MASK49     (0x00020000)
#define MCF_INTC0_IMRH_INT_MASK50     (0x00040000)
#define MCF_INTC0_IMRH_INT_MASK51     (0x00080000)
#define MCF_INTC0_IMRH_INT_MASK52     (0x00100000)
#define MCF_INTC0_IMRH_INT_MASK53     (0x00200000)
#define MCF_INTC0_IMRH_INT_MASK54     (0x00400000)
#define MCF_INTC0_IMRH_INT_MASK55     (0x00800000)
#define MCF_INTC0_IMRH_INT_MASK56     (0x01000000)
#define MCF_INTC0_IMRH_INT_MASK57     (0x02000000)
#define MCF_INTC0_IMRH_INT_MASK58     (0x04000000)
#define MCF_INTC0_IMRH_INT_MASK59     (0x08000000)
#define MCF_INTC0_IMRH_INT_MASK60     (0x10000000)
#define MCF_INTC0_IMRH_INT_MASK61     (0x20000000)
#define MCF_INTC0_IMRH_INT_MASK62     (0x40000000)
#define MCF_INTC0_IMRH_INT_MASK63     (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IMRL */
#define MCF_INTC0_IMRL_MASKALL        (0x00000001)
#define MCF_INTC0_IMRL_INT_MASK1      (0x00000002)
#define MCF_INTC0_IMRL_INT_MASK2      (0x00000004)
#define MCF_INTC0_IMRL_INT_MASK3      (0x00000008)
#define MCF_INTC0_IMRL_INT_MASK4      (0x00000010)
#define MCF_INTC0_IMRL_INT_MASK5      (0x00000020)
#define MCF_INTC0_IMRL_INT_MASK6      (0x00000040)
#define MCF_INTC0_IMRL_INT_MASK7      (0x00000080)
#define MCF_INTC0_IMRL_INT_MASK8      (0x00000100)
#define MCF_INTC0_IMRL_INT_MASK9      (0x00000200)
#define MCF_INTC0_IMRL_INT_MASK10     (0x00000400)
#define MCF_INTC0_IMRL_INT_MASK11     (0x00000800)
#define MCF_INTC0_IMRL_INT_MASK12     (0x00001000)
#define MCF_INTC0_IMRL_INT_MASK13     (0x00002000)
#define MCF_INTC0_IMRL_INT_MASK14     (0x00004000)
#define MCF_INTC0_IMRL_INT_MASK15     (0x00008000)
#define MCF_INTC0_IMRL_INT_MASK16     (0x00010000)
#define MCF_INTC0_IMRL_INT_MASK17     (0x00020000)
#define MCF_INTC0_IMRL_INT_MASK18     (0x00040000)
#define MCF_INTC0_IMRL_INT_MASK19     (0x00080000)
#define MCF_INTC0_IMRL_INT_MASK20     (0x00100000)
#define MCF_INTC0_IMRL_INT_MASK21     (0x00200000)
#define MCF_INTC0_IMRL_INT_MASK22     (0x00400000)
#define MCF_INTC0_IMRL_INT_MASK23     (0x00800000)
#define MCF_INTC0_IMRL_INT_MASK24     (0x01000000)
#define MCF_INTC0_IMRL_INT_MASK25     (0x02000000)
#define MCF_INTC0_IMRL_INT_MASK26     (0x04000000)
#define MCF_INTC0_IMRL_INT_MASK27     (0x08000000)
#define MCF_INTC0_IMRL_INT_MASK28     (0x10000000)
#define MCF_INTC0_IMRL_INT_MASK29     (0x20000000)
#define MCF_INTC0_IMRL_INT_MASK30     (0x40000000)
#define MCF_INTC0_IMRL_INT_MASK31     (0x80000000)

/* Bit definitions and macros for MCF_INTC0_INTFRCH */
#define MCF_INTC0_INTFRCH_INTFRC32    (0x00000001)
#define MCF_INTC0_INTFRCH_INTFRC33    (0x00000002)
#define MCF_INTC0_INTFRCH_INTFRC34    (0x00000004)
#define MCF_INTC0_INTFRCH_INTFRC35    (0x00000008)
#define MCF_INTC0_INTFRCH_INTFRC36    (0x00000010)
#define MCF_INTC0_INTFRCH_INTFRC37    (0x00000020)
#define MCF_INTC0_INTFRCH_INTFRC38    (0x00000040)
#define MCF_INTC0_INTFRCH_INTFRC39    (0x00000080)
#define MCF_INTC0_INTFRCH_INTFRC40    (0x00000100)
#define MCF_INTC0_INTFRCH_INTFRC41    (0x00000200)
#define MCF_INTC0_INTFRCH_INTFRC42    (0x00000400)
#define MCF_INTC0_INTFRCH_INTFRC43    (0x00000800)
#define MCF_INTC0_INTFRCH_INTFRC44    (0x00001000)
#define MCF_INTC0_INTFRCH_INTFRC45    (0x00002000)
#define MCF_INTC0_INTFRCH_INTFRC46    (0x00004000)
#define MCF_INTC0_INTFRCH_INTFRC47    (0x00008000)
#define MCF_INTC0_INTFRCH_INTFRC48    (0x00010000)
#define MCF_INTC0_INTFRCH_INTFRC49    (0x00020000)
#define MCF_INTC0_INTFRCH_INTFRC50    (0x00040000)
#define MCF_INTC0_INTFRCH_INTFRC51    (0x00080000)
#define MCF_INTC0_INTFRCH_INTFRC52    (0x00100000)
#define MCF_INTC0_INTFRCH_INTFRC53    (0x00200000)
#define MCF_INTC0_INTFRCH_INTFRC54    (0x00400000)
#define MCF_INTC0_INTFRCH_INTFRC55    (0x00800000)
#define MCF_INTC0_INTFRCH_INTFRC56    (0x01000000)
#define MCF_INTC0_INTFRCH_INTFRC57    (0x02000000)
#define MCF_INTC0_INTFRCH_INTFRC58    (0x04000000)
#define MCF_INTC0_INTFRCH_INTFRC59    (0x08000000)
#define MCF_INTC0_INTFRCH_INTFRC60    (0x10000000)
#define MCF_INTC0_INTFRCH_INTFRC61    (0x20000000)
#define MCF_INTC0_INTFRCH_INTFRC62    (0x40000000)
#define MCF_INTC0_INTFRCH_INTFRC63    (0x80000000)

/* Bit definitions and macros for MCF_INTC0_INTFRCL */
#define MCF_INTC0_INTFRCL_INTFRC1     (0x00000002)
#define MCF_INTC0_INTFRCL_INTFRC2     (0x00000004)
#define MCF_INTC0_INTFRCL_INTFRC3     (0x00000008)
#define MCF_INTC0_INTFRCL_INTFRC4     (0x00000010)
#define MCF_INTC0_INTFRCL_INTFRC5     (0x00000020)
#define MCF_INTC0_INTFRCL_INT6        (0x00000040)
#define MCF_INTC0_INTFRCL_INT7        (0x00000080)
#define MCF_INTC0_INTFRCL_INT8        (0x00000100)
#define MCF_INTC0_INTFRCL_INT9        (0x00000200)
#define MCF_INTC0_INTFRCL_INT10       (0x00000400)
#define MCF_INTC0_INTFRCL_INTFRC11    (0x00000800)
#define MCF_INTC0_INTFRCL_INTFRC12    (0x00001000)
#define MCF_INTC0_INTFRCL_INTFRC13    (0x00002000)
#define MCF_INTC0_INTFRCL_INTFRC14    (0x00004000)
#define MCF_INTC0_INTFRCL_INT15       (0x00008000)
#define MCF_INTC0_INTFRCL_INTFRC16    (0x00010000)
#define MCF_INTC0_INTFRCL_INTFRC17    (0x00020000)
#define MCF_INTC0_INTFRCL_INTFRC18    (0x00040000)
#define MCF_INTC0_INTFRCL_INTFRC19    (0x00080000)
#define MCF_INTC0_INTFRCL_INTFRC20    (0x00100000)
#define MCF_INTC0_INTFRCL_INTFRC21    (0x00200000)
#define MCF_INTC0_INTFRCL_INTFRC22    (0x00400000)
#define MCF_INTC0_INTFRCL_INTFRC23    (0x00800000)
#define MCF_INTC0_INTFRCL_INTFRC24    (0x01000000)
#define MCF_INTC0_INTFRCL_INTFRC25    (0x02000000)
#define MCF_INTC0_INTFRCL_INTFRC26    (0x04000000)
#define MCF_INTC0_INTFRCL_INTFRC27    (0x08000000)
#define MCF_INTC0_INTFRCL_INTFRC28    (0x10000000)
#define MCF_INTC0_INTFRCL_INTFRC29    (0x20000000)
#define MCF_INTC0_INTFRCL_INTFRC30    (0x40000000)
#define MCF_INTC0_INTFRCL_INTFRC31    (0x80000000)

/* Bit definitions and macros for MCF_INTC0_IRLR */
#define MCF_INTC0_IRLR_IRQ(x)         (((x)&0x7F)<<1)

/* Bit definitions and macros for MCF_INTC0_IACKLPR */
#define MCF_INTC0_IACKLPR_PRI(x)      (((x)&0x0F)<<0)
#define MCF_INTC0_IACKLPR_LEVEL(x)    (((x)&0x07)<<4)

/* Bit definitions and macros for MCF_INTC0_ICRn */
#define MCF_INTC0_ICRn_IP(x)          (((x)&0x07)<<0)
#define MCF_INTC0_ICRn_IL(x)          (((x)&0x07)<<3)

/********************************************************************/

#endif /* __MCF523X_INTC0_H__ */
>>>>>>> 16c66438 (Upload from PC.)