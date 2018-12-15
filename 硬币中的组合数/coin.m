clc
clear

syms x      %定义符号变量x

%人民币
Yuan1=1/(1-x);
Yuan1=series(Yuan1,x,'Order',1001);     %一分 -> 母函数
Yuan2=1/(1-x^2);
Yuan2=series(Yuan2,x,'Order',1001);     %两分 -> 母函数
Yuan3=1/(1-x^5);
Yuan3=series(Yuan3,x,'Order',1001);     %五分 -> 母函数
Yuan4=1/(1-x^10);
Yuan4=series(Yuan4,x,'Order',1001);     %一角 -> 母函数
Yuan5=1/(1-x^50);
Yuan5=series(Yuan5,x,'Order',1001);     %两角 -> 母函数
Yuan6=1/(1-x^100);
Yuan6=series(Yuan6,x,'Order',1001);     %一元 -> 母函数

Yuan=Yuan1*Yuan2*Yuan3*Yuan4*Yuan5*Yuan6;   %总金额的母函数
Yuan=expand(Yuan);                          %展开多项式
Yuan=coeffs(Yuan);                          %展成标准形式
Yuan=Yuan(2:1001)       %取前1000位
                        %第一位是总金额等于0的时候, 没有讨论的价值,
                       

%美元
Dollar1=1/(1-x);
Dollar1=series(Dollar1,x,'Order',1001);     %一美分 -> 母函数
Dollar2=1/(1-x^5);
Dollar2=series(Dollar2,x,'Order',1001);     %5美分 -> 母函数
Dollar3=1/(1-x^10);
Dollar3=series(Dollar3,x,'Order',1001);     %10美分 -> 母函数
Dollar4=1/(1-x^25);
Dollar4=series(Dollar4,x,'Order',1001);     %25美分 -> 母函数
Dollar5=1/(1-x^50);
Dollar5=series(Dollar5,x,'Order',1001);     %50美分 -> 母函数
Dollar6=1/(1-x^100);
Dollar6=series(Dollar6,x,'Order',1001);     %一美元 -> 母函数

Dollar=Dollar1*Dollar2*Dollar3*Dollar4*Dollar5*Dollar6;
expand(Dollar);
Dollar=coeffs(Dollar);
Dollar=Dollar(2:1001)


%欧元
Euro1=1/(1-x);
Euro1=series(Euro1,x,'Order',1001);     %1欧分 -> 母函数
Euro2=1/(1-x^2);
Euro2=series(Euro2,x,'Order',1001);     %2欧分 -> 母函数
Euro3=1/(1-x^5);
Euro3=series(Euro3,x,'Order',1001);     %5欧分 -> 母函数
Euro4=1/(1-x^10);
Euro4=series(Euro4,x,'Order',1001);     %10欧分 -> 母函数
Euro5=1/(1-x^20);
Euro5=series(Euro5,x,'Order',1001);     %20欧分 -> 母函数
Euro6=1/(1-x^50);
Euro6=series(Euro6,x,'Order',1001);     %50欧分 -> 母函数
Euro7=1/(1-x^100);
Euro7=series(Euro7,x,'Order',1001);     %一欧元 -> 母函数
Euro8=1/(1-x^200);
Euro8=series(Euro8,x,'Order',1001);     %二欧元 -> 母函数

Euro=Euro1*Euro2*Euro3*Euro4*Euro5*Euro6*Euro7*Euro8;
expand(Euro);
Euro=coeffs(Euro);
Euro=Euro(2:1001)

%绘制函数图像
Yuanx=1:1:1000;
plot(Yuanx,Yuan)
hold on;
Dollarx=1:1000;
plot(Dollarx,Dollar)
Eurox=1:1000;
plot(Eurox,Euro)

legend('人民币','美元','欧元');
xlabel('分');
ylabel('组合数');

figure 

%绘制柱状图
Combine=zeros(3,10);
for row=100:100:1000
    Combine(1,row/100)=Yuan(row);
    Combine(2,row/100)=Dollar(row);
    Combine(3,row/100)=Euro(row);
end
Combine=Combine';

bar(Combine)
set(gca,'ygrid','on');      %只显示网格的横线 
set(gca,'xticklabel',{'100','200','300','400','500','600','700','800','900','1000'});
legend('人民币','美元','欧元');
xlabel('分');
ylabel('组合数');
