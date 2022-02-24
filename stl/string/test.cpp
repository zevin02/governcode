#include<iostream>
using namespace std;
#include<cstdio>
//string���ǹ����ַ�������
#include<string>

//�����涨��
template<class T>
class basic_string
{
private:
	T* _str;
	//...
};


//���� --ֵ--���Ž���ӳ���ϵ--���������ֵ�ͷ��Ž�����Ӧ��ϵ�� 
// ASCILL�����---��ʾӢ�ı���
// unicode ---������ascill����ʾȫ�������ֱ���
//�ְ���utf -8��utf-16 
//gbk        --     �й��Լ����������ı����
// ���ֿ�����2���ֽڣ�
// 
//typrdef basic_string<char> string,�����õ���typedef������ģ�ģ���

//int main()
//{
//	string s1("hello");
//	char str2[] = "�Է�";
//	cout << sizeof(char) << endl;
//	cout << sizeof(wchar_t) << endl;//2���ֽڣ�wstring
//
//	return 0;
//}



//��ʼ��

void init()
{
	string s1;//�޵��ù��캯��
	string s2("hello world");//���캯��
	string s3(s2);//��������
	//cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	//substring (3)	

	//string(const string & str, size_t pos, size_t len = npos);
	//�����ִ����г�ʼ����pos�Ǵ�0��ʼ����string�����Ⱥ���len�����Ƚ��п���


	string s4(s2, 2, 6);
	cout << s4 << endl;//llo wo
	string s5(s2, 2);//Ĭ�ϴ�����Ϊ2�ĵط������ȡ���е�s2
	cout << s5 << endl;//ello world

	//string (const char* s, size_t n);
	string s7("hello world", 3);//ȡǰ3���ַ�
	cout << s7 << endl;
	//string(size_t n, char c);����Ūn��c
	string s8(3, '!');//������
}


void func()
{
	string s1("hello");
	//�����㡮\0��������������stringûʲô����size�Ǻ����Ϊ�˱�֤������һ����
	cout << s1.size() << endl;//5
	cout << s1.length() << endl;//5
	cout << s1.max_size() << endl;//ûʲô����
	cout << s1 << endl;
								  //��������
	cout << s1.capacity() << endl;//15
	s1.clear();//����Ч���ݶ�������,�ռ䱣������ɿ��ַ�����0���ַ�
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	if (s1.empty())//�жϴ��ַ����Ƿ�Ϊ�գ����Ƿ񳤶�Ϊ0
	{
		cout << "not" << endl;
	}


}


//char& operator[] (size_t pos);��������÷�������Ϊ����������ڶ��Ͽ��ٵģ������������ڣ����ҿ��Զ����е��ַ������޸ģ����ߵ��ã������Լ��ٿ�����������ҪĿ�ģ�


void operatoracess()
{
	string s1("hello world");
	for (size_t i = 0; i < s1.length(); i++)
	{
		cout << s1[i];//[]�Ƕ�����ֹ���򣬼�����
		s1[i] += 1;
	}
	cout << endl;
	for (size_t i = 0; i < s1.length(); i++)
	{
		s1.at(i) -= 1;//��������һ����
		cout << s1.at(i) << endl;//at�����쳣������,���黹��ʹ��[ ]
	}
	cout << endl;

}

//���ַ�������β�������ַ����ַ���
void add()
{
	string s;
	s.push_back('a');
	s.append("bcde");//β��bcd
	cout << s << endl;//abcd
	s += '!';//Ҳ����������������ؽ���ʵ��β�壬�Ƽ�,abcd!
}


//ֻ�����ַ�
//abc-bcd-qwlkj��� jkl-wqd-cbcba  
//
class Solution {
public:
	bool isletter(char ch)//�ж��Ƿ�Ϊ��ĸ
	{
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			return true;
		else return false;

	}
	string reverseOnlyLetters(string s) {
		int begin = 0, end = s.size() - 1;//����˫ָ�뷨���в���
		while (begin <= end)//���������Ǿ�ֹͣ��
		{
			if (isletter(s[begin]) && isletter(s[end]))//yes,ǰ������������ĸ
			{
				swap(s[begin], s[end]);
				begin++;//
				end--;
			}
			else if (isletter(s[begin]) && (!isletter(s[end])))//ǰ���ǣ����治��
			{
				end--;
			}
			else if (!isletter(s[begin]) && isletter(s[end]))//ǰ���ǣ�����
			{
				begin++;//begin������
			}
			else//�����ǣ�begin�����ߣ�end��ǰ��
			{
				begin++;
				end--;
			}

		}
		return s;
	}

};

//������1.������2.��Χfor
void test_string1()
{
  
string s1("hello");
string::iterator it=s1.begin();//s1.begin(),�ǵ�һ�����ݵĵ�ַ��s1.end���������һ�����ݵĺ�һ���ĵ�ַ
//���iterator�Ƕ�����string���棬it����ָ���˵�һ�����ݵĵ�ַ
//���ڿ����������һ����ָ��һ��������
//
while(it!=s1.end())//ֱ����β�ͽ����ˣ����ǲ�������<
{
  cout<<*it<<" ";//*����ȡ��������
  ++it;//����һ����ַ
}
cout<<endl;
//���˿��Զ�������д
 it=s1.begin();//s1.begin(),�ǵ�һ�����ݵĵ�ַ��s1.end���������һ�����ݵĺ�һ���ĵ�ַ
//���iterator�Ƕ�����string���棬it����ָ���˵�һ�����ݵĵ�ַ
//���ڿ����������һ����ָ��һ��������
//
while(it!=s1.end())//ֱ����β�ͽ�����
{
  *it-=1;//*����ȡ��������
  ++it;//����һ����ַ
}
cout<<endl;


//��Χfor,auto�����Զ�ʶ��
//for(auto e:s1)//��s1����ÿ���ַ�ȡ������ֵ��e������Ҫ�Լ�++���Զ��жϽ���
//{
//  cout<<e<<" ";
//}
cout<<endl;

//Ҫ�޸ľ�Ҫ������
//for(auto& e:s1)
//{
//  e-=1;
//}
cout<<endl;

//���������
//���ű���
string::reverse_iterator rit=s1.rbegin();//rbegin�����������һ�����ݵĵ�ַ
//Ϊ�˼򻯴���Ҳ����ֱ��auto�Ƶ�
//
//auto  rit=s1.rbegin()
//
while(rit!=s1.rend())//rend�����ǵ�һ�����ݵ�ǰһ����ַ
{
  cout<<*rit<<" ";//olleh������������
  ++rit;//�����������++���������ߵ�
}
cout<<endl;

//������������������ʲô�أ����е������������õ��������ַ����޸�
//1.����string����˵������[]���㹻����,ȷʵ���Բ��õ�����
//2�������������������ݽṹ��Ҳ����ʹ�ã���list��map��set����Щ�ǲ�֧��[]����Ϊֻ��������һ���Ķ�����֧��[]�������±꣬
//���ۣ�������string�û��õ��������������ǻ���ϲ���±��[],

//����const����������ͨ�������ǿɶ���д��
string cstr("hello world");
//funcion(cstr);
string::const_iterator re=s1.begin();//ֻ����д��ͬ�����з��������
//cbegin��������const����������������ƽʱ����̫�ã�

}



//���������ĺ���
void test_string3()
{
string s1;
s1.reserve(100);//�������������Ĵ�С����������100������ԭ��������
string s2;
s2.resize(100,'x');//Ҳ�ǿ������������Ĵ�С��ͬʱ�����Զ�����г�ʼ�����罫s1��Ч���ݵĺ���ȫ�����ó�x�����û�еڶ�����������Ĭ���ǡ�\0��
}





//����
void test_string2()
{

string s2="hello world";
cout<<s2.c_str()<<endl;//��stringת���c���Ե���ʽ�ַ�����char*����\0����
string file("test.txt");
//����Ҫ��c���Ե���ʽ��һ���ļ�
FILE* fout=fopen(s2.c_str(),"w"); //fopen��һ��������char*���������⺯��

//Ҫ��ȡ���ļ��ĺ�׺

  size_t pos=file.find('.');//��file������ҡ�x����λ�ã�find�ķ���ֵ��size_t,�±��0��ʼ�����ҵ�һ�����ϵ����꣬����ͷ���-1
  
string s1(file,pos);
cout<<s1<<endl;
if(pos!=string::npos)
{
  string suffix=file.substr(pos);
cout<<suffix<<endl;
}






}






int main()
{
//	init();
//	func();
//	operatoracess();
//	add();
//	Solution sl;

//	sl.reverseOnlyLetters("Test1ng-Leet=code-Q!");
//test_string1();
//test_string3();
test_string2();
  return 0;
}


















