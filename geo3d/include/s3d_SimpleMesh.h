  #pragma once

#include "s3d_KerObbtDef.h"

#include <vector>
#include <stack>
#include <string>
#include <map>
#include <sstream>
#include <osg/switch>

using namespace osg;
using namespace std;


#define _X_COORD  0
#define _Y_COORD  1
#define _Z_COORD  2


	class LIB_GMKEROBBT_EXP OGSimpleMesh
	{
		friend class OGCompdMesh;
	public:
		string				materialName;
		string				name;
//		std::Vec3d			mOffset;
		std::vector<Vec3d>	positionArray;
		std::vector<Vec3f>	normalArray;
		std::vector<Vec4f>	diffuseArray;
		std::vector<Vec4f>	specularArray;
		std::vector<Vec2f>	texture0Array;
		std::vector<Vec2f>	texture1Array;
		std::vector<Vec2f>	texture2Array;
		std::vector<Vec2f>	texture3Array;
		std::vector<Vec2f>	texture4Array;
		std::vector<Vec2f>	texture5Array;
		std::vector<Vec2f>	texture6Array;
		std::vector<Vec2f>	texture7Array;
		std::vector<Vec3i>   triangleArray;
		std::vector<Vec3i>   triangleTop;
		std::vector<long>	indexArray;
	public:
		OGSimpleMesh();
		~OGSimpleMesh();

		void		convertPostionsToLocalCoordinate(const Vec3d& center);
		void		calculateDefaultNormals();
		void		makerotate(long coord,double angle);
		void		makerotate(osg::Vec3d& point,long coord ,double angle);
		void		getMeshcenter(osg::Vec3d& center);
		size_t		getIndexBufferSize();

	public:
		void		setNull();
		bool        isNull();
		bool		merge(OGSimpleMesh* src);
		void		operator = (const OGSimpleMesh& mesh);
	};


	class  LIB_GMKEROBBT_EXP OGCompdMesh
	{
	public:
		OGCompdMesh();
		~OGCompdMesh();

// 		Vec3d				moffset;
 
	public:
		//设置顶点索引信息是不是16位的
		void		calculateDefaultNormals();
		size_t		calculateIndexNum();//
		void		setNull();
		void		operator = (OGCompdMesh& mesh);
	

		//创建一个OGSimpleMesh
		OGSimpleMesh*	createSimpleMesh(const string& name);
		OGSimpleMesh* getSimpleMesh(size_t index);
		OGSimpleMesh* getSimpleMesh(const string& name);
		//通过索引取的点
		OGSimpleMesh* getPoint(long start,long end,size_t index = 0);

		void removeSimpleMesh(size_t index);
		void removeSimpleMeshNotDel(size_t index);
		size_t getSimpleMeshNum() { return mSimpleMeshList.size(); }

		bool merge(OGCompdMesh* smesh);
		bool merge();

	protected:
		std::vector<OGSimpleMesh*>	mSimpleMeshList;

	private:
		 size_t msMaxIndexBufferSize;
	};
	typedef OGCompdMesh SuperMesh;

	//下标为0
	void  LIB_GMKEROBBT_EXP MeshBufToASimpleMesh( OGSimpleMesh* pSimpMesh,
											Vec3d *pMeshPnt, long lMeshPntNum, 
											Vec3i *pMeshTri, long lMeshTriNum, 
											Vec3i *pMeshTop=NULL, 
											string strMatName="", Vec4 *pMeshColor=NULL, long lColorNum = 1, 
											Vec3f *pMeshNormal=NULL, 
											Vec2 *texturePos=NULL, long lTexLayerNum = 0);



