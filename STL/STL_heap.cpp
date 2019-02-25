        vector<int> ivec = { 1,5,8,2,9,23,56,935 };
	PrintVec(ivec);

	//将范围内的元素调整成最大堆
	make_heap(ivec.begin(), ivec.end());
	PrintVec(ivec);

	//将堆顶元素与最后一个元素互换后,并对上面的堆重新调整
	pop_heap(ivec.begin(), ivec.end());
	cout << "The largest element is " << ivec.back() << endl;	//此时最后一个元素是最大的
	ivec.pop_back();
	PrintVec(ivec);

	//对刚插入堆尾的元素进行堆排序
	ivec.push_back(15);
	push_heap(ivec.begin(), ivec.end());
	PrintVec(ivec);
		

	//将一个堆进行排序, 所以使用sort_heap之前必须先make_heap
	sort_heap(ivec.begin(), ivec.end());
	PrintVec(ivec);
