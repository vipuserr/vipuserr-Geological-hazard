#pragma once

#ifndef LIBS3DMGRPC_API
	#pragma comment(lib, "libS3DMApiGRPC.lib")
	#define LIBS3DMGRPC_API __declspec(dllimport)
#endif

#include <grpcpp/channel.h>
#include <common/pagination.pb.h>
#include <data_engine/data_engine.grpc.pb.h>
#include <sessions/sessions.grpc.pb.h>
#include <user_manager/user_manager.grpc.pb.h>
#include <map_service/map_service.grpc.pb.h>
#include <model_exporter/model_exporter.grpc.pb.h>

namespace smart3dmap {

	class LIBS3DMGRPC_API RequestContext {
	public:
		RequestContext();
		virtual ~RequestContext();

		/// @brief 取包含的 grpc::Context 对象。
		grpc::ClientContext* GetPtr() const;

	private:
		grpc::ClientContext* ctxClient_;
	};

    class LIBS3DMGRPC_API Client {
    public:
        /// @brief 初始化客户端。
        /// @param serverURL 服务器地址，格式为："grpc://192.168.1.123:3000"或"grpcs://192.168.1.123:3000"。
        /// @param accessKey 用于标识开发者身份的Access Key。没有分配时可为空。
        /// @param secretKey 用于标识开发者身份的Secret Key。没有分配时可为空。
        static void Init(const char* serverURL, const char* accessKey = nullptr, const char* secretKey = nullptr);

        /// @brief 创建支持客户端服务器通信的grpc::Channel对象。
        /// @return 对应的grpc::Channel对象。该返回的对象可被缓存使用。
        static std::shared_ptr<grpc::ChannelInterface> CreateChannel();

        /// @brief 设置当前登录用户的会话标识符。该方法是线程安全的。
        /// @param token 会话的标识符。为空字符串则标识清除已设置的值。
        static void SetUserSessionToken(const char* token);

		/// @brief 创建客户端 grpc::ClientContext。
		static std::unique_ptr<RequestContext> NewContext();

		static std::unique_ptr<v1::DataEngine::StubInterface> NewDataEngineStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::SessionsManager::StubInterface> NewSessionsManagerStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::UserManager::StubInterface> NewUserManagerStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::MapService::StubInterface> NewMapServiceStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::ModelExport::StubInterface> NewModelExporterStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    };
}
