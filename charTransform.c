char chn[3];	//第三个存储'\0'
scanf("%s", chn);	//这里输入一个汉字

printf("%d %d\n", chn[0] & 0xFF, chn[1] & 0xFF);	//输出对应的数字,与0xff做且运算是为了保证输出正数

printf("%s", chn);	//输出该字符
