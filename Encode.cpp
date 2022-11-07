#include"HuffTree.cpp"
//#include"FileIO.h"
extern HuffTree<byte>* tree;//��������
extern std::map<byte, std::string>codeMap;//�洢�������������ֵ�

//���ô洢�ַ������ֵ佨����������
void numberMapToTree(std::map<byte, int>numberMap)
{
	const int mapSize = numberMap.size();//�����ֵ��еļ�ֵ�Ը���
	HuffTree<byte>** NodeArray = (HuffTree<byte>**)malloc(sizeof(HuffTree<byte>*) * mapSize);//����洢����������������
	int i = 0;
	for (auto iter = numberMap.begin(); iter != numberMap.end() && i < mapSize; ++iter, ++i)//������������������
	{
		NodeArray[i] = new HuffTree<byte>(iter->first, iter->second);
	}
	tree = buildHuff(NodeArray, mapSize);//������������
	string str0 = "";//���Թ�������
	traverse(tree->root(), str0);
}
