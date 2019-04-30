clear
clc

cityName = ["上海虹桥" "昆山南" "苏州园区" "无锡" "常州" "丹阳" "镇江" "南京南" "全椒" "肥东" "合肥" "六安" "金寨" "麻城北" "武昌"];

Row = 15;   Col = 15;

sumSP = zeros(Row-1);

%% 意愿出行人数矩阵 - P
% P = [
% 0	0	0	0	0	0	0	0	0	0	0	0	0	0	0;
% 48	0	0	0	0	0	0	0	0	0	0	0	0	0	0;
% 83	14	0	0	0	0	0	0	0	0	0	0	0	0	0;
% 80	7	16	0	0	0	0	0	0	0	0	0	0	0	0;
% 51	6	9	19	0	0	0	0	0	0	0	0	0	0	0;
% 22	3	5	6	6	0	0	0	0	0	0	0	0	0	0;
% 44	4	3	10	9	5	0	0	0	0	0	0	0	0	0;
% 26	4	14	23	18	8	12	0	0	0	0	0	0	0	0;
% 3	1	1	1	1	1	0	6	0	0	0	0	0	0	0;
% 2	1	0	1	1	0	1	1	1	0	0	0	0	0	0;
% 75	8	4	14	10	3	4	35	5	0	0	0	0	0	0;
% 29	2	2	4	2	1	1	4	1	0	26	0	0	0	0;
% 2	1	0	2	1	0	1	2	0	0	4	2	0	0	0;
% 5	5	1	2	2	1	1	2	0	0	7	2	1	0	0;
% 127	31	14	51	35	13	26	106	6	2	133	35	4	69	0;];
%% 票额矩阵 - C
% C = [
% 0	0	0	0	0	0	0	0	0	0	0	0	0	0	0;
% 47	0	0	0	0	0	0	0	0	0	0	0	0	0	0;
% 82	14	0	0	0	0	0	0	0	0	0	0	0	0	0;
% 79	7	16	0	0	0	0	0	0	0	0	0	0	0	0;
% 50	6	9	19	0	0	0	0	0	0	0	0	0	0	0;
% 22	3	5	6	6	0	0	0	0	0	0	0	0	0	0;
% 43	4	3	10	9	5	0	0	0	0	0	0	0	0	0;
% 26	4	14	23	18	8	12	0	0	0	0	0	0	0	0;
% 3	1	1	1	1	1	0	6	0	0	0	0	0	0	0;
% 2	1	0	1	1	0	1	1	1	0	0	0	0	0	0;
% 74	8	4	14	10	3	4	35	5	0	0	0	0	0	0;
% 29	2	2	4	2	1	1	4	1	0	26	0	0	0	0;
% 2	1	0	2	1	0	1	2	0	0	4	2	0	0	0;
% 5	5	1	2	2	1	1	2	0	0	7	2	1	0	0;
% 125	31	14	50	35	13	26	105	6	2	131	35	4	68	0;];
%% 成功出行人数矩阵 - SP
SP = zeros(Row, Col);
%% 随机数- P - C
P = zeros(Row, Col);
C = zeros(Row,Col);
MaxSize = 100
for xi=1:Row
    for xj = 1:Row
        if xi > xj
            P(xi,xj)=randi(MaxSize,1);
            C(xi,xj)=randi(MaxSize,1);
        end
    end 
end
fprintf("初始的P C矩阵")
P
C
saveP=P;
saveC=C;

%% 模拟所有直达的人
fprintf("模拟所有直达\n")
for xj = 1:1:Row
    for xi = Row:-1:xj+1
        if xi > xj
            t = min(P(xi,xj), C(xi,xj));
            SP(xi,xj) = SP(xi,xj) + t;
            P(xi,xj) = P(xi,xj) - t;
            C(xi,xj) = C(xi,xj) - t;
        end
    end
end

sumSP(1)=sum(SP(:));
P=saveP;C=saveC;
SP = zeros(Row, Col);

%% 最多只能分两段
fprintf("最多只能分两段\n")
for xj = 1:1:Row
    for xi = Row:-1:xj+1
        if xi > xj
            
            [flag,C,P,SP] = Way(xj,xi,C,P,SP,xj,xi);

            if flag == 0
                for xk = xj+1:1:xi-1                    
                    if Way(xk,xi,C,P,SP,xj,xi) & Way(xj,xk,C,P,SP,xj,xi)
                        [flag,C,P,SP] = Way(xk,xi,C,P,SP,xj,xi);
                        [flag,C,P,SP] = Way(xj,xk,C,P,SP,xj,xi);
                    end
                end
            end
            
        end
    end
end

sumSP(2)=sum(SP(:));
P=saveP;C=saveC;
SP = zeros(Row, Col);


%% plot
x=1:Row-1;
plot(x,sumSP)
