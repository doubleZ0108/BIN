vector<int> vec1 = {...};
vector<int> vec2 = {...};// vec1和vec2都存有内容
 
vector<int> vec3;//vec3是空的
vec3.insert(vec3.end(),vec1.begin(),vec1.end())//将vec1压入
vec3.insert(vec3.end(),vec2.begin(),vec2.end())//继续将vec2压入

//调用之后vec3中顺序储存vec1和vec2的内容
//相当于两个string的+运算
