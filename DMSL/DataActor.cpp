#include "DataActor.h"
#include <Windows.h>

static inline double Mix(double smallVar, double bigVar, double x) {	//�����ֵ
	return x * (bigVar - smallVar) + smallVar;
}

void Dmsl::DataActor::Update() {
	for (auto& p : m_datas) {

		//��ȫ���
		if (IsBadWritePtr(p.data, sizeof(*p.data)))
			throw std::exception("DataActor:Bad ptr write.");

		++p.timer;

		//TODO:�޸Ĵ��д��룬�����޸Ĳ�ֵ����
		*p.data = Mix(p.start, p.end, double(p.timer) / p.len);
	}
	auto nend = std::remove_if(m_datas.begin(), m_datas.end(), [](const Data& i) {
		return i.timer >= i.len;
	});
	m_datas.erase(nend, m_datas.end());

	//�����Ż�
	/*auto size = m_datas.size();
	auto lastNum = size-1;
	if (size == 0) return;
	for (unsigned i = 0; i <= lastNum; ++i) {
	auto& p = m_datas[i];
	if (p.timer <= p.len) {
	if (p.slowMotion)
	*p.data = Mix(p.start, p.end, SlowMotion(double(p.timer) / p.len));
	else
	*p.data = Mix(p.start, p.end, double(p.timer) / p.len);
	++p.timer;
	}
	else {
	if (lastNum != i) {
	std::swap(p, m_datas[lastNum]);
	--i;
	}
	lastNum--;
	}
	}
	m_datas.resize(lastNum + 1);*/
}
