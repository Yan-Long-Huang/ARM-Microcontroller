<<<<<<< HEAD
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name     : r_typedefs.h
* Device(s)     : RZ/A1H (R7S910018)
* Tool-Chain    : GNUARM-NONEv14.02-EABI
* H/W Platform  : RSK+T1 CPU Board
* Description   : basic type definition
***********************************************************************************************************************/
/***********************************************************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 21.10.2014 1.00
***********************************************************************************************************************/


/***********************************************************************************************************************
Includes <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include <stdint.h>
/* Multiple inclusion prevention macro */
#ifndef R_TYPEDEFS_H
#define R_TYPEDEFS_H


/* in case <stdio.h> has defined it. */
#ifndef     NULL
#define     NULL        (0)
#endif

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#if !defined(__bool_true_false_are_defined) && !defined(__cplusplus)

#define     FALSE       (0)
#define     TRUE        (1)

#endif

/* These two macros are used to suppress warnings generated by unused variables.
   Writing to some registers require a read instruction following the write.
   A dummy variable is declared and used to read the register written to. */
#define     UNUSED_PARAM(param)             ((void)(param))
#define     UNUSED_VARIABLE(param)          ((void)(param))

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef char                char_t;
typedef unsigned int        bool_t;
typedef int                 int_t;
typedef float               float32_t;
typedef double              float64_t;
typedef long double         float128_t;

/* R_TYPEDEFS_H */
#endif

=======
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name     : r_typedefs.h
* Device(s)     : RZ/A1H (R7S910018)
* Tool-Chain    : GNUARM-NONEv14.02-EABI
* H/W Platform  : RSK+T1 CPU Board
* Description   : basic type definition
***********************************************************************************************************************/
/***********************************************************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 21.10.2014 1.00
***********************************************************************************************************************/


/***********************************************************************************************************************
Includes <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include <stdint.h>
/* Multiple inclusion prevention macro */
#ifndef R_TYPEDEFS_H
#define R_TYPEDEFS_H


/* in case <stdio.h> has defined it. */
#ifndef     NULL
#define     NULL        (0)
#endif

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#if !defined(__bool_true_false_are_defined) && !defined(__cplusplus)

#define     FALSE       (0)
#define     TRUE        (1)

#endif

/* These two macros are used to suppress warnings generated by unused variables.
   Writing to some registers require a read instruction following the write.
   A dummy variable is declared and used to read the register written to. */
#define     UNUSED_PARAM(param)             ((void)(param))
#define     UNUSED_VARIABLE(param)          ((void)(param))

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef char                char_t;
typedef unsigned int        bool_t;
typedef int                 int_t;
typedef float               float32_t;
typedef double              float64_t;
typedef long double         float128_t;

/* R_TYPEDEFS_H */
#endif

>>>>>>> 16c66438 (Upload from PC.)