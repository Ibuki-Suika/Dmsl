#pragma once
#include <vector>
#include <string>
#include <map>
#include <cstdint>
#include <string>


namespace Dmsl {
	namespace Compiler {

		//Ԥ����ɹ�
		struct Precompiled {
			struct Unit {
				std::vector<std::string> initProgram, mainProgram;	//��ʼ���������������
				std::map<std::string, uint32_t> varTable;	//˽�б������ӱ�
				uint32_t memSize;	//�ڴ�ռ�ô�С
				uint32_t num;	//����Ԫ���
			};
			std::map<std::string, uint32_t> attributeVars, uniformVars,cFuncs,cMet;	//���Ա��������ױ�������ӱ�C���Ժ������ӱ�C���Է���
			std::map<std::string, float> constants;	//����
			std::map<uint32_t, uint32_t> metParamNum, funcParmNum;	//�������������ͺ�����������
			std::vector<Unit> units;	//����Ԫ
		};

		//Ԥ������룬����trueΪ�ɹ�
		bool Precompile(const std::string& codeStr,Precompiled&,std::ostream& log);

		//��ʾԤ�����Ĵ���
		void DisplayPrecompiled(const Precompiled&, std::ostream&);
	}
}
