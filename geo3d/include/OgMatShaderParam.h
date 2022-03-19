 #pragma once
#include <osg/Notify>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Geometry>
#include <osg/Geode>

#include <osgUtil/Optimizer>

#include <osg/Vec3>
#include <osg/Texture1D>
#include <osg/Texture2D>
#include <osg/Texture3D>
#include <osg/Matrix>
#include <osg/Uniform>

#include <osgDB/Registry>
#include <osgDB/ReadFile>

#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>

#include <osgSim/OverlayNode>
#include <osgViewer/Viewer>
#include "OGBasDef.h"

enum OG_FRAME_DLL ShaderParamType{
	MPT_FLOAT = 0,
	MPT_VECTOR2 = 1,
	MPT_VECTOR3 = 2,
	MPT_VECTOR4 = 3,
	MPT_INT=4,
	MPT_SAMPLER1D=5,
	MPT_SAMPLER2D=6,
	MPT_SAMPLER3D=7,
	MPT_BOOL=8,
	MPT_SAMPLER2DRECT=9,
};

class OG_FRAME_DLL ShaderParam
{
public:
	ShaderParam(void);
	virtual ~ShaderParam(void);

	void SetMAtParamType(ShaderParamType paramType){m_paramType=paramType;};
	ShaderParamType getMatParamType(){return m_paramType;};

	virtual osg::Uniform* InstanceUniform(std::string name)=0;
	virtual void UpdateUniform(osg::Uniform* uniformObj)=0;

protected:
	ShaderParamType m_paramType;
};


class OG_FRAME_DLL FloatMatParam : public ShaderParam
{
public:
	FloatMatParam(void){m_paramType = MPT_FLOAT;};
	virtual ~FloatMatParam(void){};

	void SetValue(float value){m_value=value;};
	float GetValue(){return m_value;};

	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);

private:
	float m_value;
};

class OG_FRAME_DLL BoolMatParam : public ShaderParam
{
public:
	BoolMatParam(void){m_paramType = MPT_BOOL;};
	virtual ~BoolMatParam(void){};

	void SetValue(bool value){m_value=value;};
	bool GetValue(){return m_value;};

	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);

private:
	bool m_value;
};

class OG_FRAME_DLL IntMatParam : public ShaderParam
{
public:
	IntMatParam(void){m_paramType = MPT_INT;};
	virtual ~IntMatParam(void){};

	void SetValue(int value){m_value=value;};
	int GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);

private:
	int m_value;
};

class OG_FRAME_DLL Vector2MatParam : public ShaderParam
{
public:
	Vector2MatParam(void){m_paramType = MPT_VECTOR2;};
	virtual ~Vector2MatParam(void){};

	void SetValue(osg::Vec2 value){m_value=value;};
	osg::Vec2  GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);

private:
	osg::Vec2  m_value;
};
class OG_FRAME_DLL Vector3MatParam : public ShaderParam
{
public:
	Vector3MatParam(void){m_paramType = MPT_VECTOR3;};
	virtual ~Vector3MatParam(void){};

	void SetValue(osg::Vec3 value){m_value=value;};
	osg::Vec3  GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);

private:
	osg::Vec3 m_value;
};

class OG_FRAME_DLL Vector4MatParam : public ShaderParam
{
public:
	Vector4MatParam(void){m_paramType = MPT_VECTOR4;}
	virtual ~Vector4MatParam(void){};

	void SetValue(osg::Vec4 value){m_value=value;};
	osg::Vec4  GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);

private:
	osg::Vec4 m_value;
};


class OG_FRAME_DLL Sampler1DMatParam : public ShaderParam
{
public:
	Sampler1DMatParam(void){m_paramType = MPT_SAMPLER1D;};
	virtual ~Sampler1DMatParam(void){};

	void SetValue(std::string value){m_value=value;};
	std::string GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);

private:
	std::string m_value;
};



class OG_FRAME_DLL Sampler2DMatParam : public ShaderParam
{
public:
	Sampler2DMatParam(void){m_paramType = MPT_SAMPLER2D;}
	virtual ~Sampler2DMatParam(void){};

	void SetValue(std::string value){m_value=value;};
	std::string GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);
private:
	std::string m_value;
};


class OG_FRAME_DLL Sampler3DMatParam : public ShaderParam
{
public:
	Sampler3DMatParam(void){m_paramType = MPT_SAMPLER3D;};
	virtual ~Sampler3DMatParam(void){};

	void SetValue(std::string value){m_value=value;};
	std::string GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);
private:
	std::string m_value;
};


class OG_FRAME_DLL Sampler2DRectMatParam : public ShaderParam
{
public:
	Sampler2DRectMatParam(void){m_paramType = MPT_SAMPLER2DRECT;};
	virtual ~Sampler2DRectMatParam(void){};

	void SetValue(std::string value){m_value=value;};
	std::string GetValue(){return m_value;};
	
	osg::Uniform* InstanceUniform(std::string name);
	void UpdateUniform(osg::Uniform* uniformObj);
private:
	std::string m_value;
};


