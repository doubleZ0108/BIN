/*对一个汉字的处理*/
char chn[3];	//第三个存储'\0'
scanf("%s", chn);	//这里输入一个汉字

printf("%d %d\n", chn[0] & 0xFF, chn[1] & 0xFF);	//输出对应的数字,与0xff做且运算是为了保证输出正数

printf("%s", chn);	//输出该字符



/*读入一行汉字, 逐个输出每个汉字的两位ASCII码*/
char str[MaxSize][3] = { 0 };
for (int i = 0; i < MaxSize; ++i)
{
	scanf("%2s", str[i]);
	printf("%d %d ", str[i][0] & 0xFF, str[i][1] & 0xFF);
	printf("%s\n", str[i]);
}
