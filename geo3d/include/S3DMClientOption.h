#include <string>
#include "s3dqtapp_global.h"

namespace Smart3dMap {

	/// @brief S3DM客户端配置
	class S3DQTAPP_EXPORT S3DMClientOption {
	public:
		/// @brief 设置网关的URL。格式为：“grpc(s)://<IP>:<Port>”，或者“grpc(s)://<域名>:<Port>”。
		static void SetGatewayURL(const std::string& url);
		/// @brief 设置开发者密钥，包括公钥（accessKey）和私钥（secretKey）。无需密钥时请设置为空字符串。
		static void SetDeveloperKey(const std::string& accessKey, const std::string& secretKey);

		/// @brief 取网关的URL。返回的格式为：“grpc(s)://<IP>:<Port>”或者“grpc(s)://<域名>:<port>”。
		static std::string GetGatewayURL();
		/// @brief 取开发者密钥对。
		static void GetDeveloperKey(std::string& accessKey, std::string& secretKey);

	private:
		S3DMClientOption();
	};
}