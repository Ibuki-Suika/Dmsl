#pragma once
#include <map>
#include <vector>
#include <string>
#include <stack>
#include "DMSLPrecompiler.h"
#include "DMSLElf.h"

namespace Dmsl {
	namespace Compiler {
		struct Compiled {
			struct Unit {
				uint32_t memSize;
				std::vector<uint32_t> initProgram, mainProgram;
			};
			std::map<std::string, uint32_t> linkTable;
			std::map<uint32_t, Unit> units;
		};
		
		//����
		void Compile(const Precompiled& in, Compiled& out);

		//��floatѹ������
		void PushFloat(float, std::vector<uint32_t>& out);

		//�ѵ�ַѹ�����
		void PushAddress(uint32_t, std::vector<uint32_t>& out);

		//��ָ��ѹ�����
		void PushCmd(Dmsl::VirtualMachine::ElfCode, std::vector<uint32_t>& out);

		//�������ı��ʽ�ṹ��
		struct ParsedMathWord {
			enum {
				NUMBER, VARNAME, OPR, FUNC_NAME
			}type;
			bool nega = false;	//�෴��
			union {
				std::string varName;
				std::string funcName;
				float number;
				struct Opr{
					int level;	//���ȼ���¼
					enum {
						COMMA,	//1�����ȼ�
						AND,
						OR,
						NOT,	//2�����ȼ�
						NE,	//3�����ȼ�
						EQ,
						BIG,
						BIGE,
						SML,
						SMLE,
						ADD,	//4��
						SUB,
						MUL,	//5
						DIV,
						MOD,
						CALL_FUNC	//6
					}opr;	//������
					//���������ţ����ȼ�+10��������-10
				}opr;
			};
		};

		//�������ʽ������
		void ParseMath(const Precompiled& in, std::string, std::vector<uint32_t>& out);

		//�������ʽ�²㺯�� -- ѹ��ɨ�赽������
		void ParseData(const Precompiled& in, const Precompiled::Unit& unit,const ParsedMathWord&, std::vector<uint32_t>& out);

		//�������ʽ�²㺯�� -- ѹ��ɨ�赽�Ĳ�����
		void ParseOperator(const Precompiled& in,const ParsedMathWord&, std::vector<uint32_t>& out,std::stack<ParsedMathWord::Opr>& stk);

		//��ѯ��������
		//0 - ��֪��
		//1 - attribute
		//2 - unit::var
		//3 - uniform
		//4 - constant_define
		//5 - number
		//6 - cfunc
		//7 - cmethod
		int WhatsTheVar(const Precompiled& in,const Precompiled::Unit& unit, const std::string& name);

	}
}