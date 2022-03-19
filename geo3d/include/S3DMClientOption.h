#include <string>
#include "s3dqtapp_global.h"

namespace Smart3dMap {

	/// @brief S3DM�ͻ�������
	class S3DQTAPP_EXPORT S3DMClientOption {
	public:
		/// @brief �������ص�URL����ʽΪ����grpc(s)://<IP>:<Port>�������ߡ�grpc(s)://<����>:<Port>����
		static void SetGatewayURL(const std::string& url);
		/// @brief ���ÿ�������Կ��������Կ��accessKey����˽Կ��secretKey����������Կʱ������Ϊ���ַ�����
		static void SetDeveloperKey(const std::string& accessKey, const std::string& secretKey);

		/// @brief ȡ���ص�URL�����صĸ�ʽΪ����grpc(s)://<IP>:<Port>�����ߡ�grpc(s)://<����>:<port>����
		static std::string GetGatewayURL();
		/// @brief ȡ��������Կ�ԡ�
		static void GetDeveloperKey(std::string& accessKey, std::string& secretKey);

	private:
		S3DMClientOption();
	};
}