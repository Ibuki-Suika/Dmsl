#pragma once
#include <ostream>
#include <string>
#include <vector>
#include <cstdint>
#include <map>

namespace Dmsl{
    namespace Compiler{
		struct Compiled {
			struct Unit {
				uint32_t memSize;
				std::vector<uint8_t> initProgram, mainProgram;
			};
			std::map<std::string, uint32_t> linkTable;
			std::map<uint32_t,uint32_t> metParamNum,funcParamNum;
			std::map<uint32_t, Unit> units;
			uint32_t uniformSize,cFuncSize,cMetSize;
		};
    };
    class DmslUnit;

    class DmslVirtualMachine{ //Dmsl�����
    friend class DmslUnit;
    private:
        Compiler::Compiled m_program;
        std::vector<void(*)(float*)> m_cMetLinks;
        std::vector<float(*)(float*)> m_cFuncLinks;
        std::vector<float> m_uniform;

        bool m_good = false;
        int m_dmovfs_sel = 0;

        void runCode(const std::vector<uint8_t>& code,std::vector<float>* attrMem) const;
    public:
        DmslVirtualMachine(const std::string& programCode,std::ostream& log);    //�������������־������Ա�����뵽�����
        inline bool Good() const {return m_good;}; //�Ƿ�״̬����
        inline bool HaveUnit(uint32_t u) const {return m_program.units.count(u)==1;}
        void SetUniform(const std::string& uniform,float);  //����Uniform����
        void LinkCFunc(const std::string& cfunc,float(*)(float*));  //����C����
        void LinkCMet(const std::string& cmet,void(*)(float*));    //����C����
        inline void SetDMOVFSSelect(int select){m_dmovfs_sel = select;} //���ظ�ֵʱʹ���ĸ�ֵ����0��ʼ
    };

    class DmslUnit{ //ִ�е�Ԫ
    friend class DmslVirtualMachine;
    private:
        std::vector<float> m_attribute;
        const DmslVirtualMachine* m_dvm;
        uint32_t m_unit;
    public:
        DmslUnit(const DmslVirtualMachine& dvm,uint32_t unit);
        inline void Call(){m_dvm -> runCode(m_dvm->m_program.units.at(m_unit).mainProgram,&m_attribute);} //���г���
        void SetAttribute(const std::string& attribute,float);  //����Attribute����
        float GetAttribute(const std::string& attribute);   //��ȡAttribute����
    };
}

