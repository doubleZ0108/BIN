function [flag,newC,newP,newSP] = Way(source, dest, C, P, SP, solveS, solveD)
% 模拟从source城市到dest城市三个矩阵的变化情况
t = min([C(dest,source),P(solveD,solveS)]);

if t == 0
    flag = -1;
    newC = C;
    newP = P;
    newSP = SP;
    return;
end

SP(solveD,solveS) = SP(solveD,solveS) + t;
P(solveD,solveS) = P(solveD,solveS) - t;
C(dest,source) = C(dest,source) - t;

if P(solveD,solveS)>0
    flag = 0;
else
    flag = 1;
end
newC = C;
newP = P;
newSP = SP;
end
