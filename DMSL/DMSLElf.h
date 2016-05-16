#pragma once
namespace Dmsl {
	namespace VirtualMachine {
		enum  class ElfCode {
			//����ָ��
			DMOVFS = 0x10,	//���ظ�ֵ�����������uint32_t n,k;float datas[n];�������ָ����һ��float��ֵ����ַΪk�ı�����
			MOV = 0x11,	//��ջ��ȡֵ����ֵ��������ָ�룩ָ��ı���
			CFUNC = 0x12,	//���ú���������Ϊ������ַ��ע���з���ֵ��ջ���ֲ�ͬ
			CMET = 0x13,	//���÷���������Ϊ������ַ��û�з���ֵ��ջ���ֲ�ͬ
			UNPA = 0x14,	//������ջ��ָ�뵽attribute����
			UNPU = 0x15,	//������ջ��ָ�뵽uniform����
			PUSH = 0x16,	//ѹջ��float
			PUSHPTR = 0x17,	//ѹջ��uint32_t
			IF = 0x19,	//���ջ��Ϊbool = true�������Ӵ�ָ�������ת��ָ�����ָ���Ĵ���λ��
			JMP = 0x1A,	//��������ת���뵽����λ��
			END = 0xFF,	//����ִ��

			//����ָ��
			NEGA = 0x20,	//ջ��ȡ��ѹջ

			//Ҫ��ջ��������Ϊfloat����ѹ��float
			ADD = 0x21,	//�ӷ�
			SUB = 0x22,	//����
			MUL = 0x23,	//�˷�
			DIV = 0x24,	//����
			MOD = 0x25,	//ȡ��������

			//Ҫ��ջ��������Ϊfloat����ѹ��BOOL
			BIG = 0x30,	//����
			BIGE = 0x31,	//���ڵ���
			SML = 0x32,	//С��
			SMLE = 0x33,	//С�ڵ���
			EQ = 0x34,	//����
			NE = 0x35,	//������

			//Ҫ��ջ��������ΪBOOL����ѹ��BOOL
			AND = 0x40,	//��
			OR = 0x41,	//��
			NOT = 0x42	//��
		};
	}
}