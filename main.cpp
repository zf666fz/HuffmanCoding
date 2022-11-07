#include"main.h"
using namespace std;

//void ReadOneBit(byte* pBuffer, int nStart, /* out */int& nEnd, /* out */ byte& retByte)
//{
//    byte btData = pBuffer[nStart / 8];
//    btData = btData << nStart % 8;
//    retByte = btData >> 7;
//    nEnd = nStart + 1;
//}
//
//void WriteOneBit(byte* pBuffer, byte btData, int nStart,  /* out */int& nEnd)
//{
//    int nSet = nStart / 8;
//    byte c = pBuffer[nSet];
//    switch (btData)
//    {
//    case 1:
//        c |= (1 << (7 - nStart % 8));
//        break;
//    case 0:
//        c &= (~(1 << (7 - nStart % 8)));
//        break;
//    default:
//        return;
//    }
//    pBuffer[nSet] = c;
//    nEnd = nStart + 1;
//}
//
//template<typename T>
//void  WriteDataToBuffer(byte* pBuffer, T tData, int nStart, byte btLength, /* out */int& nEnd)
//{
//    /* //大端机模式
//        byte btDataLength = sizeof(T);
//        if ( btLength > sizeof(T)*8 )
//            return;
//
//        int nDataStart = 0; //数据的第一位位置为0，顺序写入
//        while ( btLength-- )
//        {
//            byte bitData;
//            ReadOneBit((byte*)&tData, nDataStart, nDataStart, bitData);
//            WriteOneBit(pBuffer, bitData, nStart, nStart);
//        }
//
//        nEnd = nStart;
//    */
//
//    //小端机模式：写buffer的时候，不能顺序写位  
//
//    //获得模版占用字节大小  
//    byte btDataLength = sizeof(T);
//
//    //校验长度是否越界  
//    if (btLength > sizeof(T) * 8)
//        return;
//
//    //将待写数据转为byte*  
//    byte* ptData = (byte*)&tData;
//
//    //求模与余  
//    int nSet = btLength / 8;
//    int nRin = btLength % 8;
//
//    //定义字节数据与位数据  
//    byte bitData;
//    byte byteData;
//    int nTempEnd;
//
//    //先写rin数据  
//    byteData = ptData[nSet];
//    while (nRin--)
//    {
//        ReadOneBit(&byteData, 7 - nRin, nTempEnd, bitData);
//        WriteOneBit(pBuffer, bitData, nStart, nStart);
//    }
//
//    //再写Set数据  
//    while (nSet)
//    {
//        byteData = ptData[--nSet];
//        //写一个byte  
//        int i = 0;
//        while (i != 8)
//        {
//            ReadOneBit(&byteData, i++, nTempEnd, bitData);
//            WriteOneBit(pBuffer, bitData, nStart, nStart);
//        }
//    }
//    nEnd = nStart;
//
//}

HuffTree<byte>* tree;//哈夫曼树
std::map<byte, int>numberMap;//存储输入文件中个字符数的字典
std::map<byte, std::string>codeMap;//存储哈夫曼编码表的字典
string in_file_name;//输入文件的名字

int main()
{
	fileByteNumber();//读文件并将文件各字符数存储在次数字典中
	numberMapToTree(numberMap);//利用存储字符数的字典建立哈夫曼树
	treeTocodeMap(tree->root());//将哈夫曼树中的叶节点存入编码字典中
	for (auto iter = codeMap.begin(); iter != codeMap.end(); ++iter)//测试打印codeMap中的键值对
	{
		cout << iter->first << " " << iter->second << endl;
	}
	
	return 0;
}