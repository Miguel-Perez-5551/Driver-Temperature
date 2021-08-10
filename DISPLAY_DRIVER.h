/*
 * DISPLAY_DRIVER.h
 *
 *  Created on: 22 jun. 2021
 *      Author: danov
 */

#ifndef DISPLAY_DRIVER_H_
#define DISPLAY_DRIVER_H_

extern void DPY_vfnDriverInit(void);
extern void DPY_bfnWriteMsg(uint8_t *bpMsgSrc, uint8_t bMsgSize);
extern void Delay(long n);

#endif /* DISPLAY_DRIVER_H_ */
