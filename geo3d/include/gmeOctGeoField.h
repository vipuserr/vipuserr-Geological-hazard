#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeEntity.h"

namespace Smart3dMap {
	// 局部坐标系
	class OG_GME_API gmeLocalAxis {
	public:
		// 局部坐标系的3个坐标轴是互相正交的。
		// 由全局标系得到局部坐标系的过程：
		// （1）将坐标系原点平移至点 origin；
		// （2）绕Z轴逆时针旋转zAngle（单位：弧度）；
		// （3）以方向为(1, -1, 0)且过原点的直线为轴逆时针旋转以抬升XY平面，使得新平面与原始平面的二面角为dihedralAngle（单位：弧度）。
		gmeLocalAxis(const gme_vector3d& origin = gme_vector3d(), const gme_radian_d& zAngle = gme_radian_d(0), const gme_radian_d& dihedralAngle = gme_radian_d(0));

		gme_vector3d GetOrigin() const;
		gme_radian_d GetZAngle() const;
		gme_radian_d GetDihedralAngle() const;

		// 全局坐标转换为局部坐标的坐标转换矩阵。
		const gme_matrix4_d& TransformOfGlobalToLocal() const;
		// 全局坐标转换为局部坐标。
		gme_vector3d GlobalToLocal(const gme_vector3d& pt) const;
		// 由局部坐标计算网格索引。
		gme_vector3i LocalXYZToIJK(const gme_vector3d& localPt, const gme_vector3d& cellSize) const;

		// 局部坐标转换为全局坐标的坐标转换矩阵。
		const gme_matrix4_d& TransformOfLocalToGlobal() const;
		// 局部坐标转换为全局坐标。
		gme_vector3d LocalToGlobal(const gme_vector3d& pt);

	private:
		gme_vector3d origin_;
		double zAngle_, dihedralAngle_;
		gme_matrix4_d transGlobalToLocal_, transLocalToGlobal_;
	};

	// 采用八叉树索引的规则网格模型（或属性场）。
	class OG_GME_API gmeOctGeoField : public gmeGeometry {
	public:
		// 网格模型的分片。
		class OG_GME_API Tile {
		public:
			// 沿单坐标轴方向单个分块所包含的网格的数目。
			static GString DefaultTileFormat();
			static const GString FieldCellMask;
			static const GString FieldSubCellMask;
			static const GString FieldCellModifiedMask;

		public:
			Tile(int indexId, int level, int r, int s, int t, const gme_vector3i& span);
			virtual ~Tile();

			int GetR() const { return r_; }
			int GetS() const { return s_; }
			int GetT() const { return t_; }
			gme_vector3i GetSpan() const { return span_; }

			// 分片内网格单元的有效性标记。(u, v, w)是网格在当前块内的相对位置编号。
			bool IsCellValid(int u, int v, int w) const;
			bool SetCellValidation(int u, int v, int w, bool isValid);
			// 批量取网格是否有效的标记位数据。每字节中的每比特位对应一个网格。比特位为0表示无效，为1表示有效。
			// 调用者不能删除data输出的指针，且不能长期保存并使用该指针。因为底层数据缓存层随时可能释放其指向的内存。
			// 返回true时表示输出的 data 和 size 值有效。
			bool GetCellMaskData(unsigned char*& data, int& size) const;

			// 分片内网格单元的子单元是否同质的标记。(u, v, w)是网格在当前块内的相对位置编号。
			bool IsSubCellHomogeneous(int u, int v, int w) const;
			bool SetSubCellHomogeneous(int u, int v, int w, bool isHomogeneous);
			// 批量取子网格与父网格是否一致的标记位数据。每字节中的每比特位对应一个网格。比特位为0表示不一致，为1表示一致。
			// 调用者不能删除data输出的指针，且不能长期保存并使用该指针。因为底层数据缓存层随时可能释放其指向的内存。
			// 返回true时表示输出的 data 和 size 值有效。
			bool GetSubCellMaskData(unsigned char*& data, int& size) const;

			// 分片内网格单元的值是否被修改的标记。(u, v, w)是网格在当前块内的相对位置编号。
			bool IsCellModified(int u, int v, int w) const;
			bool SetCellModification(int u, int v, int w, bool isModified);
			// 批量取网格是否被修改的标记位数据。每字节中的每比特位对应一个网格。比特位为0表示没有修改，为1表示有修改。
			// 调用者不能删除data输出的指针，且不能长期保存并使用该指针。因为底层数据缓存层随时可能释放其指向的内存。
			// 返回true时表示输出的 data 和 size 值有效。
			bool GetCellModificationMaskData(unsigned char*& data, int& size) const;

			// 分片内网格单元的属性值。(u, v, w)是网格在当前块内的相对位置编号。
			bool GetCellValue(int u, int v, int w, const gmeField& field, gmeFieldValue& value) const;
			bool SetCellValue(int u, int v, int w, const gmeField& field, const gmeFieldValue& value);
			bool SetCellValue(int u, int v, int w, const gmeField& field, const void* value);
			// 批量取网格属性值数据。调用者应根据属性字段的值类型来解析获取的数据。
			// 调用者不能删除data输出的指针，且不能长期保存并使用该指针。因为底层数据缓存层随时可能释放其指向的内存。
			// 返回true时表示输出的 data 和 size 值有效。
			bool GetCellValueData(const GString& fieldName, unsigned char*& data, int& size) const;
		
		private:
			int CellPositionInTileData(int u, int v, int w) const;

		private:
			int indexId_, level_, r_, s_, t_;
			gme_vector3i span_;
		};

		// 网格集合。集合中的网格单元的大小可能不一致，比如从不同层级得到的网格共同构成一个切片。
		// 集合内部可按LOD层级来组织网格。
		class CellSet {
		};

		// 八叉树索引数据。
		class OG_GME_API OctIndex {
		public:
			OctIndex();
			OctIndex(gmeOctGeoField* model, const GString& fieldName);
			virtual ~OctIndex();

		public:
			bool IsValid() const;

			// 取所属的网格模型的ID。
			GME_TYPE_OBJ_ID GetGridModeID() const;
			// 取所针对的属性字段的名字。
			GString GetFieldName() const;

			// 索引的ID。
			GME_TYPE_OBJ_ID GetId() const;
			OctIndex& SetId(GME_TYPE_OBJ_ID id);

			// 获取八叉树的层级数。
			// @return 返回八叉树的层数。N层的八叉树的层级编号从根节点至叶节点依次为：0, ..., N-1。层级编号越大，网格精细程度越高。
			int GetDepth() const;
			
			gme_vector3i GetTileSpan() const;
			OctIndex& SetTileSpan(const gme_vector3i& span);
			GString GetTileFormat() const;
			OctIndex& SetTileFormat(const GString& format);	// 暂时仅支持zip压缩格式

			// 关于单个网格单元的操作。
			// 取指定层级中网格单元的大小。
			// @param level	是从0开始的八叉树层级编号。
			// @return			对应层级网格单元的大小。
			gme_vector3d GetCellSizeAtLevel(int level) const;
			// 取指定层级中网格单元编号的范围。
			bool GetIJKBoxOfCellAtLevel(int level, gme_vector3i& minIJK, gme_vector3i& maxIJK) const;
			// 取指定层级中网格单元的属性值。
			bool GetCellValueAtLevel(int level, int i, int j, int k, const gmeField& field, gmeFieldValue& value) const;
			// 设置指定层级中网格单元的属性值。markCellAsValid为true时表示给网格赋值成功时同时设置对应网格为有效；其它情况下不改变网格的有效性。
			bool SetCellValueAtLevel(int level, int i, int j, int k, const gmeField& field, const gmeFieldValue& value, bool markCellAsValid) const;
			// 检查指定网格单元是否有效。
			bool IsCellValidAtLevel(int level, int i, int j, int k) const;
			bool SetCellValidationAtLevel(int level, int i, int j, int k, bool isValid) const;
			// 检查指定网格单元是否被修改了。
			bool IsCellModifiedAtLevel(int level, int i, int j, int k) const;
			bool SetCellModificationAtLevel(int level, int i, int j, int k, bool isModified) const;
			// 检查网格单元的子网格关于当前索引属性是否是同质的。
			bool IsSubCellHomogeneous(int level, int i, int j, int k) const;

			// 关于分块的操作。可批量读取块中的网格单元数据。
			// 取单个分块的大小。
			gme_vector3d GetTileSizeAtLevel(int level) const;
			// 以分块(tile)为单位，取指定层级中分块的编号的范围。
			bool GetIJKBoxOfTileAtLevel(int level, gme_vector3i& minIJK, gme_vector3i& maxIJK) const;
			// 取指定的分片。调用者负责管理返回的指针所指向的对象。指定的分片无效时返回空指针。
			Tile* GetTile(int level, int tileI, int tileJ, int tileK) const;

			// 更新/或重构索引。
			void Update();

		public:
			static int ComputeDepth(int max, int min, int span);

			// 计算网格所在的Tile。
			gme_vector3i CellIndexToTileIndex(const gme_vector3i& cellIJK) const;

		private:
			// 计算网格在Tile内部的索引位置。
			gme_vector3i CellIndexInTile(const gme_vector3i& cellIJK) const;
			// 计算网格在Tile数据数组中的位置。
			int CellPositionInTileData(const gme_vector3i& cellIndexInTile) const;
			gmeFieldValue::gmeType CheckAttributeDataType(const GString& fieldName) const;
			// 从子网格归并计算父网格的属性值，并返回子网格与父网格是否一致的标记(返回true表示一致，否则表示不一致)。
			// 对连续型属性，以集合的平均值为归并结果。
			// 对离散型属性，以集合内占多数的值为归并结果。
			bool ReduceValueFromSubCells(const std::vector<gmeFieldValue>& values, const gmeField& field, gmeFieldValue& value) const;

		private:
			GME_TYPE_OBJ_ID indexId_;
			GString fieldName_;
			gme_vector3i tileSpan_;
			GString tileFormat_;
			gmeOctGeoField* model_;
		};


	public:
		//属性场颜色信息 luohh add 2021.11.15
		typedef enum GME_COLOR_TYPE {
			GME_CL_DISCRETE = 0,//离散取区间给色
			GME_CL_CONTINUE = 1,//连续取单值给色
		}GME_COLOR_TYPE;

		typedef struct Gme_FieldColor //色带数据
		{
			GME_COLOR_TYPE fieldColorType;
			vector<std::pair<double, gme_color4>> vFieldColors;
			Gme_FieldColor(){
				fieldColorType = GME_COLOR_TYPE::GME_CL_CONTINUE;
			}
		}Gme_FieldColor;

		// 创建网格模型。
		// @param name		模型的名字。
		// @param localAxis	局部坐标系信息。
		// @param minPt		网格模型在局部坐标系下最小外包矩形的左下角点坐标。
		// @param maxPt		网格模型在局部坐标系下最小外包矩形的右上角点坐标。
		// @param cellSize	局部坐标系下网格单元的大小。
		// @param schema	网格所包含的属性字段的定义。
		// @return			返回所创建的网格模型对象。
		static gmeOctGeoField* Create(const GString& name, const gmeLocalAxis& localAxis, const gme_vector3d& minPt, const gme_vector3d& maxPt, const gme_vector3d& cellSize, const gmeFields& schema);
		// 获取有效的网格模型的ID列表。
		// @param excludeDeleting 是否排除处于被删除状态的模型。
		static std::vector<GME_TYPE_OBJ_ID> ListOctGeoFieldIds(bool excludeDeleting = true);

		// 缺省的八叉树索引字段的名字。实际为空，表示不针对特定属性字段。
		static GString DefaultOctIndexField();

	public:
		gmeOctGeoField();
		gmeOctGeoField(const GString& name, const gmeLocalAxis& localAxis, const gme_vector3d& cellSize, const gme_vector3i& minIJK, const gme_vector3i& maxIJK, const gmeFields& schema);
		virtual ~gmeOctGeoField();

	public:
		// 重载父类定义的方法。
		virtual long Clone(gmeOctGeoField& obj);//拷贝对象
		virtual long Clear();//清空
		virtual long Load(GME_TYPE_OBJ_ID objID, long lodLevel = 0);//从数据库重新加载
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel = 0);//保存 // 添加第二参数，修复 -- LH.2021.11.05 17:10 added.
		virtual long CompressSave();//压缩存储
		virtual long Delete();
		virtual long UndoDelete();

		// 网格模型的元数据信息。
		const gmeLocalAxis& GetLocalAxix() const;
		gmeOctGeoField& SetLocalAxis(const gmeLocalAxis& localAxis);
		// 取局部坐标系下的AABB。
		void GetAABB(gme_vector3d& minPt, gme_vector3d& maxPt) const;
		const gme_vector3d& GetCellSize() const;
		gmeOctGeoField& SetCellSize(const gme_vector3d& size);
		void GetIJKBox(gme_vector3i& minIJK, gme_vector3i& maxIJK) const;
		gmeOctGeoField& SetIJKBox(const gme_vector3i& minIJK, const gme_vector3i& maxIJK);
		const gmeFields& GetSchema() const;
		gmeOctGeoField& SetSchema(const gmeFields& schema);	// 设置内存对象的属性字段定义，并不改变存储引擎中记录的值。

		// 关于最精细层（即最底层）网格单元的操作。
		// 设置/获取网格单元在指定字段上的取值。markCellAsValid为true时表示同时设置对应网格为有效，否则不改变网格的有效性。
		void SetCellValue(int i, int j, int k, const gmeField& field, const gmeFieldValue& value, bool markCellAsValid = true);
		gmeFieldValue GetCellValue(int i, int j, int k, const gmeField& field) const;
		// 批量设置网格单元在指定字段上的取值。
		// 参数field指明了要设置其值的属性字段的名字、值的数据类型。
		// 参数data是一个三维数组。数组的实际元素的类型与field记录的值的类型一致，包含的元素数目等于 dimK * dimJ * dimI，元素的存储顺序是I优先、J次之，K最后。
		// 指针data将被强制转换为field指定的值类型的指针。
		// lowCellIJK用于指定data数组中第一个元素对应的网格的位置，数组中其它位置元素的(I, J, K)编号均大于该位置。
		// markCellAsValid为true时，该方法将同时设置被赋值的网格为有效网格，否则不修改网格的有效性。
		void SetCellsValue(const void* data, const gme_vector3i& lowCellIJK, int dimI, int dimJ, int dimK, const gmeField& field, bool markCellAsValid = true);
		void SetCellsValue(gmeFieldValues& values, const gme_vector3i& lowCellIJK, int dimI, int dimJ, int dimK, const gmeField& field, bool markCellAsValid = true);
		bool GetCellsValue(const gme_vector3i& lowCellIJK, int dimI, int dimJ, int dimK, const gmeField& field, gmeFieldValues& values);
		// 设置/检查网格单元是否有效。
		void SetCellValidation(int i, int j, int k, bool isValid);
		bool IsCellValid(int i, int j, int k) const;

		// 模型对应的八叉树索引数据。
		// 获取当前已有的索引的信息。
		const std::vector<OctIndex>& ListOctIndices() const;
		// 针对指定属性字段创建八叉树索引。
		// @param fieldName	属性字段的名字。
		// @return				操作是否成功。
		bool CreateOctIndex(const GString& fieldName);
		// 取针对特定属性字段的八叉树索引。
		// @param fieldName	属性字段的名字。可为空，表示取缺省的通用八叉树索引。
		// @return				返回对应的八叉树索引对象。返回空指针时表示没有关于特定字段的索引。调用者不能删除返回的指针所指向的对象。
		const OctIndex* GetOctIndex(const GString& fieldName) const;
		// 删除指定的八叉树索引。
		bool DeleteOctIndex(const GString& fieldName);
		// 为内存对象配置索引元数据。
		gmeOctGeoField& SetOctIndices(const std::vector<OctIndex>& octIndices);

		// 更新或重建八叉树索引。
		void UpdateIndices();

		// 取较优的分片大小。
		gme_vector3i GetOptTileSpan() const;


		//属性场颜色信息 luohh add 2021.11.15
		long SetColorMap(Gme_FieldColor fieldColor);
		long GetColorMap(Gme_FieldColor &fieldColor);

		protected:
			virtual long CalBox();//被GetBox调用,计算包围盒
	private:
		Gme_FieldColor mColorMap;

		gmeLocalAxis localAxis_;
		gme_vector3d cellSize_;
		gme_vector3i minIJK_, maxIJK_;
		gmeFields schema_;
		std::vector<OctIndex> octIndices_;
	};
}
