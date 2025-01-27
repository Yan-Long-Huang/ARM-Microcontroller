<<<<<<< HEAD
/* ----------------------------------------------------------------------------
 *         SAM Software Package License 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * USB Device Framework configurations.
 *
 */

#ifndef USBD_CONFIG_H
#define USBD_CONFIG_H

/*----------------------------------------------------------------------------
 *      Headers
 *----------------------------------------------------------------------------*/

#include "board.h"

/** \addtogroup usbd_config
 *@{
 */
/*----------------------------------------------------------------------------
 *      Constants
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_ids USBD Device IDs
 *      @{
 */
#define USBD_VID_ATMEL              0x03EB  /**< Vendor ID: Atmel */

#define USBD_PID_ENUM               0x0001  /**< Product ID: Enum (Core) */
#define USBD_PID_CDCDSERIAL         0x6119  /**< Product ID: CDC Serial */
#define USBD_PID_HIDKEYBOARD        0x6127  /**< Product ID: HID Keyboard */
#define USBD_PID_AUDIO              0x6128  /**< Product ID: Audio devices */
#define USBD_PID_MSD                0x6129  /**< Product ID: Massstorage */
#define USBD_PID_CDCHID             0x6130  /**< Product ID: composite */
#define USBD_PID_CDCAUDIO           0x6131  /**< Product ID: composite */
#define USBD_PID_CDCMSD             0x6132  /**< Product ID: composite */
#define USBD_PID_CDCCDC             0x6133  /**< Product ID: composite */
#define USBD_PID_HIDAUDIO           0x6134  /**< Product ID: composite */
#define USBD_PID_HIDMSD             0x6135  /**< Product ID: composite */
#define USBD_PID_HIDMOUSE           0x6200  /**< Product ID: HID Mouse */
#define USBD_PID_HIDTRANSFER        0x6201  /**< Product ID: HID Transfer */
#define USBD_PID_CCID               0x6203  /**< Product ID: CCID */
#define USBD_PID_UVC                0x6136  /**< Product ID: UVC  */

#define USBD_RELEASE_1_00           0x0100  /**< Release: 1.00 */
#define USBD_RELEASE_0_01           0x0001  /**< Release: 0.01 */
/**     @}*/

/** \addtogroup usbd_general_config USBD General Configure
 *      @{
 * This page lists general configurations for all USB device drivers.
 * - \ref USBD_BMATTRIBUTES
 */
/** default USB Device attributes configuration descriptor
 *  (bus or self powered, remote wakeup) */
#define USBD_BMATTRIBUTES           BOARD_USB_BMATTRIBUTES
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Mass storage
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_msdd_config USB MassStorage Configure
 *      @{
 * This page lists the defines used by the Mass Storage driver.
 *
 * \section msd_ep_addr Endpoint Addresses
 * - \ref MSDDriverDescriptors_BULKOUT
 * - \ref MSDDriverDescriptors_BULKIN
 */
/** Address of the Mass Storage bulk-out endpoint.*/
#define MSDDriverDescriptors_BULKOUT                2
/** Address of the Mass Storage bulk-in endpoint.*/
#define MSDDriverDescriptors_BULKIN                 3
/**      @}*/

/*----------------------------------------------------------------------------
 *      USB Device - CDC Serial
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_cdc_serial_config USB CDC Serial Configure
 *      @{
 * This page lists the defines used by the CDC Serial Device Driver.
 *
 * \section cdcd_ep_addr Endpoint Addresses
 * - \ref CDCDSerialDriverDescriptors_DATAOUT
 * - \ref CDCDSerialDriverDescriptors_DATAIN
 * - \ref CDCDSerialDriverDescriptors_NOTIFICATION
 */
/** Data OUT endpoint number */
#define CDCDSerialDriverDescriptors_DATAOUT             2
/** Data IN endpoint number */
#define CDCDSerialDriverDescriptors_DATAIN              3
/** Notification endpoint number */
#define CDCDSerialDriverDescriptors_NOTIFICATION        4
/**      @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Audio
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_audio_config USB Audio General Configure
 *      @{
 * This page lists definitions for USB Audio Devices Drivers.
 * - \ref
 */

/** Sample rate in Hz. */
#define AUDDevice_SAMPLERATE        48000UL
/** Number of channels in audio stream. */
#define AUDDevice_NUMCHANNELS       2
/** Number of bytes in one sample. */
#define AUDDevice_BYTESPERSAMPLE    2

/** Number of bits in one sample. */
#define AUDDevice_BITSPERSAMPLE     (AUDDevice_BYTESPERSAMPLE * 8)
/** Number of bytes in one USB subframe. */
#define AUDDevice_BYTESPERSUBFRAME  (AUDDevice_NUMCHANNELS * \
                                     AUDDevice_BYTESPERSAMPLE)
/** Number of samples in one USB frame. */
#define AUDDevice_SAMPLESPERFRAME   (AUDDevice_SAMPLERATE / 1000 \
                                     * AUDDevice_NUMCHANNELS)
/** Number of bytes in one USB frame. */
#define AUDDevice_BYTESPERFRAME     (AUDDevice_SAMPLESPERFRAME * \
                                     AUDDevice_BYTESPERSAMPLE)
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Audio - Desktop Speaker
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_audio_speaker_config USB Speaker Configure
 *      @{
 * This page lists the definitions for USB Audio Speaker Device Driver.
 * - \ref AUDDSpeakerDriverDescriptors_DATAOUT
 * - \ref AUDDSpeakerDriverDescriptors_FS_INTERVAL
 * - \ref AUDDSpeakerDriverDescriptors_HS_INTERVAL
 *
 * \note for UDP, uses IN EPs that support double buffer; for UDPHS, uses
 *       IN EPs that support DMA and High bandwidth.
 */
/** Data out endpoint number. */
#define AUDDSpeakerDriverDescriptors_DATAOUT            0x02
/** Endpoint polling interval 2^(x-1) * 125us */
#define AUDDSpeakerDriverDescriptors_HS_INTERVAL        0x04
/** Endpoint polling interval 2^(x-1) * ms */
#define AUDDSpeakerDriverDescriptors_FS_INTERVAL        0x01
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Audio - Speaker Phone
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_audio_speakerphone_config USB Speaker Phone Configure
 *      @{
 * This page lists the definitions for USB Audio Speaker Phone Device Driver.
 * - \ref AUDDSpeakerPhoneDriverDescriptors_DATAOUT
 * - \ref AUDDSpeakerPhoneDriverDescriptors_DATAIN
 * - \ref AUDDSpeakerPhoneDriverDescriptors_HS_INTERVAL
 * - \ref AUDDSpeakerPhoneDriverDescriptors_FS_INTERVAL
 */


/** Data out endpoint number, size 192B */
#define AUDDSpeakerPhoneDriverDescriptors_DATAOUT        0x02
/** Data in endpoint number, size 192B */
#define AUDDSpeakerPhoneDriverDescriptors_DATAIN         0x01

/** Endpoint polling interval 2^(x-1) * 125us */
#define AUDDSpeakerPhoneDriverDescriptors_HS_INTERVAL        0x04
/** Endpoint polling interval 2^(x-1) * ms */
#define AUDDSpeakerPhoneDriverDescriptors_FS_INTERVAL        0x01
/**      @}*/

/*----------------------------------------------------------------------------
 *      USB Device - HID - Keyboard
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_hid_keyboard_config USB HID Keyboard Device Configure
 *      @{
 * This page lists the defines used by the HID Keyboard Device Driver.
 *
 * \section hidd_k_ep_addr Endpoint Addresses
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTIN
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTOUT
 * \section hidd_k_ep_polling Endpoint Polling Rate
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTIN_POLLING
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTOUT_POLLING
 */
/** Interrupt IN endpoint number */
#define HIDDKeyboardDriverDescriptors_INTERRUPTIN           2
/** Interrupt IN endpoint polling rate (in milliseconds) */
#define HIDDKeyboardDriverDescriptors_INTERRUPTIN_POLLING   10
/** Interrupt OUT endpoint number */
#define HIDDKeyboardDriverDescriptors_INTERRUPTOUT          3
/** Interrupt OUT endpoint polling rate (in milliseconds) */
#define HIDDKeyboardDriverDescriptors_INTERRUPTOUT_POLLING  10
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - HID  - Mouse
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_hid_mouse_config USB HID Mouse Device Configure
 *      @{
 * This page lists the defines used by the HID Mouse Device Driver.
 *
 * \section hidd_m_ep_addr Endpoint Addresses
 * - \ref HIDDMouseDriverDescriptors_INTERRUPTIN
 * \section hidd_m_ep_polling Endpoint Polling Rate
 * - \ref HIDDMouseDriverDescriptors_INTERRUPTIN_POLLING
 */
/** Interrupt IN endpoint number */
#define HIDDMouseDriverDescriptors_INTERRUPTIN           2
/** Interrupt IN endpoint polling rate (in milliseconds) */
#define HIDDMouseDriverDescriptors_INTERRUPTIN_POLLING   8
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - HID  - Transfer (Customize device)
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_hid_xfr_config USB HID Transfer Device Configure
 *      @{
 * This page lists the defines used by the HID Transfer Device Driver.
 *
 * \section hidd_t_ep_addr Endpoint Addresses
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTIN
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTOUT
 * \section hidd_t_ep_polling Endpoint Polling Rate
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTIN_POLLING
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTOUT_POLLING
 */
/** Interrupt IN endpoint number. */
#define HIDDTransferDriverDescriptors_INTERRUPTIN           2
/** Polling rate in ms */
#define HIDDTransferDriverDescriptors_INTERRUPTIN_POLLING   50
/** Interrupt IN endpoint polling rate (in milliseconds). */
#define HIDDTransferDriverDescriptors_INTERRUPTOUT          3
/** Polling rate in ms */
#define HIDDTransferDriverDescriptors_INTERRUPTOUT_POLLING  50
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Composite
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_composite_config USB Composite Device Configure
 *  @{
 */

/*----------------------------------------------------------------------------
 *      USB Device - HID_AUD
 *----------------------------------------------------------------------------*/

/** Address of the HID interrupt IN endpoint. */
#define HIDAUDD_Descriptors_INTERRUPTIN                0x03
/** Address of the HID interrupt OUT endpoint. */
#define HIDAUDD_Descriptors_INTERRUPTOUT               0x04

/** Audio data out endpoint number */
#define HIDAUDD_Descriptors_ISO_DATAOUT                0x02


/*----------------------------------------------------------------------------
 *      USB Device - CDC AUD
 *----------------------------------------------------------------------------*/

/** Address of the CDC interrupt-in endpoint. */
#define CDCAUDD_Descriptors_NOTIFICATION0              0x04
/** Address of the CDC bulk-in endpoint. */
#define CDCAUDD_Descriptors_DATAIN0                    0x03
/** Address of the CDC bulk-out endpoint. */
#define CDCAUDD_Descriptors_DATAOUT0                   0x02
/** Address of the Audio ISO-out endpoint. */
#define CDCAUDD_Descriptors_ISO_DATAOUT                0x01


/*----------------------------------------------------------------------------
 *      USB Device - DUAL CDC
 *----------------------------------------------------------------------------*/

/// Address of the CDC0 interrupt-in endpoint.
#define CDCD_Descriptors_NOTIFICATION0              3
/// Address of the CDC0 bulk-in endpoint.
#define CDCD_Descriptors_DATAIN0                    2
/// Address of the CDC0 bulk-out endpoint.
#define CDCD_Descriptors_DATAOUT0                   1

/// Address of the CDC1 interrupt-in endpoint.
#define CDCD_Descriptors_NOTIFICATION1              6
/// Address of the CDC1 bulk-in endpoint.
#define CDCD_Descriptors_DATAIN1                    5
/// Address of the CDC1 bulk-out endpoint.
#define CDCD_Descriptors_DATAOUT1                   4


/*----------------------------------------------------------------------------
 *      USB Device - HID CDC
 *----------------------------------------------------------------------------*/


/** Address of the CDC interrupt-in endpoint. */
#define CDCD_Descriptors_NOTIFICATION0              3
/** Address of the CDC bulk-in endpoint. */
#define CDCD_Descriptors_DATAIN0                    2
/** Address of the CDC bulk-out endpoint. */
#define CDCD_Descriptors_DATAOUT0                   1

/** Address of the HID interrupt IN endpoint. */
#define HIDD_Descriptors_INTERRUPTIN                4
/** Address of the HID interrupt OUT endpoint. */
#define HIDD_Descriptors_INTERRUPTOUT               5



/*----------------------------------------------------------------------------
 *      USB Device - HID MSD
 *----------------------------------------------------------------------------*/

/** Address of the Mass Storage bulk-out endpoint. */
#define HIDMSDD_Descriptors_BULKOUT                    2
/** Address of the Mass Storage bulk-in endpoint. */
#define HIDMSDD_Descriptors_BULKIN                     3

/** Address of the HID interrupt IN endpoint. */
#define HIDMSDD_Descriptors_INTERRUPTIN                4
/** Address of the HID interrupt OUT endpoint. */
#define HIDMSDD_Descriptors_INTERRUPTOUT               5

/*----------------------------------------------------------------------------
 *      USB Device - MSD CDC
 *----------------------------------------------------------------------------*/

/** Address of the CDC interrupt-in endpoint. */
#define CDCD_Descriptors_NOTIFICATION0              3
/** Address of the CDC bulk-in endpoint. */
#define CDCD_Descriptors_DATAIN0                    2
/** Address of the CDC bulk-out endpoint. */
#define CDCD_Descriptors_DATAOUT0                   1
/** Address of the Mass Storage bulk-out endpoint. */
#define MSDD_Descriptors_BULKOUT                    4
/** Address of the Mass Storage bulk-in endpoint. */
#define MSDD_Descriptors_BULKIN                     5

/** @}*/

/**@}*/
#endif //#ifndef USBD_CONFIG_H


=======
/* ----------------------------------------------------------------------------
 *         SAM Software Package License 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * USB Device Framework configurations.
 *
 */

#ifndef USBD_CONFIG_H
#define USBD_CONFIG_H

/*----------------------------------------------------------------------------
 *      Headers
 *----------------------------------------------------------------------------*/

#include "board.h"

/** \addtogroup usbd_config
 *@{
 */
/*----------------------------------------------------------------------------
 *      Constants
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_ids USBD Device IDs
 *      @{
 */
#define USBD_VID_ATMEL              0x03EB  /**< Vendor ID: Atmel */

#define USBD_PID_ENUM               0x0001  /**< Product ID: Enum (Core) */
#define USBD_PID_CDCDSERIAL         0x6119  /**< Product ID: CDC Serial */
#define USBD_PID_HIDKEYBOARD        0x6127  /**< Product ID: HID Keyboard */
#define USBD_PID_AUDIO              0x6128  /**< Product ID: Audio devices */
#define USBD_PID_MSD                0x6129  /**< Product ID: Massstorage */
#define USBD_PID_CDCHID             0x6130  /**< Product ID: composite */
#define USBD_PID_CDCAUDIO           0x6131  /**< Product ID: composite */
#define USBD_PID_CDCMSD             0x6132  /**< Product ID: composite */
#define USBD_PID_CDCCDC             0x6133  /**< Product ID: composite */
#define USBD_PID_HIDAUDIO           0x6134  /**< Product ID: composite */
#define USBD_PID_HIDMSD             0x6135  /**< Product ID: composite */
#define USBD_PID_HIDMOUSE           0x6200  /**< Product ID: HID Mouse */
#define USBD_PID_HIDTRANSFER        0x6201  /**< Product ID: HID Transfer */
#define USBD_PID_CCID               0x6203  /**< Product ID: CCID */
#define USBD_PID_UVC                0x6136  /**< Product ID: UVC  */

#define USBD_RELEASE_1_00           0x0100  /**< Release: 1.00 */
#define USBD_RELEASE_0_01           0x0001  /**< Release: 0.01 */
/**     @}*/

/** \addtogroup usbd_general_config USBD General Configure
 *      @{
 * This page lists general configurations for all USB device drivers.
 * - \ref USBD_BMATTRIBUTES
 */
/** default USB Device attributes configuration descriptor
 *  (bus or self powered, remote wakeup) */
#define USBD_BMATTRIBUTES           BOARD_USB_BMATTRIBUTES
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Mass storage
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_msdd_config USB MassStorage Configure
 *      @{
 * This page lists the defines used by the Mass Storage driver.
 *
 * \section msd_ep_addr Endpoint Addresses
 * - \ref MSDDriverDescriptors_BULKOUT
 * - \ref MSDDriverDescriptors_BULKIN
 */
/** Address of the Mass Storage bulk-out endpoint.*/
#define MSDDriverDescriptors_BULKOUT                2
/** Address of the Mass Storage bulk-in endpoint.*/
#define MSDDriverDescriptors_BULKIN                 3
/**      @}*/

/*----------------------------------------------------------------------------
 *      USB Device - CDC Serial
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_cdc_serial_config USB CDC Serial Configure
 *      @{
 * This page lists the defines used by the CDC Serial Device Driver.
 *
 * \section cdcd_ep_addr Endpoint Addresses
 * - \ref CDCDSerialDriverDescriptors_DATAOUT
 * - \ref CDCDSerialDriverDescriptors_DATAIN
 * - \ref CDCDSerialDriverDescriptors_NOTIFICATION
 */
/** Data OUT endpoint number */
#define CDCDSerialDriverDescriptors_DATAOUT             2
/** Data IN endpoint number */
#define CDCDSerialDriverDescriptors_DATAIN              3
/** Notification endpoint number */
#define CDCDSerialDriverDescriptors_NOTIFICATION        4
/**      @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Audio
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_audio_config USB Audio General Configure
 *      @{
 * This page lists definitions for USB Audio Devices Drivers.
 * - \ref
 */

/** Sample rate in Hz. */
#define AUDDevice_SAMPLERATE        48000UL
/** Number of channels in audio stream. */
#define AUDDevice_NUMCHANNELS       2
/** Number of bytes in one sample. */
#define AUDDevice_BYTESPERSAMPLE    2

/** Number of bits in one sample. */
#define AUDDevice_BITSPERSAMPLE     (AUDDevice_BYTESPERSAMPLE * 8)
/** Number of bytes in one USB subframe. */
#define AUDDevice_BYTESPERSUBFRAME  (AUDDevice_NUMCHANNELS * \
                                     AUDDevice_BYTESPERSAMPLE)
/** Number of samples in one USB frame. */
#define AUDDevice_SAMPLESPERFRAME   (AUDDevice_SAMPLERATE / 1000 \
                                     * AUDDevice_NUMCHANNELS)
/** Number of bytes in one USB frame. */
#define AUDDevice_BYTESPERFRAME     (AUDDevice_SAMPLESPERFRAME * \
                                     AUDDevice_BYTESPERSAMPLE)
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Audio - Desktop Speaker
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_audio_speaker_config USB Speaker Configure
 *      @{
 * This page lists the definitions for USB Audio Speaker Device Driver.
 * - \ref AUDDSpeakerDriverDescriptors_DATAOUT
 * - \ref AUDDSpeakerDriverDescriptors_FS_INTERVAL
 * - \ref AUDDSpeakerDriverDescriptors_HS_INTERVAL
 *
 * \note for UDP, uses IN EPs that support double buffer; for UDPHS, uses
 *       IN EPs that support DMA and High bandwidth.
 */
/** Data out endpoint number. */
#define AUDDSpeakerDriverDescriptors_DATAOUT            0x02
/** Endpoint polling interval 2^(x-1) * 125us */
#define AUDDSpeakerDriverDescriptors_HS_INTERVAL        0x04
/** Endpoint polling interval 2^(x-1) * ms */
#define AUDDSpeakerDriverDescriptors_FS_INTERVAL        0x01
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Audio - Speaker Phone
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_audio_speakerphone_config USB Speaker Phone Configure
 *      @{
 * This page lists the definitions for USB Audio Speaker Phone Device Driver.
 * - \ref AUDDSpeakerPhoneDriverDescriptors_DATAOUT
 * - \ref AUDDSpeakerPhoneDriverDescriptors_DATAIN
 * - \ref AUDDSpeakerPhoneDriverDescriptors_HS_INTERVAL
 * - \ref AUDDSpeakerPhoneDriverDescriptors_FS_INTERVAL
 */


/** Data out endpoint number, size 192B */
#define AUDDSpeakerPhoneDriverDescriptors_DATAOUT        0x02
/** Data in endpoint number, size 192B */
#define AUDDSpeakerPhoneDriverDescriptors_DATAIN         0x01

/** Endpoint polling interval 2^(x-1) * 125us */
#define AUDDSpeakerPhoneDriverDescriptors_HS_INTERVAL        0x04
/** Endpoint polling interval 2^(x-1) * ms */
#define AUDDSpeakerPhoneDriverDescriptors_FS_INTERVAL        0x01
/**      @}*/

/*----------------------------------------------------------------------------
 *      USB Device - HID - Keyboard
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_hid_keyboard_config USB HID Keyboard Device Configure
 *      @{
 * This page lists the defines used by the HID Keyboard Device Driver.
 *
 * \section hidd_k_ep_addr Endpoint Addresses
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTIN
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTOUT
 * \section hidd_k_ep_polling Endpoint Polling Rate
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTIN_POLLING
 * - \ref HIDDKeyboardDriverDescriptors_INTERRUPTOUT_POLLING
 */
/** Interrupt IN endpoint number */
#define HIDDKeyboardDriverDescriptors_INTERRUPTIN           2
/** Interrupt IN endpoint polling rate (in milliseconds) */
#define HIDDKeyboardDriverDescriptors_INTERRUPTIN_POLLING   10
/** Interrupt OUT endpoint number */
#define HIDDKeyboardDriverDescriptors_INTERRUPTOUT          3
/** Interrupt OUT endpoint polling rate (in milliseconds) */
#define HIDDKeyboardDriverDescriptors_INTERRUPTOUT_POLLING  10
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - HID  - Mouse
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_hid_mouse_config USB HID Mouse Device Configure
 *      @{
 * This page lists the defines used by the HID Mouse Device Driver.
 *
 * \section hidd_m_ep_addr Endpoint Addresses
 * - \ref HIDDMouseDriverDescriptors_INTERRUPTIN
 * \section hidd_m_ep_polling Endpoint Polling Rate
 * - \ref HIDDMouseDriverDescriptors_INTERRUPTIN_POLLING
 */
/** Interrupt IN endpoint number */
#define HIDDMouseDriverDescriptors_INTERRUPTIN           2
/** Interrupt IN endpoint polling rate (in milliseconds) */
#define HIDDMouseDriverDescriptors_INTERRUPTIN_POLLING   8
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - HID  - Transfer (Customize device)
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_hid_xfr_config USB HID Transfer Device Configure
 *      @{
 * This page lists the defines used by the HID Transfer Device Driver.
 *
 * \section hidd_t_ep_addr Endpoint Addresses
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTIN
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTOUT
 * \section hidd_t_ep_polling Endpoint Polling Rate
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTIN_POLLING
 * - \ref HIDDTransferDriverDescriptors_INTERRUPTOUT_POLLING
 */
/** Interrupt IN endpoint number. */
#define HIDDTransferDriverDescriptors_INTERRUPTIN           2
/** Polling rate in ms */
#define HIDDTransferDriverDescriptors_INTERRUPTIN_POLLING   50
/** Interrupt IN endpoint polling rate (in milliseconds). */
#define HIDDTransferDriverDescriptors_INTERRUPTOUT          3
/** Polling rate in ms */
#define HIDDTransferDriverDescriptors_INTERRUPTOUT_POLLING  50
/**     @}*/

/*----------------------------------------------------------------------------
 *      USB Device - Composite
 *----------------------------------------------------------------------------*/

/** \addtogroup usbd_composite_config USB Composite Device Configure
 *  @{
 */

/*----------------------------------------------------------------------------
 *      USB Device - HID_AUD
 *----------------------------------------------------------------------------*/

/** Address of the HID interrupt IN endpoint. */
#define HIDAUDD_Descriptors_INTERRUPTIN                0x03
/** Address of the HID interrupt OUT endpoint. */
#define HIDAUDD_Descriptors_INTERRUPTOUT               0x04

/** Audio data out endpoint number */
#define HIDAUDD_Descriptors_ISO_DATAOUT                0x02


/*----------------------------------------------------------------------------
 *      USB Device - CDC AUD
 *----------------------------------------------------------------------------*/

/** Address of the CDC interrupt-in endpoint. */
#define CDCAUDD_Descriptors_NOTIFICATION0              0x04
/** Address of the CDC bulk-in endpoint. */
#define CDCAUDD_Descriptors_DATAIN0                    0x03
/** Address of the CDC bulk-out endpoint. */
#define CDCAUDD_Descriptors_DATAOUT0                   0x02
/** Address of the Audio ISO-out endpoint. */
#define CDCAUDD_Descriptors_ISO_DATAOUT                0x01


/*----------------------------------------------------------------------------
 *      USB Device - DUAL CDC
 *----------------------------------------------------------------------------*/

/// Address of the CDC0 interrupt-in endpoint.
#define CDCD_Descriptors_NOTIFICATION0              3
/// Address of the CDC0 bulk-in endpoint.
#define CDCD_Descriptors_DATAIN0                    2
/// Address of the CDC0 bulk-out endpoint.
#define CDCD_Descriptors_DATAOUT0                   1

/// Address of the CDC1 interrupt-in endpoint.
#define CDCD_Descriptors_NOTIFICATION1              6
/// Address of the CDC1 bulk-in endpoint.
#define CDCD_Descriptors_DATAIN1                    5
/// Address of the CDC1 bulk-out endpoint.
#define CDCD_Descriptors_DATAOUT1                   4


/*----------------------------------------------------------------------------
 *      USB Device - HID CDC
 *----------------------------------------------------------------------------*/


/** Address of the CDC interrupt-in endpoint. */
#define CDCD_Descriptors_NOTIFICATION0              3
/** Address of the CDC bulk-in endpoint. */
#define CDCD_Descriptors_DATAIN0                    2
/** Address of the CDC bulk-out endpoint. */
#define CDCD_Descriptors_DATAOUT0                   1

/** Address of the HID interrupt IN endpoint. */
#define HIDD_Descriptors_INTERRUPTIN                4
/** Address of the HID interrupt OUT endpoint. */
#define HIDD_Descriptors_INTERRUPTOUT               5



/*----------------------------------------------------------------------------
 *      USB Device - HID MSD
 *----------------------------------------------------------------------------*/

/** Address of the Mass Storage bulk-out endpoint. */
#define HIDMSDD_Descriptors_BULKOUT                    2
/** Address of the Mass Storage bulk-in endpoint. */
#define HIDMSDD_Descriptors_BULKIN                     3

/** Address of the HID interrupt IN endpoint. */
#define HIDMSDD_Descriptors_INTERRUPTIN                4
/** Address of the HID interrupt OUT endpoint. */
#define HIDMSDD_Descriptors_INTERRUPTOUT               5

/*----------------------------------------------------------------------------
 *      USB Device - MSD CDC
 *----------------------------------------------------------------------------*/

/** Address of the CDC interrupt-in endpoint. */
#define CDCD_Descriptors_NOTIFICATION0              3
/** Address of the CDC bulk-in endpoint. */
#define CDCD_Descriptors_DATAIN0                    2
/** Address of the CDC bulk-out endpoint. */
#define CDCD_Descriptors_DATAOUT0                   1
/** Address of the Mass Storage bulk-out endpoint. */
#define MSDD_Descriptors_BULKOUT                    4
/** Address of the Mass Storage bulk-in endpoint. */
#define MSDD_Descriptors_BULKIN                     5

/** @}*/

/**@}*/
#endif //#ifndef USBD_CONFIG_H


>>>>>>> 16c66438 (Upload from PC.)
