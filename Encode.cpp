#include"HuffTree.cpp"
//#include"FileIO.h"
extern HuffTree<byte>* tree;//哈夫曼树
extern std::map<byte, std::string>codeMap;//存储哈夫曼编码表的字典

//利用存储字符数的字典建立哈夫曼树
void numberMapToTree(std::map<byte, int>numberMap)
{
	const int mapSize = numberMap.size();//次数字典中的键值对个数
	HuffTree<byte>** NodeArray = (HuffTree<byte>**)malloc(sizeof(HuffTree<byte>*) * mapSize);//定义存储哈夫曼子树的数组
	int i = 0;
	for (auto iter = numberMap.begin(); iter != numberMap.end() && i < mapSize; ++iter, ++i)//创建哈夫曼树的子树
	{
		NodeArray[i] = new HuffTree<byte>(iter->first, iter->second);
	}
	tree = buildHuff(NodeArray, mapSize);//建立哈夫曼树
	string str0 = "";//测试哈夫曼树
	traverse(tree->root(), str0);
}
