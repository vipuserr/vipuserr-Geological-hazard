#pragma once
#include "s3dqtapp_global.h"

#include "qobject.h"
#include "qslider.h"
#include "qspinbox.h"


using namespace std;

//QSlider�����QDoubleSpinBox��ϣ��γ�����

namespace Smart3dMap 
{
	class S3DQTAPP_EXPORT ComQSliderQDoubleSpinBox:public QObject
	{
		Q_OBJECT
	public:
		ComQSliderQDoubleSpinBox(QSlider* slider, QDoubleSpinBox* spinbox,bool useFocus = true);
		
		void setSliderValue(int val);

		void setSpinBoxValue(double val);

		void setSpinBoxRange(double min, double max);

	//private:
		//Slider������һ���Ǵ�0-ĳ��ֵ 
		void setSliderRange(int min = 0, int max = 10000);

		void updateSliderValue(double spinBoxVal);
		void updateSpinBoxValue(double sliderVal);

	public	slots:
		void changeSliderValue();
		void changeSpinBoxValue();

	private:
		QSlider* m_Slider;
		QDoubleSpinBox* m_SpinBox;
		bool	m_UserFocus;
	};
}


