// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"


int main()
{	
	int wei=8;
	int i=32;
	int k;
	int o,q,flag,p=0;
	char c=0;
	int ar[8] = {};
	for (k = 0;k <8;k++) {
		o = i & 0x01;
		i = i >> 1;
		printf("o=%d\n", o);
		ar[7-k] = o;				//将二进制数放入数组ar
	}
	for (k = 0;k < 8;k++) {
		printf("ar[k]=%d\n", ar[k]);
		if (ar[k] == 0) {
			if (flag == 1) {
				c = c << 1;
				}
		}
		if (ar[k] == 1) {
			c = (c << 1) + 1;
			flag = 1;
		}
		printf("c=%d\n", c);
	}
	printf("c=%d", c);
	


	

    return 0;
}

