
#ifndef __LCD_1602_H__
#define __LCD_1602_H__
#include <reg52.h>
#include <stdio.h>
#include <INTRINS.H>
#include "datatype.h"  //数据类型自定义

#define LCD_DATA P0 //LCD1602数据端口
void LCD_write_char(INT8U cd,INT8U ab);
void LCD_set_xy( INT8U x, INT8U y );
void LCD_byte(INT8U abc);				  

//写入数值，X Y为坐标，F为数值
LCD_value(INT8U x,INT8U y,FP32 f);

//写入字符，X Y为坐标，*s是字符串首地址
void LCD_write_str(INT8U X,INT8U Y,INT8U *s);
LCD_value0(INT8U x,INT8U y,FP32 f);
void Init_Lcd(); //LCD 初始化;

#endif