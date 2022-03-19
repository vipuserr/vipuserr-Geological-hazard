#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeEntity.h"

namespace Smart3dMap {
	// �ֲ�����ϵ
	class OG_GME_API gmeLocalAxis {
	public:
		// �ֲ�����ϵ��3���������ǻ��������ġ�
		// ��ȫ�ֱ�ϵ�õ��ֲ�����ϵ�Ĺ��̣�
		// ��1��������ϵԭ��ƽ������ origin��
		// ��2����Z����ʱ����תzAngle����λ�����ȣ���
		// ��3���Է���Ϊ(1, -1, 0)�ҹ�ԭ���ֱ��Ϊ����ʱ����ת��̧��XYƽ�棬ʹ����ƽ����ԭʼƽ��Ķ����ΪdihedralAngle����λ�����ȣ���
		gmeLocalAxis(const gme_vector3d& origin = gme_vector3d(), const gme_radian_d& zAngle = gme_radian_d(0), const gme_radian_d& dihedralAngle = gme_radian_d(0));

		gme_vector3d GetOrigin() const;
		gme_radian_d GetZAngle() const;
		gme_radian_d GetDihedralAngle() const;

		// ȫ������ת��Ϊ�ֲ����������ת������
		const gme_matrix4_d& TransformOfGlobalToLocal() const;
		// ȫ������ת��Ϊ�ֲ����ꡣ
		gme_vector3d GlobalToLocal(const gme_vector3d& pt) const;
		// �ɾֲ������������������
		gme_vector3i LocalXYZToIJK(const gme_vector3d& localPt, const gme_vector3d& cellSize) const;

		// �ֲ�����ת��Ϊȫ�����������ת������
		const gme_matrix4_d& TransformOfLocalToGlobal() const;
		// �ֲ�����ת��Ϊȫ�����ꡣ
		gme_vector3d LocalToGlobal(const gme_vector3d& pt);

	private:
		gme_vector3d origin_;
		double zAngle_, dihedralAngle_;
		gme_matrix4_d transGlobalToLocal_, transLocalToGlobal_;
	};

	// ���ð˲��������Ĺ�������ģ�ͣ������Գ�����
	class OG_GME_API gmeOctGeoField : public gmeGeometry {
	public:
		// ����ģ�͵ķ�Ƭ��
		class OG_GME_API Tile {
		public:
			// �ص������᷽�򵥸��ֿ����������������Ŀ��
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

			// ��Ƭ������Ԫ����Ч�Ա�ǡ�(u, v, w)�������ڵ�ǰ���ڵ����λ�ñ�š�
			bool IsCellValid(int u, int v, int w) const;
			bool SetCellValidation(int u, int v, int w, bool isValid);
			// ����ȡ�����Ƿ���Ч�ı��λ���ݡ�ÿ�ֽ��е�ÿ����λ��Ӧһ�����񡣱���λΪ0��ʾ��Ч��Ϊ1��ʾ��Ч��
			// �����߲���ɾ��data�����ָ�룬�Ҳ��ܳ��ڱ��沢ʹ�ø�ָ�롣��Ϊ�ײ����ݻ������ʱ�����ͷ���ָ����ڴ档
			// ����trueʱ��ʾ����� data �� size ֵ��Ч��
			bool GetCellMaskData(unsigned char*& data, int& size) const;

			// ��Ƭ������Ԫ���ӵ�Ԫ�Ƿ�ͬ�ʵı�ǡ�(u, v, w)�������ڵ�ǰ���ڵ����λ�ñ�š�
			bool IsSubCellHomogeneous(int u, int v, int w) const;
			bool SetSubCellHomogeneous(int u, int v, int w, bool isHomogeneous);
			// ����ȡ�������븸�����Ƿ�һ�µı��λ���ݡ�ÿ�ֽ��е�ÿ����λ��Ӧһ�����񡣱���λΪ0��ʾ��һ�£�Ϊ1��ʾһ�¡�
			// �����߲���ɾ��data�����ָ�룬�Ҳ��ܳ��ڱ��沢ʹ�ø�ָ�롣��Ϊ�ײ����ݻ������ʱ�����ͷ���ָ����ڴ档
			// ����trueʱ��ʾ����� data �� size ֵ��Ч��
			bool GetSubCellMaskData(unsigned char*& data, int& size) const;

			// ��Ƭ������Ԫ��ֵ�Ƿ��޸ĵı�ǡ�(u, v, w)�������ڵ�ǰ���ڵ����λ�ñ�š�
			bool IsCellModified(int u, int v, int w) const;
			bool SetCellModification(int u, int v, int w, bool isModified);
			// ����ȡ�����Ƿ��޸ĵı��λ���ݡ�ÿ�ֽ��е�ÿ����λ��Ӧһ�����񡣱���λΪ0��ʾû���޸ģ�Ϊ1��ʾ���޸ġ�
			// �����߲���ɾ��data�����ָ�룬�Ҳ��ܳ��ڱ��沢ʹ�ø�ָ�롣��Ϊ�ײ����ݻ������ʱ�����ͷ���ָ����ڴ档
			// ����trueʱ��ʾ����� data �� size ֵ��Ч��
			bool GetCellModificationMaskData(unsigned char*& data, int& size) const;

			// ��Ƭ������Ԫ������ֵ��(u, v, w)�������ڵ�ǰ���ڵ����λ�ñ�š�
			bool GetCellValue(int u, int v, int w, const gmeField& field, gmeFieldValue& value) const;
			bool SetCellValue(int u, int v, int w, const gmeField& field, const gmeFieldValue& value);
			bool SetCellValue(int u, int v, int w, const gmeField& field, const void* value);
			// ����ȡ��������ֵ���ݡ�������Ӧ���������ֶε�ֵ������������ȡ�����ݡ�
			// �����߲���ɾ��data�����ָ�룬�Ҳ��ܳ��ڱ��沢ʹ�ø�ָ�롣��Ϊ�ײ����ݻ������ʱ�����ͷ���ָ����ڴ档
			// ����trueʱ��ʾ����� data �� size ֵ��Ч��
			bool GetCellValueData(const GString& fieldName, unsigned char*& data, int& size) const;
		
		private:
			int CellPositionInTileData(int u, int v, int w) const;

		private:
			int indexId_, level_, r_, s_, t_;
			gme_vector3i span_;
		};

		// ���񼯺ϡ������е�����Ԫ�Ĵ�С���ܲ�һ�£�����Ӳ�ͬ�㼶�õ�������ͬ����һ����Ƭ��
		// �����ڲ��ɰ�LOD�㼶����֯����
		class CellSet {
		};

		// �˲����������ݡ�
		class OG_GME_API OctIndex {
		public:
			OctIndex();
			OctIndex(gmeOctGeoField* model, const GString& fieldName);
			virtual ~OctIndex();

		public:
			bool IsValid() const;

			// ȡ����������ģ�͵�ID��
			GME_TYPE_OBJ_ID GetGridModeID() const;
			// ȡ����Ե������ֶε����֡�
			GString GetFieldName() const;

			// ������ID��
			GME_TYPE_OBJ_ID GetId() const;
			OctIndex& SetId(GME_TYPE_OBJ_ID id);

			// ��ȡ�˲����Ĳ㼶����
			// @return ���ذ˲����Ĳ�����N��İ˲����Ĳ㼶��ŴӸ��ڵ���Ҷ�ڵ�����Ϊ��0, ..., N-1���㼶���Խ������ϸ�̶�Խ�ߡ�
			int GetDepth() const;
			
			gme_vector3i GetTileSpan() const;
			OctIndex& SetTileSpan(const gme_vector3i& span);
			GString GetTileFormat() const;
			OctIndex& SetTileFormat(const GString& format);	// ��ʱ��֧��zipѹ����ʽ

			// ���ڵ�������Ԫ�Ĳ�����
			// ȡָ���㼶������Ԫ�Ĵ�С��
			// @param level	�Ǵ�0��ʼ�İ˲����㼶��š�
			// @return			��Ӧ�㼶����Ԫ�Ĵ�С��
			gme_vector3d GetCellSizeAtLevel(int level) const;
			// ȡָ���㼶������Ԫ��ŵķ�Χ��
			bool GetIJKBoxOfCellAtLevel(int level, gme_vector3i& minIJK, gme_vector3i& maxIJK) const;
			// ȡָ���㼶������Ԫ������ֵ��
			bool GetCellValueAtLevel(int level, int i, int j, int k, const gmeField& field, gmeFieldValue& value) const;
			// ����ָ���㼶������Ԫ������ֵ��markCellAsValidΪtrueʱ��ʾ������ֵ�ɹ�ʱͬʱ���ö�Ӧ����Ϊ��Ч����������²��ı��������Ч�ԡ�
			bool SetCellValueAtLevel(int level, int i, int j, int k, const gmeField& field, const gmeFieldValue& value, bool markCellAsValid) const;
			// ���ָ������Ԫ�Ƿ���Ч��
			bool IsCellValidAtLevel(int level, int i, int j, int k) const;
			bool SetCellValidationAtLevel(int level, int i, int j, int k, bool isValid) const;
			// ���ָ������Ԫ�Ƿ��޸��ˡ�
			bool IsCellModifiedAtLevel(int level, int i, int j, int k) const;
			bool SetCellModificationAtLevel(int level, int i, int j, int k, bool isModified) const;
			// �������Ԫ����������ڵ�ǰ���������Ƿ���ͬ�ʵġ�
			bool IsSubCellHomogeneous(int level, int i, int j, int k) const;

			// ���ڷֿ�Ĳ�������������ȡ���е�����Ԫ���ݡ�
			// ȡ�����ֿ�Ĵ�С��
			gme_vector3d GetTileSizeAtLevel(int level) const;
			// �Էֿ�(tile)Ϊ��λ��ȡָ���㼶�зֿ�ı�ŵķ�Χ��
			bool GetIJKBoxOfTileAtLevel(int level, gme_vector3i& minIJK, gme_vector3i& maxIJK) const;
			// ȡָ���ķ�Ƭ�������߸�������ص�ָ����ָ��Ķ���ָ���ķ�Ƭ��Чʱ���ؿ�ָ�롣
			Tile* GetTile(int level, int tileI, int tileJ, int tileK) const;

			// ����/���ع�������
			void Update();

		public:
			static int ComputeDepth(int max, int min, int span);

			// �����������ڵ�Tile��
			gme_vector3i CellIndexToTileIndex(const gme_vector3i& cellIJK) const;

		private:
			// ����������Tile�ڲ�������λ�á�
			gme_vector3i CellIndexInTile(const gme_vector3i& cellIJK) const;
			// ����������Tile���������е�λ�á�
			int CellPositionInTileData(const gme_vector3i& cellIndexInTile) const;
			gmeFieldValue::gmeType CheckAttributeDataType(const GString& fieldName) const;
			// ��������鲢���㸸���������ֵ���������������븸�����Ƿ�һ�µı��(����true��ʾһ�£������ʾ��һ��)��
			// �����������ԣ��Լ��ϵ�ƽ��ֵΪ�鲢�����
			// ����ɢ�����ԣ��Լ�����ռ������ֵΪ�鲢�����
			bool ReduceValueFromSubCells(const std::vector<gmeFieldValue>& values, const gmeField& field, gmeFieldValue& value) const;

		private:
			GME_TYPE_OBJ_ID indexId_;
			GString fieldName_;
			gme_vector3i tileSpan_;
			GString tileFormat_;
			gmeOctGeoField* model_;
		};


	public:
		//���Գ���ɫ��Ϣ luohh add 2021.11.15
		typedef enum GME_COLOR_TYPE {
			GME_CL_DISCRETE = 0,//��ɢȡ�����ɫ
			GME_CL_CONTINUE = 1,//����ȡ��ֵ��ɫ
		}GME_COLOR_TYPE;

		typedef struct Gme_FieldColor //ɫ������
		{
			GME_COLOR_TYPE fieldColorType;
			vector<std::pair<double, gme_color4>> vFieldColors;
			Gme_FieldColor(){
				fieldColorType = GME_COLOR_TYPE::GME_CL_CONTINUE;
			}
		}Gme_FieldColor;

		// ��������ģ�͡�
		// @param name		ģ�͵����֡�
		// @param localAxis	�ֲ�����ϵ��Ϣ��
		// @param minPt		����ģ���ھֲ�����ϵ����С������ε����½ǵ����ꡣ
		// @param maxPt		����ģ���ھֲ�����ϵ����С������ε����Ͻǵ����ꡣ
		// @param cellSize	�ֲ�����ϵ������Ԫ�Ĵ�С��
		// @param schema	�����������������ֶεĶ��塣
		// @return			����������������ģ�Ͷ���
		static gmeOctGeoField* Create(const GString& name, const gmeLocalAxis& localAxis, const gme_vector3d& minPt, const gme_vector3d& maxPt, const gme_vector3d& cellSize, const gmeFields& schema);
		// ��ȡ��Ч������ģ�͵�ID�б�
		// @param excludeDeleting �Ƿ��ų����ڱ�ɾ��״̬��ģ�͡�
		static std::vector<GME_TYPE_OBJ_ID> ListOctGeoFieldIds(bool excludeDeleting = true);

		// ȱʡ�İ˲��������ֶε����֡�ʵ��Ϊ�գ���ʾ������ض������ֶΡ�
		static GString DefaultOctIndexField();

	public:
		gmeOctGeoField();
		gmeOctGeoField(const GString& name, const gmeLocalAxis& localAxis, const gme_vector3d& cellSize, const gme_vector3i& minIJK, const gme_vector3i& maxIJK, const gmeFields& schema);
		virtual ~gmeOctGeoField();

	public:
		// ���ظ��ඨ��ķ�����
		virtual long Clone(gmeOctGeoField& obj);//��������
		virtual long Clear();//���
		virtual long Load(GME_TYPE_OBJ_ID objID, long lodLevel = 0);//�����ݿ����¼���
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel = 0);//���� // ��ӵڶ��������޸� -- LH.2021.11.05 17:10 added.
		virtual long CompressSave();//ѹ���洢
		virtual long Delete();
		virtual long UndoDelete();

		// ����ģ�͵�Ԫ������Ϣ��
		const gmeLocalAxis& GetLocalAxix() const;
		gmeOctGeoField& SetLocalAxis(const gmeLocalAxis& localAxis);
		// ȡ�ֲ�����ϵ�µ�AABB��
		void GetAABB(gme_vector3d& minPt, gme_vector3d& maxPt) const;
		const gme_vector3d& GetCellSize() const;
		gmeOctGeoField& SetCellSize(const gme_vector3d& size);
		void GetIJKBox(gme_vector3i& minIJK, gme_vector3i& maxIJK) const;
		gmeOctGeoField& SetIJKBox(const gme_vector3i& minIJK, const gme_vector3i& maxIJK);
		const gmeFields& GetSchema() const;
		gmeOctGeoField& SetSchema(const gmeFields& schema);	// �����ڴ����������ֶζ��壬�����ı�洢�����м�¼��ֵ��

		// �����ϸ�㣨����ײ㣩����Ԫ�Ĳ�����
		// ����/��ȡ����Ԫ��ָ���ֶ��ϵ�ȡֵ��markCellAsValidΪtrueʱ��ʾͬʱ���ö�Ӧ����Ϊ��Ч�����򲻸ı��������Ч�ԡ�
		void SetCellValue(int i, int j, int k, const gmeField& field, const gmeFieldValue& value, bool markCellAsValid = true);
		gmeFieldValue GetCellValue(int i, int j, int k, const gmeField& field) const;
		// ������������Ԫ��ָ���ֶ��ϵ�ȡֵ��
		// ����fieldָ����Ҫ������ֵ�������ֶε����֡�ֵ���������͡�
		// ����data��һ����ά���顣�����ʵ��Ԫ�ص�������field��¼��ֵ������һ�£�������Ԫ����Ŀ���� dimK * dimJ * dimI��Ԫ�صĴ洢˳����I���ȡ�J��֮��K���
		// ָ��data����ǿ��ת��Ϊfieldָ����ֵ���͵�ָ�롣
		// lowCellIJK����ָ��data�����е�һ��Ԫ�ض�Ӧ�������λ�ã�����������λ��Ԫ�ص�(I, J, K)��ž����ڸ�λ�á�
		// markCellAsValidΪtrueʱ���÷�����ͬʱ���ñ���ֵ������Ϊ��Ч���񣬷����޸��������Ч�ԡ�
		void SetCellsValue(const void* data, const gme_vector3i& lowCellIJK, int dimI, int dimJ, int dimK, const gmeField& field, bool markCellAsValid = true);
		void SetCellsValue(gmeFieldValues& values, const gme_vector3i& lowCellIJK, int dimI, int dimJ, int dimK, const gmeField& field, bool markCellAsValid = true);
		bool GetCellsValue(const gme_vector3i& lowCellIJK, int dimI, int dimJ, int dimK, const gmeField& field, gmeFieldValues& values);
		// ����/�������Ԫ�Ƿ���Ч��
		void SetCellValidation(int i, int j, int k, bool isValid);
		bool IsCellValid(int i, int j, int k) const;

		// ģ�Ͷ�Ӧ�İ˲����������ݡ�
		// ��ȡ��ǰ���е���������Ϣ��
		const std::vector<OctIndex>& ListOctIndices() const;
		// ���ָ�������ֶδ����˲���������
		// @param fieldName	�����ֶε����֡�
		// @return				�����Ƿ�ɹ���
		bool CreateOctIndex(const GString& fieldName);
		// ȡ����ض������ֶεİ˲���������
		// @param fieldName	�����ֶε����֡���Ϊ�գ���ʾȡȱʡ��ͨ�ð˲���������
		// @return				���ض�Ӧ�İ˲����������󡣷��ؿ�ָ��ʱ��ʾû�й����ض��ֶε������������߲���ɾ�����ص�ָ����ָ��Ķ���
		const OctIndex* GetOctIndex(const GString& fieldName) const;
		// ɾ��ָ���İ˲���������
		bool DeleteOctIndex(const GString& fieldName);
		// Ϊ�ڴ������������Ԫ���ݡ�
		gmeOctGeoField& SetOctIndices(const std::vector<OctIndex>& octIndices);

		// ���»��ؽ��˲���������
		void UpdateIndices();

		// ȡ���ŵķ�Ƭ��С��
		gme_vector3i GetOptTileSpan() const;


		//���Գ���ɫ��Ϣ luohh add 2021.11.15
		long SetColorMap(Gme_FieldColor fieldColor);
		long GetColorMap(Gme_FieldColor &fieldColor);

		protected:
			virtual long CalBox();//��GetBox����,�����Χ��
	private:
		Gme_FieldColor mColorMap;

		gmeLocalAxis localAxis_;
		gme_vector3d cellSize_;
		gme_vector3i minIJK_, maxIJK_;
		gmeFields schema_;
		std::vector<OctIndex> octIndices_;
	};
}
