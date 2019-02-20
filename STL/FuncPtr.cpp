/*函数原型*/
bool myless1(const Student stud1, const Student stud2)
{
	return (stud1.num < stud2.num);
}

/*函数指针数组*/
bool(*FuncPtr[3])(const Student, const Student) = { myless1,myless2,myless3 };
vector<bool(*)(const Student, const Student)> FuncPtr(N);

/*使用*/
FuncPtr[i](参数一,参数二);
sort(studVec.begin(), studVec.end(), FuncPtr[i]);
