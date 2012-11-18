/*
 * (C) Copyright 2003
 * David M�ller ELSOFT AG Switzerland. d.mueller@elsoft.ch
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/************************************************
 * NAME	    : s3c24x0.h
 * Version  : 31.3.2003
 *
 * common stuff for SAMSUNG S3C24X0 SoC
 ************************************************/

#ifndef __S3C24X0_H__
#define __S3C24X0_H__

typedef volatile u8	S3C24X0_REG8;
typedef volatile u16	S3C24X0_REG16;
typedef volatile u32	S3C24X0_REG32;

/* Memory controller (see manual chapter 5) */
struct s3c24x0_memctl {
	S3C24X0_REG32	BWSCON;
	S3C24X0_REG32	BANKCON[8];
	S3C24X0_REG32	REFRESH;
	S3C24X0_REG32	BANKSIZE;
	S3C24X0_REG32	MRSRB6;
	S3C24X0_REG32	MRSRB7;
};


/* USB HOST (see manual chapter 12) */
struct s3c24x0_usb_host {
	S3C24X0_REG32	HcRevision;
	S3C24X0_REG32	HcControl;
	S3C24X0_REG32	HcCommonStatus;
	S3C24X0_REG32	HcInterruptStatus;
	S3C24X0_REG32	HcInterruptEnable;
	S3C24X0_REG32	HcInterruptDisable;
	S3C24X0_REG32	HcHCCA;
	S3C24X0_REG32	HcPeriodCuttendED;
	S3C24X0_REG32	HcControlHeadED;
	S3C24X0_REG32	HcControlCurrentED;
	S3C24X0_REG32	HcBulkHeadED;
	S3C24X0_REG32	HcBuldCurrentED;
	S3C24X0_REG32	HcDoneHead;
	S3C24X0_REG32	HcRmInterval;
	S3C24X0_REG32	HcFmRemaining;
	S3C24X0_REG32	HcFmNumber;
	S3C24X0_REG32	HcPeriodicStart;
	S3C24X0_REG32	HcLSThreshold;
	S3C24X0_REG32	HcRhDescriptorA;
	S3C24X0_REG32	HcRhDescriptorB;
	S3C24X0_REG32	HcRhStatus;
	S3C24X0_REG32	HcRhPortStatus1;
	S3C24X0_REG32	HcRhPortStatus2;
};


/* INTERRUPT (see manual chapter 14) */
struct s3c24x0_interrupt {
	S3C24X0_REG32	SRCPND;
	S3C24X0_REG32	INTMOD;
	S3C24X0_REG32	INTMSK;
	S3C24X0_REG32	PRIORITY;
	S3C24X0_REG32	INTPND;
	S3C24X0_REG32	INTOFFSET;
#ifdef CONFIG_S3C2410
	S3C24X0_REG32	SUBSRCPND;
	S3C24X0_REG32	INTSUBMSK;
#endif
};


/* DMAS (see manual chapter 8) */
struct s3c24x0_dma {
	S3C24X0_REG32	DISRC;
#ifdef CONFIG_S3C2410
	S3C24X0_REG32	DISRCC;
#endif
	S3C24X0_REG32	DIDST;
#ifdef CONFIG_S3C2410
	S3C24X0_REG32	DIDSTC;
#endif
	S3C24X0_REG32	DCON;
	S3C24X0_REG32	DSTAT;
	S3C24X0_REG32	DCSRC;
	S3C24X0_REG32	DCDST;
	S3C24X0_REG32	DMASKTRIG;
#ifdef CONFIG_S3C2400
	S3C24X0_REG32	res[1];
#endif
#ifdef CONFIG_S3C2410
	S3C24X0_REG32	res[7];
#endif
};

struct s3c24x0_dmas {
	struct s3c24x0_dma	dma[4];
};


/* CLOCK & POWER MANAGEMENT (see S3C2400 manual chapter 6) */
/*                          (see S3C2410 manual chapter 7) */
struct s3c24x0_clock_power {
	S3C24X0_REG32	LOCKTIME;
	S3C24X0_REG32	MPLLCON;
	S3C24X0_REG32	UPLLCON;
	S3C24X0_REG32	CLKCON;
	S3C24X0_REG32	CLKSLOW;
	S3C24X0_REG32	CLKDIVN;
};


/* LCD CONTROLLER (see manual chapter 15) */
struct s3c24x0_lcd {
	S3C24X0_REG32	LCDCON1;
	S3C24X0_REG32	LCDCON2;
	S3C24X0_REG32	LCDCON3;
	S3C24X0_REG32	LCDCON4;
	S3C24X0_REG32	LCDCON5;
	S3C24X0_REG32	LCDSADDR1;
	S3C24X0_REG32	LCDSADDR2;
	S3C24X0_REG32	LCDSADDR3;
	S3C24X0_REG32	REDLUT;
	S3C24X0_REG32	GREENLUT;
	S3C24X0_REG32	BLUELUT;
	S3C24X0_REG32	res[8];
	S3C24X0_REG32	DITHMODE;
	S3C24X0_REG32	TPAL;
#ifdef CONFIG_S3C2410
	S3C24X0_REG32	LCDINTPND;
	S3C24X0_REG32	LCDSRCPND;
	S3C24X0_REG32	LCDINTMSK;
	S3C24X0_REG32	LPCSEL;
#endif
};


/* NAND FLASH (see S3C2410 manual chapter 6) */
struct s3c2410_nand {
	S3C24X0_REG32	NFCONF;
	S3C24X0_REG32	NFCMD;
	S3C24X0_REG32	NFADDR;
	S3C24X0_REG32	NFDATA;
	S3C24X0_REG32	NFSTAT;
	S3C24X0_REG32	NFECC;
};


/* UART (see manual chapter 11) */
struct s3c24x0_uart {
	S3C24X0_REG32	ULCON;
	S3C24X0_REG32	UCON;
	S3C24X0_REG32	UFCON;
	S3C24X0_REG32	UMCON;
	S3C24X0_REG32	UTRSTAT;
	S3C24X0_REG32	UERSTAT;
	S3C24X0_REG32	UFSTAT;
	S3C24X0_REG32	UMSTAT;
#ifdef __BIG_ENDIAN
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	UTXH;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	URXH;
#else /* Little Endian */
	S3C24X0_REG8	UTXH;
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	URXH;
	S3C24X0_REG8	res2[3];
#endif
	S3C24X0_REG32	UBRDIV;
};


/* PWM TIMER (see manual chapter 10) */
struct s3c24x0_timer {
	S3C24X0_REG32	TCNTB;
	S3C24X0_REG32	TCMPB;
	S3C24X0_REG32	TCNTO;
};

struct s3c24x0_timers {
	S3C24X0_REG32		TCFG0;
	S3C24X0_REG32		TCFG1;
	S3C24X0_REG32		TCON;
	struct s3c24x0_timer	ch[4];
	S3C24X0_REG32		TCNTB4;
	S3C24X0_REG32		TCNTO4;
};


/* USB DEVICE (see manual chapter 13) */
struct s3c24x0_usb_dev_fifos {
#ifdef __BIG_ENDIAN
	S3C24X0_REG8	res[3];
	S3C24X0_REG8	EP_FIFO_REG;
#else /*  little endian */
	S3C24X0_REG8	EP_FIFO_REG;
	S3C24X0_REG8	res[3];
#endif
};

struct s3c24x0_usb_dev_dmas {
#ifdef __BIG_ENDIAN
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	EP_DMA_CON;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	EP_DMA_UNIT;
	S3C24X0_REG8	res3[3];
	S3C24X0_REG8	EP_DMA_FIFO;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG8	EP_DMA_TTC_L;
	S3C24X0_REG8	res5[3];
	S3C24X0_REG8	EP_DMA_TTC_M;
	S3C24X0_REG8	res6[3];
	S3C24X0_REG8	EP_DMA_TTC_H;
#else /*  little endian */
	S3C24X0_REG8	EP_DMA_CON;
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	EP_DMA_UNIT;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	EP_DMA_FIFO;
	S3C24X0_REG8	res3[3];
	S3C24X0_REG8	EP_DMA_TTC_L;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG8	EP_DMA_TTC_M;
	S3C24X0_REG8	res5[3];
	S3C24X0_REG8	EP_DMA_TTC_H;
	S3C24X0_REG8	res6[3];
#endif
};

struct s3c24x0_usb_device {
#ifdef __BIG_ENDIAN
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	FUNC_ADDR_REG;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	PWR_REG;
	S3C24X0_REG8	res3[3];
	S3C24X0_REG8	EP_INT_REG;
	S3C24X0_REG8	res4[15];
	S3C24X0_REG8	USB_INT_REG;
	S3C24X0_REG8	res5[3];
	S3C24X0_REG8	EP_INT_EN_REG;
	S3C24X0_REG8	res6[15];
	S3C24X0_REG8	USB_INT_EN_REG;
	S3C24X0_REG8	res7[3];
	S3C24X0_REG8	FRAME_NUM1_REG;
	S3C24X0_REG8	res8[3];
	S3C24X0_REG8	FRAME_NUM2_REG;
	S3C24X0_REG8	res9[3];
	S3C24X0_REG8	INDEX_REG;
	S3C24X0_REG8	res10[7];
	S3C24X0_REG8	MAXP_REG;
	S3C24X0_REG8	res11[3];
	S3C24X0_REG8	EP0_CSR_IN_CSR1_REG;
	S3C24X0_REG8	res12[3];
	S3C24X0_REG8	IN_CSR2_REG;
	S3C24X0_REG8	res13[7];
	S3C24X0_REG8	OUT_CSR1_REG;
	S3C24X0_REG8	res14[3];
	S3C24X0_REG8	OUT_CSR2_REG;
	S3C24X0_REG8	res15[3];
	S3C24X0_REG8	OUT_FIFO_CNT1_REG;
	S3C24X0_REG8	res16[3];
	S3C24X0_REG8	OUT_FIFO_CNT2_REG;
#else /*  little endian */
	S3C24X0_REG8	FUNC_ADDR_REG;
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	PWR_REG;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	EP_INT_REG;
	S3C24X0_REG8	res3[15];
	S3C24X0_REG8	USB_INT_REG;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG8	EP_INT_EN_REG;
	S3C24X0_REG8	res5[15];
	S3C24X0_REG8	USB_INT_EN_REG;
	S3C24X0_REG8	res6[3];
	S3C24X0_REG8	FRAME_NUM1_REG;
	S3C24X0_REG8	res7[3];
	S3C24X0_REG8	FRAME_NUM2_REG;
	S3C24X0_REG8	res8[3];
	S3C24X0_REG8	INDEX_REG;
	S3C24X0_REG8	res9[7];
	S3C24X0_REG8	MAXP_REG;
	S3C24X0_REG8	res10[7];
	S3C24X0_REG8	EP0_CSR_IN_CSR1_REG;
	S3C24X0_REG8	res11[3];
	S3C24X0_REG8	IN_CSR2_REG;
	S3C24X0_REG8	res12[3];
	S3C24X0_REG8	OUT_CSR1_REG;
	S3C24X0_REG8	res13[7];
	S3C24X0_REG8	OUT_CSR2_REG;
	S3C24X0_REG8	res14[3];
	S3C24X0_REG8	OUT_FIFO_CNT1_REG;
	S3C24X0_REG8	res15[3];
	S3C24X0_REG8	OUT_FIFO_CNT2_REG;
	S3C24X0_REG8	res16[3];
#endif /*  __BIG_ENDIAN */
	struct s3c24x0_usb_dev_fifos	fifo[5];
	struct s3c24x0_usb_dev_dmas	dma[5];
};


/* WATCH DOG TIMER (see manual chapter 18) */
struct s3c24x0_watchdog {
	S3C24X0_REG32	WTCON;
	S3C24X0_REG32	WTDAT;
	S3C24X0_REG32	WTCNT;
};


/* IIC (see manual chapter 20) */
struct s3c24x0_i2c {
	S3C24X0_REG32	IICCON;
	S3C24X0_REG32	IICSTAT;
	S3C24X0_REG32	IICADD;
	S3C24X0_REG32	IICDS;
};


/* IIS (see manual chapter 21) */
struct s3c24x0_i2s {
#ifdef __BIG_ENDIAN
	S3C24X0_REG16	res1;
	S3C24X0_REG16	IISCON;
	S3C24X0_REG16	res2;
	S3C24X0_REG16	IISMOD;
	S3C24X0_REG16	res3;
	S3C24X0_REG16	IISPSR;
	S3C24X0_REG16	res4;
	S3C24X0_REG16	IISFCON;
	S3C24X0_REG16	res5;
	S3C24X0_REG16	IISFIFO;
#else /*  little endian */
	S3C24X0_REG16	IISCON;
	S3C24X0_REG16	res1;
	S3C24X0_REG16	IISMOD;
	S3C24X0_REG16	res2;
	S3C24X0_REG16	IISPSR;
	S3C24X0_REG16	res3;
	S3C24X0_REG16	IISFCON;
	S3C24X0_REG16	res4;
	S3C24X0_REG16	IISFIFO;
	S3C24X0_REG16	res5;
#endif
};


/* I/O PORT (see manual chapter 9) */
struct s3c24x0_gpio {
#ifdef CONFIG_S3C2400
	S3C24X0_REG32	PACON;
	S3C24X0_REG32	PADAT;

	S3C24X0_REG32	PBCON;
	S3C24X0_REG32	PBDAT;
	S3C24X0_REG32	PBUP;

	S3C24X0_REG32	PCCON;
	S3C24X0_REG32	PCDAT;
	S3C24X0_REG32	PCUP;

	S3C24X0_REG32	PDCON;
	S3C24X0_REG32	PDDAT;
	S3C24X0_REG32	PDUP;

	S3C24X0_REG32	PECON;
	S3C24X0_REG32	PEDAT;
	S3C24X0_REG32	PEUP;

	S3C24X0_REG32	PFCON;
	S3C24X0_REG32	PFDAT;
	S3C24X0_REG32	PFUP;

	S3C24X0_REG32	PGCON;
	S3C24X0_REG32	PGDAT;
	S3C24X0_REG32	PGUP;

	S3C24X0_REG32	OPENCR;

	S3C24X0_REG32	MISCCR;
	S3C24X0_REG32	EXTINT;
#endif
#if defined(CONFIG_S3C2410) || defined(CONFIG_S3C2440)
	S3C24X0_REG32	GPACON;
	S3C24X0_REG32	GPADAT;
	S3C24X0_REG32	res1[2];
	S3C24X0_REG32	GPBCON;
	S3C24X0_REG32	GPBDAT;
	S3C24X0_REG32	GPBUP;
	S3C24X0_REG32	res2;
	S3C24X0_REG32	GPCCON;
	S3C24X0_REG32	GPCDAT;
	S3C24X0_REG32	GPCUP;
	S3C24X0_REG32	res3;
	S3C24X0_REG32	GPDCON;
	S3C24X0_REG32	GPDDAT;
	S3C24X0_REG32	GPDUP;
	S3C24X0_REG32	res4;
	S3C24X0_REG32	GPECON;
	S3C24X0_REG32	GPEDAT;
	S3C24X0_REG32	GPEUP;
	S3C24X0_REG32	res5;
	S3C24X0_REG32	GPFCON;
	S3C24X0_REG32	GPFDAT;
	S3C24X0_REG32	GPFUP;
	S3C24X0_REG32	res6;
	S3C24X0_REG32	GPGCON;
	S3C24X0_REG32	GPGDAT;
	S3C24X0_REG32	GPGUP;
	S3C24X0_REG32	res7;
	S3C24X0_REG32	GPHCON;
	S3C24X0_REG32	GPHDAT;
	S3C24X0_REG32	GPHUP;
	S3C24X0_REG32	res8;

	S3C24X0_REG32	MISCCR;
	S3C24X0_REG32	DCLKCON;
	S3C24X0_REG32	EXTINT0;
	S3C24X0_REG32	EXTINT1;
	S3C24X0_REG32	EXTINT2;
	S3C24X0_REG32	EINTFLT0;
	S3C24X0_REG32	EINTFLT1;
	S3C24X0_REG32	EINTFLT2;
	S3C24X0_REG32	EINTFLT3;
	S3C24X0_REG32	EINTMASK;
	S3C24X0_REG32	EINTPEND;
	S3C24X0_REG32	GSTATUS0;
	S3C24X0_REG32	GSTATUS1;
	S3C24X0_REG32	GSTATUS2;
	S3C24X0_REG32	GSTATUS3;
	S3C24X0_REG32	GSTATUS4;
#if defined(CONFIG_S3C2440)
	S3C24X0_REG32	res9[3];
	S3C24X0_REG32 	MSLCON;
	S3C24X0_REG32	GPJCON;
	S3C24X0_REG32	GPJDAT;
	S3C24X0_REG32	GPJUP;
#endif
#endif
};


/* RTC (see manual chapter 17) */
struct s3c24x0_rtc {
#ifdef __BIG_ENDIAN
	S3C24X0_REG8	res1[67];
	S3C24X0_REG8	RTCCON;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	TICNT;
	S3C24X0_REG8	res3[11];
	S3C24X0_REG8	RTCALM;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG8	ALMSEC;
	S3C24X0_REG8	res5[3];
	S3C24X0_REG8	ALMMIN;
	S3C24X0_REG8	res6[3];
	S3C24X0_REG8	ALMHOUR;
	S3C24X0_REG8	res7[3];
	S3C24X0_REG8	ALMDATE;
	S3C24X0_REG8	res8[3];
	S3C24X0_REG8	ALMMON;
	S3C24X0_REG8	res9[3];
	S3C24X0_REG8	ALMYEAR;
	S3C24X0_REG8	res10[3];
	S3C24X0_REG8	RTCRST;
	S3C24X0_REG8	res11[3];
	S3C24X0_REG8	BCDSEC;
	S3C24X0_REG8	res12[3];
	S3C24X0_REG8	BCDMIN;
	S3C24X0_REG8	res13[3];
	S3C24X0_REG8	BCDHOUR;
	S3C24X0_REG8	res14[3];
	S3C24X0_REG8	BCDDATE;
	S3C24X0_REG8	res15[3];
	S3C24X0_REG8	BCDDAY;
	S3C24X0_REG8	res16[3];
	S3C24X0_REG8	BCDMON;
	S3C24X0_REG8	res17[3];
	S3C24X0_REG8	BCDYEAR;
#else /*  little endian */
	S3C24X0_REG8	res0[64];
	S3C24X0_REG8	RTCCON;
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	TICNT;
	S3C24X0_REG8	res2[11];
	S3C24X0_REG8	RTCALM;
	S3C24X0_REG8	res3[3];
	S3C24X0_REG8	ALMSEC;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG8	ALMMIN;
	S3C24X0_REG8	res5[3];
	S3C24X0_REG8	ALMHOUR;
	S3C24X0_REG8	res6[3];
	S3C24X0_REG8	ALMDATE;
	S3C24X0_REG8	res7[3];
	S3C24X0_REG8	ALMMON;
	S3C24X0_REG8	res8[3];
	S3C24X0_REG8	ALMYEAR;
	S3C24X0_REG8	res9[3];
	S3C24X0_REG8	RTCRST;
	S3C24X0_REG8	res10[3];
	S3C24X0_REG8	BCDSEC;
	S3C24X0_REG8	res11[3];
	S3C24X0_REG8	BCDMIN;
	S3C24X0_REG8	res12[3];
	S3C24X0_REG8	BCDHOUR;
	S3C24X0_REG8	res13[3];
	S3C24X0_REG8	BCDDATE;
	S3C24X0_REG8	res14[3];
	S3C24X0_REG8	BCDDAY;
	S3C24X0_REG8	res15[3];
	S3C24X0_REG8	BCDMON;
	S3C24X0_REG8	res16[3];
	S3C24X0_REG8	BCDYEAR;
	S3C24X0_REG8	res17[3];
#endif
};


/* ADC (see manual chapter 16) */
struct s3c2400_adc {
	S3C24X0_REG32	ADCCON;
	S3C24X0_REG32	ADCDAT;
};


/* ADC (see manual chapter 16) */
struct s3c2410_adc {
	S3C24X0_REG32	ADCCON;
	S3C24X0_REG32	ADCTSC;
	S3C24X0_REG32	ADCDLY;
	S3C24X0_REG32	ADCDAT0;
	S3C24X0_REG32	ADCDAT1;
};


/* SPI (see manual chapter 22) */
struct s3c24x0_spi_channel {
	S3C24X0_REG8	SPCON;
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	SPSTA;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	SPPIN;
	S3C24X0_REG8	res3[3];
	S3C24X0_REG8	SPPRE;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG8	SPTDAT;
	S3C24X0_REG8	res5[3];
	S3C24X0_REG8	SPRDAT;
	S3C24X0_REG8	res6[3];
	S3C24X0_REG8	res7[16];
};

struct s3c24x0_spi {
	struct s3c24x0_spi_channel	ch[S3C24X0_SPI_CHANNELS];
};


/* MMC INTERFACE (see S3C2400 manual chapter 19) */
struct s3c2400_mmc {
#ifdef __BIG_ENDIAN
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	MMCON;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	MMCRR;
	S3C24X0_REG8	res3[3];
	S3C24X0_REG8	MMFCON;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG8	MMSTA;
	S3C24X0_REG16	res5;
	S3C24X0_REG16	MMFSTA;
	S3C24X0_REG8	res6[3];
	S3C24X0_REG8	MMPRE;
	S3C24X0_REG16	res7;
	S3C24X0_REG16	MMLEN;
	S3C24X0_REG8	res8[3];
	S3C24X0_REG8	MMCR7;
	S3C24X0_REG32	MMRSP[4];
	S3C24X0_REG8	res9[3];
	S3C24X0_REG8	MMCMD0;
	S3C24X0_REG32	MMCMD1;
	S3C24X0_REG16	res10;
	S3C24X0_REG16	MMCR16;
	S3C24X0_REG8	res11[3];
	S3C24X0_REG8	MMDAT;
#else
	S3C24X0_REG8	MMCON;
	S3C24X0_REG8	res1[3];
	S3C24X0_REG8	MMCRR;
	S3C24X0_REG8	res2[3];
	S3C24X0_REG8	MMFCON;
	S3C24X0_REG8	res3[3];
	S3C24X0_REG8	MMSTA;
	S3C24X0_REG8	res4[3];
	S3C24X0_REG16	MMFSTA;
	S3C24X0_REG16	res5;
	S3C24X0_REG8	MMPRE;
	S3C24X0_REG8	res6[3];
	S3C24X0_REG16	MMLEN;
	S3C24X0_REG16	res7;
	S3C24X0_REG8	MMCR7;
	S3C24X0_REG8	res8[3];
	S3C24X0_REG32	MMRSP[4];
	S3C24X0_REG8	MMCMD0;
	S3C24X0_REG8	res9[3];
	S3C24X0_REG32	MMCMD1;
	S3C24X0_REG16	MMCR16;
	S3C24X0_REG16	res10;
	S3C24X0_REG8	MMDAT;
	S3C24X0_REG8	res11[3];
#endif
};


/* SD INTERFACE (see S3C2410 manual chapter 19) */
struct s3c2410_sdi {
	S3C24X0_REG32	SDICON;
	S3C24X0_REG32	SDIPRE;
	S3C24X0_REG32	SDICARG;
	S3C24X0_REG32	SDICCON;
	S3C24X0_REG32	SDICSTA;
	S3C24X0_REG32	SDIRSP0;
	S3C24X0_REG32	SDIRSP1;
	S3C24X0_REG32	SDIRSP2;
	S3C24X0_REG32	SDIRSP3;
	S3C24X0_REG32	SDIDTIMER;
	S3C24X0_REG32	SDIBSIZE;
	S3C24X0_REG32	SDIDCON;
	S3C24X0_REG32	SDIDCNT;
	S3C24X0_REG32	SDIDSTA;
	S3C24X0_REG32	SDIFSTA;
#ifdef __BIG_ENDIAN
	S3C24X0_REG8	res[3];
	S3C24X0_REG8	SDIDAT;
#else
	S3C24X0_REG8	SDIDAT;
	S3C24X0_REG8	res[3];
#endif
	S3C24X0_REG32	SDIIMSK;
};

#endif /*__S3C24X0_H__*/
