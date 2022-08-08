multiset<int> s;     // 初始化   

s.insert(x);    // 插入元素

s.count(x);     // 返回容器中元素x的个数

s.size();       // 返回容器长度

s.erase(s.find(x)); // 删除集合中一个元素x

s.erase(x);     // 删除集合中的所有元素x

s.clear();      // 清空集合中元素

s.empty();      // 判断是否为空

s.begin();      // 返回第一个元素的迭代器

s.end();        // 返回最后一个元素加1的迭代器

s.rbegin();     // 反向迭代器

s.find(x);      // 返回元素x的迭代器，没找到返回s.end()

s.lower_bound(x);   // 返回第一个大于等于x的迭代器，没找到返回s.end()

s.upper_bound(x);   // 返回第一个大于等于x的迭代器，没找到返回s.end()

for (auto x : s) {  // 正向遍历
    cout << x << ' ';   
}

for (auto it = --s.end(); it != --s.begin(); it--) {    // 反向遍历
    cout << *it << ' ';   
}

// 自定义结构体，按关键字y从小到大排序
struct node {
    int x, y;
    bool operator < (const node& a) const {
        return y < a.y;
    }
};

multiset<node> s;
s.insert({2, 1});
s.insert({1, 3});
s.insert({2, 1});
for (auto it : s) {
    cout << it.x << ' ' << it.y << endl;
}
