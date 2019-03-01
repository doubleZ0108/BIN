	vector<int> ivec(3);
	for_each(ivec.begin(), ivec.end(), [](int &i) {i = 6; });
	for_each(ivec.begin(), ivec.end(), [](int i) {cout << i << ' '; });
  
  vector<bool> bvec(3);
	for_each(bvec.begin(), bvec.end(), [](bool &flag) {flag = true; });
	for_each(bvec.begin(), bvec.end(), [](bool flag) {cout << flag << ' '; });
	cout << endl;
  
  //参数为int类型,在lambda中传递参数引用没毛病
  //但是如果类型为bool, 会报错
  //错误	C2664	“void main::<lambda_ef5d749e5e64123486b6af46813b3135>::operator ()(bool &) const”: 无法将参数 1 从“std::_Vb_reference<std::_Wrap_alloc<std::allocator<std::_Vbase>>>”转换为“bool &”	EverydayCode	f:\visual studio\vc\tools\msvc\14.13.26128\include\algorithm	119	
  //不知道什么原因
