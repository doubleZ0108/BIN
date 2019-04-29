Y = [2144.73 2486.31 2869.58 3217.76]

X1 = [6012.64 7145.52 8210.57 9011.78];
X2 = [632.42 636.36 638.48 643.09];
X3 = [7366 8181 8950 9674];
X4 = [2288.74 2697.10 3103.82 3504.17];
X5 = [18156 20763 23493 25647];


subplot(2,3,1)
plot(X1,Y,'g*');
hold on
b1=polyfit(X1,Y,1);       %进行1元线性拟合，b是多项式前面的值。就如2次拟合中y=ax+b,a,b的值。
Y1=polyval(b1,X1);        %得到拟合后y的新值
plot(X1,Y1,'r-')          %画拟合图
xlabel('GDP(亿元)');      %标记坐标轴
ylabel('铁路客运量(万人)');
title('GDP(亿元)')

subplot(2,3,2)
plot(X2,Y,'g*');
hold on
b2=polyfit(X2,Y,1);
Y2=polyval(b2,X2); 
plot(X2,Y2,'r-')
xlabel('人口(万人)');
ylabel('铁路客运量(万人)');
title('人口(万人)')

subplot(2,3,3)
plot(X3,Y,'g*');
hold on
b3=polyfit(X3,Y,1);
Y=polyval(b3,X3); 
plot(X3,Y,'r-')
xlabel('旅游人数(万人)');
ylabel('铁路客运量(万人)');
title('旅游人数(万人)')

subplot(2,3,4)
plot(X4,Y,'g*');
hold on
b4=polyfit(X4,Y,1);
Y=polyval(b4,X4); 
plot(X4,Y,'r-')
xlabel('社会消费品零售总额(亿元)');
ylabel('铁路客运量(万人)');
title('社会消费品零售总额(亿元)')

subplot(2,3,5)
plot(X5,Y,'g*');
hold on
b5=polyfit(X5,Y,1);
Y=polyval(b5,X5); 
plot(X5,Y,'r-')
xlabel('人均消费支出(元)');
ylabel('铁路客运量(万人)');
title('人均消费支出(元)')
